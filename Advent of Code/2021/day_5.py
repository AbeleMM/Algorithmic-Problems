import re


def read_in():
    data = []
    size = 0
    while value := re.findall(r'\d+', input()):
        arr = list(map(int, value))
        data.append(arr)
        size = max(size, max(arr))
    return size, data


def solve(data, flag):
    mat = [[0 for _ in range(data[0] + 1)] for _ in range(data[0] + 1)]
    for arr in data[1]:
        if arr[0] == arr[2]:
            mn = min(arr[1], arr[3])
            mx = max(arr[1], arr[3])
            for i in range(mn, mx + 1):
                mat[i][arr[0]] += 1
        elif arr[1] == arr[3]:
            mn = min(arr[0], arr[2])
            mx = max(arr[0], arr[2])
            for j in range(mn, mx + 1):
                mat[arr[1]][j] += 1
        elif flag:
            dist = abs(arr[0] - arr[2])
            sign_i = pow(-1, arr[1] > arr[3])
            sign_j = pow(-1, arr[0] > arr[2])
            for inc in range(dist + 1):
                mat[arr[1] + sign_i * inc][arr[0] + sign_j * inc] += 1
    res = 0
    for row in mat:
        for e in row:
            res += e > 1
    return res


def part_one(data):
    print(solve(data, False))


def part_two(data):
    print(solve(data, True))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
