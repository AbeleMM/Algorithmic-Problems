def read_in():
    def mapping(x):
        return '0' if x == '.' else '1'

    def read_row(s):
        r = ['0', '0', '0']
        r.extend((map(mapping, s)))
        r.extend(r[:3])
        return r

    algorithm = list(map(mapping, input()))
    input()
    row = read_row(input())
    image = [['0' for _ in range(len(row))] for _ in range(3)]
    image.append(row)
    while value := input():
        row = read_row(value)
        image.append(row)
    image.extend(image[:3])
    return algorithm, image


def get_algo_ind(img, i, j):
    s = []
    for alt_i in [i - 1, i, i + 1]:
        for alt_j in [j - 1, j, j + 1]:
            s.append(img[alt_i][alt_j])
    return int(''.join(s), 2)


def get_count_enhanced(algo, init_img, count):
    img = init_img
    for _ in range(count):
        fill_char = algo[int(img[0][0] * 9, 2)]
        new_img = [[fill_char for _ in range(len(img[0]) + 2)] for _ in range(len(img) + 2)]
        for i in range(2, len(img) - 2):
            for j in range(2, len(img[i]) - 2):
                new_img[i + 1][j + 1] = algo[get_algo_ind(img, i, j)]
        img = new_img

    res = 0
    for row in img[3:-3]:
        for e in row[3:-3]:
            res += e == '1'
    return res


def part_one(data):
    print(get_count_enhanced(data[0], data[1], 2))


def part_two(data):
    print(get_count_enhanced(data[0], data[1], 50))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
