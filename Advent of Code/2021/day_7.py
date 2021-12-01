def read_in():
    return list(map(int, input().split(',')))


def part_one(data):
    res = float('inf')
    for p in range(min(data), max(data) + 1):
        fuel = 0
        for e in data:
            fuel += abs(e - p)
        if fuel < res:
            res = fuel
    print(res)


def part_two(data):
    res = float('inf')
    for p in range(min(data), max(data) + 1):
        fuel = 0
        for e in data:
            nr = abs(e - p)
            fuel += nr * (nr + 1) / 2
        if fuel < res:
            res = fuel
    print(int(res))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
