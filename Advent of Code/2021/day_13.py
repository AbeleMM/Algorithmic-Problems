def read_in():
    dots = []
    folds = []
    i_max = j_max = 0
    while value := input():
        aux = list(map(int, value.split(',')))
        i_max = max(i_max, aux[1])
        j_max = max(j_max, aux[0])
        dots.append((aux[1], aux[0]))
    paper = [[False for _ in range(j_max + 1)] for _ in range(i_max + 1)]
    for x, y in dots:
        paper[x][y] = True
    while value := input().split():
        aux = value[2].split('=')
        folds.append((aux[0], int(aux[1])))
    return paper, folds


def transpose(mat):
    return [[mat[j][i] for j in range(len(mat))] for i in range(len(mat[0]))]


def fold_one(paper, axis, ind):
    p = paper if axis == 'y' else transpose(paper)
    upr = [row.copy() for row in p[:ind]]
    lwr = [row.copy() for row in p[ind + 1:]]
    for i in range(len(lwr)):
        for j in range(len(lwr[i])):
            upr[len(upr) - 1 - i][j] |= lwr[i][j]
    return upr if axis == 'y' else transpose(upr)


def part_one(data):
    res = 0
    new_paper = fold_one(data[0], data[1][0][0], data[1][0][1])
    for row in new_paper:
        for e in row:
            res += e
    print(res)


def part_two(data):
    new_paper = data[0]
    for fold in data[1]:
        new_paper = fold_one(new_paper, fold[0], fold[1])
    for row in new_paper:
        print(''.join(map(lambda x: '#' if x else '.', row)))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
