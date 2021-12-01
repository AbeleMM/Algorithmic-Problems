import re


class Cuboid:
    def __init__(self, xmn, ymn, zmn, xmx, ymx, zmx):
        self.xmn, self.ymn, self.zmn, self.xmx, self.ymx, self.zmx = xmn, ymn, zmn, xmx, ymx, zmx
        self._hash = hash((self.xmn, self.ymn, self.zmn, self.xmx, self.ymx, self.zmx))

    def __eq__(self, other):
        return self.xmn == other.xmn and self.ymn == other.ymn and self.zmn == other.zmn and \
               self.xmx == other.xmx and self.ymx == other.ymx and self.zmx == other.zmx

    def __hash__(self):
        return self._hash


def read_in():
    data = []
    while value := re.findall(r'on|off|-?\d+', input()):
        cuboid = Cuboid(int(value[1]), int(value[3]), int(value[5]),
                        int(value[2]), int(value[4]), int(value[6]))
        data.append((value[0] == 'on', cuboid))
    return data


def part_one(data):
    def gen_2d_mat():
        return [[False for _ in range(-mx, mx + 1)] for _ in range(-mx, mx + 1)]

    mx, res = 50, 0
    mat = [gen_2d_mat() for _ in range(-mx, mx + 1)]
    for v, c in data:
        for i in range(max(-mx, c.xmn), min(mx, c.xmx) + 1):
            for j in range(max(-mx, c.ymn), min(mx, c.ymx) + 1):
                for k in range(max(-mx, c.zmn), min(mx, c.zmx) + 1):
                    mat[i + mx][j + mx][k + mx] = v
    for plane in mat:
        for row in plane:
            for v in row:
                res += v
    print(res)


def intersect(cuboid, other_cuboid):
    xmn, xmx = max(cuboid.xmn, other_cuboid.xmn), min(cuboid.xmx, other_cuboid.xmx)
    ymn, ymx = max(cuboid.ymn, other_cuboid.ymn), min(cuboid.ymx, other_cuboid.ymx)
    zmn, zmx = max(cuboid.zmn, other_cuboid.zmn), min(cuboid.zmx, other_cuboid.zmx)
    if xmn <= xmx and ymn <= ymx and zmn <= zmx:
        return Cuboid(xmn, ymn, zmn, xmx, ymx, zmx)
    return None


def get_splits(cuboid, overlap):
    splits = []
    if cuboid.xmn < overlap.xmn:
        splits.append(Cuboid(cuboid.xmn, cuboid.ymn, cuboid.zmn,
                             overlap.xmn - 1, cuboid.ymx, cuboid.zmx))
    if overlap.xmx < cuboid.xmx:
        splits.append(Cuboid(overlap.xmx + 1, cuboid.ymn, cuboid.zmn,
                             cuboid.xmx, cuboid.ymx, cuboid.zmx))
    if cuboid.ymn < overlap.ymn:
        splits.append(Cuboid(overlap.xmn, cuboid.ymn, cuboid.zmn,
                             overlap.xmx, overlap.ymn - 1, cuboid.zmx))
    if overlap.ymx < cuboid.ymx:
        splits.append(Cuboid(overlap.xmn, overlap.ymx + 1, cuboid.zmn,
                             overlap.xmx, cuboid.ymx, cuboid.zmx))
    if cuboid.zmn < overlap.zmn:
        splits.append(Cuboid(overlap.xmn, overlap.ymn, cuboid.zmn,
                             overlap.xmx, overlap.ymx, overlap.zmn - 1))
    if overlap.zmx < cuboid.zmx:
        splits.append(Cuboid(overlap.xmn, overlap.ymn, overlap.zmx + 1,
                             overlap.xmx, overlap.ymx, cuboid.zmx))
    return splits


def part_two(data):
    res = 0
    on_cuboids = []
    for v, curr_c in data:
        on_cuboids_new = []
        if v:
            to_add = True
            for on_c in on_cuboids:
                intersection = intersect(curr_c, on_c)
                if intersection is None:
                    on_cuboids_new.append(on_c)
                elif intersection == curr_c:
                    on_cuboids_new.append(on_c)
                    to_add = False
                else:
                    on_cuboids_new.extend(get_splits(on_c, intersection))
            if to_add:
                on_cuboids_new.append(curr_c)
        else:
            for on_c in on_cuboids:
                intersection = intersect(curr_c, on_c)
                if intersection is None:
                    on_cuboids_new.append(on_c)
                else:
                    on_cuboids_new.extend(get_splits(on_c, intersection))
        on_cuboids = on_cuboids_new
    for on_c in on_cuboids:
        res += (on_c.xmx - on_c.xmn + 1) * (on_c.ymx - on_c.ymn + 1) * (on_c.zmx - on_c.zmn + 1)
    print(res)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
