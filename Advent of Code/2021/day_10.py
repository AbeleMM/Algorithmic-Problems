def read_in():
    data = []
    while value := input():
        data.append(value)
    return data


def solve_line_illegal(line):
    opening_chars = ('(', '[', '{', '<')
    closing_chars = (')', ']', '}', '>')
    stack = []
    for s in line:
        if s in opening_chars:
            stack.append(s)
        else:
            opener = stack.pop()
            if opening_chars[closing_chars.index(s)] != opener:
                return s
    return stack


def part_one(data):
    point_map = {')': 3, ']': 57, '}': 1197, '>': 25137}
    res = 0
    for line in data:
        ret = solve_line_illegal(line)
        if type(ret) is str:
            res += point_map[ret]
    print(res)


def solve_line_autocomplete(line):
    res = 0
    point_map = {'(': 1, '[': 2, '{': 3, '<': 4}
    while line:
        s = line.pop()
        res *= 5
        res += point_map[s]
    return res


def part_two(data):
    scores = []
    for line in data:
        ret = solve_line_illegal(line)
        if type(ret) is list:
            scores.append(solve_line_autocomplete(ret))
    scores.sort()
    print(scores[int(len(scores) / 2)])


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
