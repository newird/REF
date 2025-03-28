#!/usr/bin/fish

if test -d ref_result
    rm -r ref_result
    mkdir ref_result
end
for file in cluster/*
    if test -f $file
        set incorrect (head -n 1 $file)
        set correct (tail -n +2 $file | head -n 1)
        set base (basename $incorrect .c)
        echo align $incorrect $correct
        python align.py $incorrect $correct >>ref_result/$base
    end
end
