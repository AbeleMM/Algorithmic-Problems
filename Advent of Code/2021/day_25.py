def read_in():
    data = []
    while value := input():
        data.append([s for s in value])
    return data


def part_one(data):
    seafloor = data
    changed = True
    nr_steps = 0
    while changed:
        seafloor_e = [[x if x != '>' else '.' for x in row] for row in seafloor]
        for i in range(len(seafloor)):
            for j in range(len(seafloor[0])):
                if seafloor[i][j] == '>':
                    next_j = j + 1 if j != len(seafloor[0]) - 1 else 0
                    if seafloor[i][next_j] == '.':
                        seafloor_e[i][next_j] = '>'
                    else:
                        seafloor_e[i][j] = '>'
        seafloor_s = [[x if x != 'v' else '.' for x in row] for row in seafloor_e]
        for i in range(len(seafloor)):
            for j in range(len(seafloor[0])):
                if seafloor_e[i][j] == 'v':
                    next_i = i + 1 if i != len(seafloor) - 1 else 0
                    if seafloor_e[next_i][j] == '.':
                        seafloor_s[next_i][j] = 'v'
                    else:
                        seafloor_s[i][j] = 'v'
        changed = seafloor_s != seafloor
        seafloor = seafloor_s
        nr_steps += 1
    print(nr_steps)


def part_two(data):
    pass


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
