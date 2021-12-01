import re


def read_in():
    return list(map(int, re.findall(r'-?\d+', input())))


def part_one(data):
    max_height = int((data[2] - 1) * data[2] / 2)
    print(max_height)


def part_two(data):
    res = 0
    x_min = 1
    while x_min * (x_min + 1) / 2 < data[0]:
        x_min += 1
    for x in range(x_min, data[1] + 1):
        for y in range(data[2], -data[2]):
            if data[0] <= x <= data[1] and data[2] <= y <= data[3]:
                res += 1
                continue
            curr_x, curr_y = x, y
            step_x, step_y = x - 1, y - 1
            while curr_x <= data[1] and curr_y >= data[2]:
                curr_x += step_x
                curr_y += step_y
                if step_x != 0:
                    step_x -= 1
                step_y -= 1
                if data[0] <= curr_x <= data[1] and data[2] <= curr_y <= data[3]:
                    res += 1
                    break
    print(res)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
