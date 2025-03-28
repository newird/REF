import gdb
import re
import os


# Check if the current frame is a library function
def is_library_frame(frame):
    sal = frame.find_sal()
    print(sal.symtab)
    return sal.symtab is None or "std" in (frame.name() or "")


# Parse GDB output into a dictionary
def parse_gdb_output_to_dict(output):
    variables = {}
    for line in output.splitlines():
        if line.strip() and "No arguments." not in line:
            match = re.match(r"(\w+) = (.+)", line)
            if match:
                variables[match.group(1)] = match.group(2)
    return variables


# Write the dictionary to a file, filename based on the C++ source name
def write_dict_to_file(src_file_name, var_dict, line_number, src_line):
    base_name = os.path.basename(src_file_name)  # Extract base name of the file
    debug_file_name = (
        os.path.splitext(base_name)[0] + ".txt"
    )  # Construct debug file name
    output_dict = {"line": line_number, "src": src_line, "storage": var_dict}
    with open(debug_file_name, "a") as file:
        file.write(str(output_dict) + "\n")


# Get current line number and source code line
def get_current_line_info():
    frame = gdb.selected_frame()
    sal = frame.find_sal()
    if sal.symtab:
        filename = sal.symtab.fullname()
        line_number = sal.line
        with open(filename, "r") as file:
            lines = file.readlines()
            src_line = lines[line_number - 1].strip()
            return filename, str(line_number), src_line
    return None, None, None


def on_stop(event):
    try:
        frame = gdb.selected_frame()
        frame_name = frame.name()

        if frame_name and (
            "std::" in frame_name or "_IO_" in frame_name or frame_name.startswith("__")
        ):
            gdb.execute("finish")
            return

        sal = frame.find_sal()
        if sal.symtab:
            filename = sal.symtab.fullname()
            if "/usr/include/" in filename or "/usr/lib/" in filename:
                print("finish")
                gdb.execute("finish")
                return

        filename, line_number, src_line = get_current_line_info()
        locals_output = gdb.execute("info locals", to_string=True, from_tty=False)
        args_output = gdb.execute("info args", to_string=True, from_tty=False)
        var_dict = parse_gdb_output_to_dict(locals_output + args_output)
        write_dict_to_file(filename, var_dict, line_number, src_line)

        gdb.execute("step")

    except Exception as e:
        print(f"on_stop 发生错误: {e}")
        gdb.execute("quit")


# Set breakpoint and start debugging with input redirection
def start_debugging():
    gdb.execute("set confirm off")
    gdb.execute("break main")
    gdb.execute("run < input.txt")


# Automatically quit GDB when the debugged program exits
def quit_gdb(event):
    gdb.execute("quit")


gdb.events.exited.connect(quit_gdb)  # Register exit event handler
gdb.events.stop.connect(on_stop)  # Register stop event handler

start_debugging()
