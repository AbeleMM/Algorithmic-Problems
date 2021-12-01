def read_in():
    data = []
    while value := input():
        data.append([int(x) for x in value])
    return data


def get_low_points(data):
    low_points = []
    for i in range(len(data)):
        for j in range(len(data[i])):
            if i > 0 and data[i - 1][j] <= data[i][j]:
                continue
            if i < len(data) - 1 and data[i + 1][j] <= data[i][j]:
                continue
            if j > 0 and data[i][j - 1] <= data[i][j]:
                continue
            if j < len(data[i]) - 1 and data[i][j + 1] <= data[i][j]:
                continue
            low_points.append((i, j))
    return low_points


def part_one(data):
    res = 0
    for lp in get_low_points(data):
        res += data[lp[0]][lp[1]] + 1
    print(res)


def get_basin_size(data, lp):
    res = 0
    fill_mat = [[False for _ in data[0]] for _ in data]
    fill_stack = [lp]
    while fill_stack:
        i, j = fill_stack.pop()
        if fill_mat[i][j]:
            continue
        fill_mat[i][j] = True
        if i > 0 and data[i - 1][j] != 9:
            fill_stack.append((i - 1, j))
        if i < len(data) - 1 and data[i + 1][j] != 9:
            fill_stack.append((i + 1, j))
        if j > 0 and data[i][j - 1] != 9:
            fill_stack.append((i, j - 1))
        if j < len(data[i]) - 1 and data[i][j + 1] != 9:
            fill_stack.append((i, j + 1))
    for row in fill_mat:
        for e in row:
            res += e
    return res


def part_two(data):
    res = 1
    basin_sizes = [get_basin_size(data, x) for x in get_low_points(data)]
    basin_sizes.sort(reverse=True)
    for e in basin_sizes[:3]:
        res *= e
    print(res)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
