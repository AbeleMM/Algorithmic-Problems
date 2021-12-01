from functools import cache
from itertools import cycle


def read_in():
    p1, p2 = int(input().split()[-1]), int(input().split()[-1])
    return p1, p2


def part_one(data):
    pos_p1, pos_p2 = data[0], data[1]
    score_p1, score_p2 = 0, 0
    nr_rolls = 0
    dice_roll = cycle(range(1, 101))
    while score_p1 < 1000 and score_p2 < 1000:
        v = next(dice_roll) + next(dice_roll) + next(dice_roll)
        if nr_rolls % 2 == 0:
            pos_p1 = (pos_p1 + v) % 10
            if not pos_p1:
                pos_p1 = 10
            score_p1 += pos_p1
        else:
            pos_p2 = (pos_p2 + v) % 10
            if not pos_p2:
                pos_p2 = 10
            score_p2 += pos_p2
        nr_rolls += 3
    print(min(score_p1, score_p2) * nr_rolls)


dirac_die_outcomes = {3: 1, 4: 3, 5: 6, 6: 7, 7: 6, 8: 3, 9: 1}


@cache
def solve_universe(pos, score=(0, 0), turn_p2=False):
    if score[0] > 20:
        return 1, 0
    if score[1] > 20:
        return 0, 1
    res = (0, 0)
    for v in dirac_die_outcomes:
        p = list(pos)
        s = list(score)
        p[turn_p2] += v
        p[turn_p2] %= 10
        if not p[turn_p2]:
            p[turn_p2] = 10
        s[turn_p2] += p[turn_p2]
        inner_res = solve_universe(tuple(p), tuple(s), not turn_p2)
        res = (res[0] + inner_res[0] * dirac_die_outcomes[v],
               res[1] + inner_res[1] * dirac_die_outcomes[v])
    return res


def part_two(data):
    print(max(solve_universe(data)))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
