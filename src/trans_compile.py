import re


def convert_cpp_to_c(filepath):
    with open(filepath, "r") as file:
        content = file.read()

    # Remove using namespace std;
    content = re.sub(r"using\s+namespace\s+std\s*;\s*", "", content)

    # Replace #include <iostream> with #include <stdio.h>
    content = re.sub(r"#include\s*<iostream>", "#include <stdio.h>", content)

    # Map variable types to scanf/printf formats
    type_format_map = {
        "int": "%d",
        "float": "%f",
        "double": "%lf",
        "char": "%c",
        "char\[\d+\]": "%s",  # Simplified for fixed-size char arrays
        "std::string": "%s",  # Needs special handling
    }

    # Extract variable declarations and their types
    variable_types = {}
    for var_type, fmt in type_format_map.items():
        pattern = r"\b{}\s+(\w+)\b".format(var_type)
        matches = re.findall(pattern, content)
        for match in matches:
            variable_types[match] = fmt

    # Replace cin with scanf
    def replace_cin(match):
        variables = match.group(1).strip().split(">>")
        formats = " ".join([variable_types.get(var.strip(), "%s") for var in variables])
        vars_with_amp = ", ".join(
            [
                "&" + var.strip()
                if variable_types.get(var.strip()) != "%s"
                else var.strip()
                for var in variables
            ]
        )
        return 'scanf("{}"'.format(formats) + ", " + vars_with_amp + ");"

    content = re.sub(r"cin\s*>>\s*(.*?);\s*", replace_cin, content)

    # Replace cout with printf
    def replace_cout(match):
        variables = match.group(1).strip().split("<<")
        formats = " ".join(
            [
                variable_types.get(var.strip(), "%s")
                if var.strip() in variable_types
                else "%s"
                for var in variables
            ]
        )
        vars_str = ", ".join([var.strip() for var in variables])
        return 'printf("{}"'.format(formats) + ", " + vars_str + ");"

    content = re.sub(r"cout\s*<<\s*(.*?);\s*", replace_cout, content)

    with open("converted_" + filepath, "w") as file:
        file.write(content)


# Example usage
convert_cpp_to_c("example.cpp")
