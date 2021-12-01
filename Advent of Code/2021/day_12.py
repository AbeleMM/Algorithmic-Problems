def read_in():
    data = {}
    while value := input():
        x, y = value.split('-')
        if x in data:
            data[x].append(y)
        else:
            data[x] = [y]
        if y in data:
            data[y].append(x)
        else:
            data[y] = [x]
    return data


def get_path_count(data, u, visited, double_dip):
    if u == 'end':
        return 1
    else:
        res = 0
        visited[u] += 1
        for v in data[u]:
            if double_dip and v != 'start' and v.islower() and visited[v] == 1:
                res += get_path_count(data, v, visited, False)
            elif (v.islower() and visited[v] == 0) or v.isupper():
                res += get_path_count(data, v, visited, double_dip)
        visited[u] -= 1
        return res


def part_one(data):
    visited = {x: 0 for x in data}
    print(get_path_count(data, 'start', visited, False))


def part_two(data):
    visited = {x: 0 for x in data}
    print(get_path_count(data, 'start', visited, True))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
