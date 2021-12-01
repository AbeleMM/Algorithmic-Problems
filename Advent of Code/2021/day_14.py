from collections import defaultdict


def read_in():
    polymer = input()
    input()
    rules = {}
    while value := input():
        k, v = value.split(' -> ')
        rules[k] = v
    return polymer, rules


def run_for_n_rounds(polymer, rules, n):
    p_map = defaultdict(int)
    e_count = defaultdict(int)
    for i in range(len(polymer) - 1):
        k = polymer[i] + polymer[i + 1]
        p_map[k] += 1
        e_count[polymer[i]] += 1
    e_count[polymer[-1]] += 1
    for _ in range(n):
        new_p_map = defaultdict(int)
        for k in p_map:
            v = p_map[k]
            new_k = k[0] + rules[k]
            new_p_map[new_k] += v
            new_k = rules[k] + k[1]
            new_p_map[new_k] += v
            e_count[rules[k]] += v
        p_map = new_p_map
    return max(e_count.values()) - min(e_count.values())


def part_one(data):
    print(run_for_n_rounds(data[0], data[1], 10))


def part_two(data):
    print(run_for_n_rounds(data[0], data[1], 40))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
