#!/usr/bin/fish

# Ensure the output directory exists
mkdir -p cluster

# Loop through directories 0 to 99
for i in (seq 0 99)
    set dir $i
    # Check if the directory exists
    if test -d $dir
        # Iterate over files in the directory
        for file in $dir/*
            set base (basename $file .cpp)

            # this first line is incorrect file path
            # the next ten lines are correct file path
            echo $file
            echo $file >cluster/$base
            # Ensure there is a corresponding file in the directory '100'
            if test -d 100
                # Process the file with cc.js and compare it with its counterpart in '100'
                node cc.js $file 100 >>cluster/$base
            end
        end
    end
end
