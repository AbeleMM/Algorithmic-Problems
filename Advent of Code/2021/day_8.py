def read_in():
    data = []
    while value := input().split():
        value.pop(10)
        data.append((value[:10], value[10:]))
    return data


def part_one(data):
    count = 0
    # 1 -> 2 segments; 4-> 4; 7 -> 3; 8-> 7
    nr_segments_simple_digits = [2, 4, 3, 7]
    for entry in data:
        for digitSegments in entry[1]:
            count += len(digitSegments) in nr_segments_simple_digits
    print(count)


def solve_single_entry(entry):
    output = 0
    chars_to_digit = {}
    char_set_4 = char_set_7 = frozenset()

    for digitSegments in entry[0]:
        nr_chars = len(digitSegments)
        char_set = frozenset(digitSegments)
        if nr_chars == 2:
            chars_to_digit[char_set] = 1
        elif nr_chars == 4:
            chars_to_digit[char_set] = 4
            char_set_4 = char_set
        elif nr_chars == 3:
            chars_to_digit[char_set] = 7
            char_set_7 = char_set
        elif nr_chars == 7:
            chars_to_digit[char_set] = 8

    for digitSegments in entry[0]:
        nr_chars = len(digitSegments)
        char_set = frozenset(digitSegments)
        if nr_chars == 5:
            if len(char_set.intersection(char_set_4)) == 2:
                chars_to_digit[char_set] = 2
            elif len(char_set.intersection(char_set_7)) == 3:
                chars_to_digit[char_set] = 3
            else:
                chars_to_digit[char_set] = 5
        elif nr_chars == 6:
            if len(char_set.intersection(char_set_7)) == 2:
                chars_to_digit[char_set] = 6
            elif len(char_set.intersection(char_set_4)) == 4:
                chars_to_digit[char_set] = 9
            else:
                chars_to_digit[char_set] = 0

    for pattern in entry[1]:
        output *= 10
        output += chars_to_digit[frozenset(pattern)]
    return output


def part_two(data):
    res = 0
    for entry in data:
        res += solve_single_entry(entry)
    print(res)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
