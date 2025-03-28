#!/usr/bin/env fish
set base_dir (pwd)

mkdir -p $base_dir/correct
mkdir -p $base_dir/incorrect

for dir in correctanswer wronganswer partiallycorrectanswer
    if test -d $dir
        for file in $dir/*.c
            set filename (basename $file .c)
            g++ $file -o $dir/$filename -g
            if string match -r correctanswer (basename $dir)
                mv $dir/$filename $base_dir/correct/$filename
            else
                mv $dir/$filename $base_dir/incorrect/$filename
            end
        end
    end
end
