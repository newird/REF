#!/usr/bin/env fish
# Define the base directory containing the subdirectories with CPP files
set base_dir (pwd)

# Create correct and incorrect directories if they don't exist
mkdir -p $base_dir/correct
mkdir -p $base_dir/incorrect

# Iterate over the subdirectories in the base directory
for dir in $base_dir/*
    if test -d $dir
        # Compile all CPP files in the subdirectory
        for file in $dir/*.cpp
            # Extract the filename without the extension for the output binary
            set filename (basename $file .cpp)

            # Compile the CPP file
            g++ $file -o $dir/$filename -g

            # Check if the directory name is 100 for correct answers
            if string match -r 100 (basename $dir)
                # Move the executable to the correct directory
                mv $dir/$filename $base_dir/correct/$filename
            else
                # Move the executable to the incorrect directory
                mv $dir/$filename $base_dir/incorrect/$filename
            end
        end
    end
end
