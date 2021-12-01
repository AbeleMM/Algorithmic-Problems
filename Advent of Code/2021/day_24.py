def read_in():
    data = []
    while value := input():
        data.append(value.split())
    return data


DIGIT_COUNT, CHECK_IND, OFFSET_IND = 14, 5, 15


def get_number(data, mx):
    """
    https://github.com/dphilipson/advent-of-code-2021/blob/master/src/days/day24.rs
    """
    nr = [9 if mx else 1] * DIGIT_COUNT
    chunk_size = len(data) // DIGIT_COUNT
    stack = []
    for i in range(DIGIT_COUNT):
        check = int(data[i * chunk_size + CHECK_IND][2])
        if check > 0:
            offset = int(data[i * chunk_size + OFFSET_IND][2])
            stack.append((i, offset))
        else:
            prev_i, prev_offset = stack.pop()
            diff = prev_offset + check
            if (mx and diff > 0) or (not mx and diff < 0):
                nr[prev_i] -= diff
            else:
                nr[i] += diff
    return ''.join(map(str, nr))


def part_one(data):
    print(get_number(data, True))


def part_two(data):
    print(get_number(data, False))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
