def read_in():
    data = []
    while value := input():
        level = 0
        res = []
        for s in value:
            if s == '[':
                level += 1
            elif s == ']':
                level -= 1
            elif s != ',':
                res.append((int(s), level))
        data.append(res)
    return data


def reduce(unfolded_nr):
    changed = True
    while changed:
        changed = False
        i_s = -1
        for i in range(len(unfolded_nr)):
            if i_s == -1 and unfolded_nr[i][0] > 9:
                i_s = i
            if unfolded_nr[i][1] == 5:
                if i == 0:
                    unfolded_nr[i] = (0, 4)
                    unfolded_nr[i + 2] = (unfolded_nr[i + 2][0] + unfolded_nr[i + 1][0],
                                          unfolded_nr[i + 2][1])
                    del unfolded_nr[i + 1]
                elif i == len(unfolded_nr) - 2:
                    unfolded_nr[i + 1] = (0, 4)
                    unfolded_nr[i - 1] = (unfolded_nr[i - 1][0] + unfolded_nr[i][0],
                                          unfolded_nr[i - 1][1])
                    del unfolded_nr[i]
                else:
                    unfolded_nr[i - 1] = (unfolded_nr[i - 1][0] + unfolded_nr[i][0],
                                          unfolded_nr[i - 1][1])
                    unfolded_nr[i + 2] = (unfolded_nr[i + 2][0] + unfolded_nr[i + 1][0],
                                          unfolded_nr[i + 2][1])
                    unfolded_nr[i] = (0, 4)
                    del unfolded_nr[i + 1]
                changed = True
                break
        if i_s != -1:
            l_val = unfolded_nr[i_s][0] // 2
            unfolded_nr.insert(i_s + 1, (unfolded_nr[i_s][0] - l_val, unfolded_nr[i_s][1] + 1))
            unfolded_nr[i_s] = (l_val, unfolded_nr[i_s][1] + 1)
            changed = True


def fold(snail_fish_nr):
    curr_nr = snail_fish_nr
    for curr_lvl in range(4, 0, -1):
        next_nr = []
        skip_next = False
        for i in range(len(curr_nr)):
            if skip_next:
                skip_next = False
                continue
            if curr_nr[i][1] == curr_lvl:
                next_nr.append(([curr_nr[i][0], curr_nr[i + 1][0]], curr_lvl - 1))
                skip_next = True
            else:
                next_nr.append(curr_nr[i])
        curr_nr = next_nr
    return curr_nr[0][0]


def magnitude(folded_nr):
    if type(folded_nr) is int:
        return folded_nr
    return 3 * magnitude(folded_nr[0]) + 2 * magnitude(folded_nr[1])


def part_one(data):
    curr_nr = data[0]
    for i in range(1, len(data)):
        next_nr = list(map(lambda x: (x[0], x[1] + 1), curr_nr))
        next_nr.extend(map(lambda x: (x[0], x[1] + 1), data[i]))
        reduce(next_nr)
        curr_nr = next_nr
    print(magnitude(fold(curr_nr)))


def part_two(data):
    max_magnitude = -1
    for i in range(len(data)):
        for j in range(len(data)):
            if i != j:
                summed_nr = list(map(lambda x: (x[0], x[1] + 1), data[i]))
                summed_nr.extend(map(lambda x: (x[0], x[1] + 1), data[j]))
                reduce(summed_nr)
                max_magnitude = max(max_magnitude, magnitude(fold(summed_nr)))
    print(max_magnitude)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
