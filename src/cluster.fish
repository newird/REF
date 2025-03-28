#!/usr/bin/fish

# Ensure the output directory exists
mkdir -p cluster
mkdir -p condense_cluster

# Loop through directories 0 to 99
for i in wronganswer partiallycorrectanswer
    set dir $i
    if test -d $dir
        for file in $dir/*
            set base (basename $file .c)

            echo $file
            echo $file >cluster/$base
            if test -d correctanswer
                node cc.mjs $file correctanswer >>cluster/$base
            end
            echo $file >condense_cluster/$base
            if test -d condense
                node cc.mjs $file correctanswer >>condense_cluster/$base
            end
        end
    end
end
