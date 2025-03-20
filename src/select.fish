if not test -d condense
    mkdir condense
end

for file in (node select.js 100/ | string split "\n")
    set filename (basename $file) # or use basename $file
    if test -f "$file"
        mv "$file" condense/
    end
end
