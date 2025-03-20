#!/usr/bin/fish

# Ensure the output directory exists
mkdir -p cluster
mkdir -p condense_cluster

# Loop through directories 0 to 99
for i in (seq 0 99)
    set dir $i
    # Check if the directory exists
    if test -d $dir
        # Iterate over files in the directory
        for file in $dir/*
            set base (basename $file .cpp)

            echo $file
            echo $file >cluster/$base
            if test -d 100
                node cc.js $file 100 >>cluster/$base
            end
            echo $file >condense_cluster/$base
            if test -d condense
                node cc.js $file 100 >>condense_cluster/$base
            end
        end
    end
end
