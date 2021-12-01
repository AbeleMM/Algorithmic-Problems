def read_in():
    data = []
    while value := input():
        data.append(list(map(int, value)))
    return data


def get_stack(data):
    stack = []
    for i in range(len(data)):
        for j in range(len(data[i])):
            if data[i][j] == 9:
                stack.append((i, j))
            else:
                data[i][j] += 1
    return stack


def dfs(data, stack):
    res = 0
    visited = set()
    while stack:
        i, j = stack.pop()
        if (i, j) in visited:
            continue
        data[i][j] = 0
        res += 1
        visited.add((i, j))
        for alt_i in range(i - 1, i + 2):
            for alt_j in range(j - 1, j + 2):
                if 0 <= alt_i < len(data) and 0 <= alt_j < len(data[i]):
                    if data[alt_i][alt_j] == 9:
                        stack.append((alt_i, alt_j))
                    elif data[alt_i][alt_j] != 0:
                        data[alt_i][alt_j] += 1
    return res


def part_one(data):
    res = 0
    for _ in range(100):
        stack = get_stack(data)
        res += dfs(data, stack)
    print(res)


def part_two(data):
    ind = 1
    while True:
        stack = get_stack(data)
        if dfs(data, stack) == len(data) * len(data[0]):
            print(ind)
            break
        ind += 1


if __name__ == '__main__':
    d = read_in()
    part_one([row.copy() for row in d])
    print()
    part_two([row.copy() for row in d])
