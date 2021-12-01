from math import prod


class Packet:
    def __init__(self, ver, length):
        self.ver = ver
        self.length = length

    def get_ver_sum(self):
        pass

    def get_val(self):
        pass


class LiteralPacket(Packet):
    def __init__(self, ver, val, length):
        super().__init__(ver, length)
        self.val = val

    def get_ver_sum(self):
        return self.ver

    def get_val(self):
        return self.val


class OperatorPacket(Packet):
    def __init__(self, typ, ver, children, length):
        super().__init__(ver, length)
        self.typ = typ
        self.children = children

    def get_ver_sum(self):
        return self.ver + sum(map(lambda x: x.get_ver_sum(), self.children))

    def get_val(self):
        children_values = map(lambda x: x.get_val(), self.children)
        if self.typ == 0:
            return sum(children_values)
        elif self.typ == 1:
            return prod(children_values)
        elif self.typ == 2:
            return min(children_values)
        elif self.typ == 3:
            return max(children_values)
        elif self.typ == 5:
            return int(next(children_values) > next(children_values))
        elif self.typ == 6:
            return int(next(children_values) < next(children_values))
        elif self.typ == 7:
            return int(next(children_values) == next(children_values))


def read_in():
    data = []
    for s in input():
        # ignore first two '0b' chars then pad
        for b in bin(int(s, 16))[2:].zfill(4):
            data.append(b)
    return ''.join(data)


def parse_packet(data):
    ver = int(data[:3], 2)
    typ = int(data[3:6], 2)
    if typ == 4:
        end = 6
        val = ''
        while data[end] == '1':
            val += data[(end + 1):(end + 5)]
            end += 5
        val += data[(end + 1):(end + 5)]
        return LiteralPacket(ver, int(val, 2), end + 5)
    elif data[6] == '0':
        children = []
        length = 22
        total_length = length + int(data[7: length], 2)
        while length < total_length:
            packet = parse_packet(data[length:])
            children.append(packet)
            length += packet.length
        return OperatorPacket(typ, ver, children, length)
    else:
        children = []
        length = 18
        total_packets = int(data[7: length], 2)
        for _ in range(total_packets):
            packet = parse_packet(data[length:])
            children.append(packet)
            length += packet.length
        return OperatorPacket(typ, ver, children, length)


def part_one(packet):
    print(packet.get_ver_sum())


def part_two(packet):
    print(packet.get_val())


if __name__ == '__main__':
    d = read_in()
    p = parse_packet(d)
    part_one(p)
    print()
    part_two(p)
