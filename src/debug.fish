# Define the base directory containing the correct and incorrect directories
set base_dir (pwd)

# Create correct_trace and incorrect_trace directories if they don't exist
mkdir -p $base_dir/correct_trace
mkdir -p $base_dir/incorrect_trace

# Function to process files in a given directory
function process_files
    set dir_name $argv[1] # correct or incorrect
    set target_dir $base_dir/{$dir_name}_trace # correct_trace or incorrect_trace

    # Iterate over the files in the directory
    for file in $base_dir/$dir_name/*
        # Make sure it's a file
        if test -f $file
            # Get the basename of the file
            set base (basename $file)

            echo $base
            # Run gdb with debug.py on the file
            gdb -q -x $base_dir/debug.py $file

            echo finish
            # Move the debug file to the appropriate trace directory
            mv $base_dir/debug_$base.txt $target_dir/debug_$base.txt

        end
    end
end

# Process files in both correct and incorrect directories
process_files correct
process_files incorrect
