def read_in():
    data = []
    while value := input().split():
        data.append((value[0], int(value[1])))
    return data


def part_one(data):
    horizontal = 0
    depth = 0
    for e in data:
        if e[0] == "forward":
            horizontal += e[1]
        elif e[0] == "down":
            depth += e[1]
        elif e[0] == "up":
            depth -= e[1]
    print(horizontal * depth)


def part_two(data):
    horizontal = depth = aim = 0
    for e in data:
        if e[0] == "forward":
            horizontal += e[1]
            depth += aim * e[1]
        elif e[0] == "down":
            aim += e[1]
        elif e[0] == "up":
            aim -= e[1]
    print(horizontal * depth)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
