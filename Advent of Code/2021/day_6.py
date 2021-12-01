def read_in():
    return list(map(int, input().split(',')))


def solve(data, days):
    arr = [0] * 9
    for e in data:
        arr[e] += 1
    for _ in range(days):
        new_arr = [0] * 9
        for i in range(8):
            new_arr[i] = arr[i + 1]
        new_arr[6] += arr[0]
        new_arr[8] = arr[0]
        arr = new_arr
    return sum(arr)


def part_one(data):
    print(solve(data, 80))


def part_two(data):
    print(solve(data, 256))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
