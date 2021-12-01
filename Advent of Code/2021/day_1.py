def read_in():
    data = []
    while value := input():
        data.append(int(value))
    return data


def part_one(data):
    res = 0
    for i in range(1, len(data)):
        res += data[i] > data[i - 1]
    print(res)


def part_two(data):
    res = 0
    s = data[0] + data[1] + data[2]
    for i in range(3, len(data)):
        new_s = s - data[i - 3] + data[i]
        res += new_s > s
        s = new_s
    print(res)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
