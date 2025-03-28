set base_dir (pwd)

mkdir -p $base_dir/trace

function process_files
    set dir_name $argv[1]
    set target_dir $base_dir/trace

    for file in $base_dir/$dir_name/*
        if test -f $file
            set base (basename $file)

            echo $base
            # Run gdb with debug.py on the file
            gdb -q -x $base_dir/gen_trace.py $file

            echo finish
            # Move the debug file to the appropriate trace directory
            mv $base_dir/$base.txt $target_dir/$base.txt

        end
    end
end

# Process files in both correct and incorrect directories
process_files correct
process_files incorrect

rm *.txt
