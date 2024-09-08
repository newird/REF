def load(file_path):

    line2src = {}
    storage2line = {}
    line2storage = {}

    with open(file_path, 'r') as file:
        for line in file:
            line_dict = eval(line)

            line_num = line_dict['line']
            src_code = line_dict['src']
            storage = line_dict['storage']

            line2src[line_num] = src_code

            if line_num in line2storage:
                line2storage[line_num].append(storage)
            else:
                line2storage[line_num] = [storage]
            storage2line[str(storage)] = line_num
    return line2src, line2storage, storage2line


def seq(file_path):

    seq = []
    with open(file_path, 'r') as file:
        for line in file:
            line_dict = eval(line)

            src_code = line_dict['src']
            storage = line_dict['storage']

            seq.append(str(storage))
    return seq


_, l2s, s2l = load("debug_144.txt")
#
for k, v in l2s.items():
    print(k, ":")
    for vv in v:
        print(vv)
#
for k, v in s2l.items():
    print(k, v)
