if not test -d condense
    mkdir condense
end

for file in (node select.mjs correctanswer/ | string split "\n")
    set filename (basename $file)
    if test -f "$file"
        mv "$file" condense/
    end
end
