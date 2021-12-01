from collections import defaultdict


def read_in():
    data = []
    while input():
        scanner = []
        while value := input():
            split_val = value.split(',')
            scanner.append(tuple(map(int, split_val)))
        data.append(scanner)
    return data


def apply_rotation(mat, p):
    return mat[0][0] * p[0] + mat[0][1] * p[1] + mat[0][2] * p[2],\
           mat[1][0] * p[0] + mat[1][1] * p[1] + mat[1][2] * p[2],\
           mat[2][0] * p[0] + mat[2][1] * p[1] + mat[2][2] * p[2]


def get_rotation_mats():
    sin_cos_values = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    mats = set()
    for sin_x, cos_x in sin_cos_values:
        for sin_y, cos_y in sin_cos_values:
            for sin_z, cos_z in sin_cos_values:
                mat = ((cos_y * cos_z, -cos_y * sin_z, sin_y),
                       (sin_x * sin_y * cos_z + cos_x * sin_z,
                        cos_x * cos_z - sin_x * sin_y * sin_z,
                        sin_x * -cos_y),
                       (sin_x * sin_z - cos_x * sin_y * cos_z,
                        cos_x * sin_y * sin_z + sin_x * cos_z,
                        cos_x * cos_y))
                mats.add(mat)
    return mats


def solve_positions(data):
    scanners = {(0, 0, 0)}
    beacons = set(data[0])
    remaining = list(range(1, len(data)))
    while remaining:
        for i in remaining:
            for r_mat in rotation_mats:
                translate_count = defaultdict(int)
                max_key = None
                for beacon_i in data[i]:
                    r_beacon_i = apply_rotation(r_mat, beacon_i)
                    for beacon in beacons:
                        key = (beacon[0] - r_beacon_i[0],
                               beacon[1] - r_beacon_i[1],
                               beacon[2] - r_beacon_i[2])
                        if translate_count[key] == 11:
                            max_key = key
                            break
                        else:
                            translate_count[key] += 1
                    if max_key:
                        break
                if max_key:
                    scanners.add(max_key)
                    for beacon_i in data[i]:
                        r_beacon_i = apply_rotation(r_mat, beacon_i)
                        beacons.add((r_beacon_i[0] + max_key[0],
                                     r_beacon_i[1] + max_key[1],
                                     r_beacon_i[2] + max_key[2]))
                    remaining.remove(i)
                    break
    return scanners, beacons


def part_one(beacons):
    print(len(beacons))


def part_two(scanners):
    max_dist = 0
    for u in scanners:
        for v in scanners:
            max_dist = max(max_dist, abs(u[0] - v[0]) + abs(u[1] - v[1]) + abs(u[2] - v[2]))
    print(max_dist)


rotation_mats = get_rotation_mats()

if __name__ == '__main__':
    d = read_in()
    s, b = solve_positions(d)
    part_one(b)
    print()
    part_two(s)
