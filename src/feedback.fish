#!/usr/bin/fish 


# Ensure the output directory exists
if test -d result
    rm -r result
    mkdir result
end
# Iterate over all files in the 'cluster' directory
for file in cluster/*
    # Check if the item is a file
    if test -f $file
        # Read the first line as 'incorrect'
        set incorrect (head -n 1 $file)

        # Read the next ten lines as 'correct' items
        set correct (tail -n +2 $file | head -n 10)
        set base (basename $incorrect .cpp)
        touch result/$base
        # Iterate through each 'correct' line
        for c in $correct
            # Use Python script 'diff.py' to compare 'incorrect' with each 'correct'
            python diff.py $incorrect $c >>result/$base
            echo -------------------- >>result/$base
        end
    end
end
