def read_in():
    data = []
    while value := input():
        data.append(value)
    return data


def part_one(data):
    count_zeros = [0] * len(data[0])
    for s in data:
        for i in range(len(s)):
            count_zeros[i] += s[i] == '0'
    gamma_str = ''.join('0' if x > len(data) - x else '1' for x in count_zeros)
    epsilon_str = ''.join('0' if x == '1' else '1' for x in gamma_str)
    print(int(gamma_str, 2) * int(epsilon_str, 2))


def filter_data(data_, flag):
    """
    Set flag = False for oxygen generator & flag = True for CO2 scrubber
    """
    data = data_.copy()
    ind = 0
    while len(data) > 1:
        count_zero = 0
        for s in data:
            count_zero += s[ind] == '0'
        ch = '0' if count_zero > len(data) - count_zero else '1'
        if flag:
            ch = '0' if ch == '1' else '1'
        data = list(filter(lambda x: x[ind] == ch, data))
        ind += 1
    return data[0]


def part_two(data):
    print(int(filter_data(data, False), 2) * int(filter_data(data, True), 2))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
