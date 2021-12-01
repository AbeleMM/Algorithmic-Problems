from collections import defaultdict
from heapq import heappush, heappop


class BurrowState:
    def __init__(self, rooms, corridor=tuple(' ' for _ in range(11))):
        self.rooms = tuple(map(tuple, rooms))
        self.corridor = tuple(corridor)
        self._hash = hash((self.rooms, self.corridor))

    def __lt__(self, other):
        if self.rooms == other.rooms:
            return self.corridor < other.corridor
        return self.rooms < other.rooms

    def __eq__(self, other):
        return self.rooms == other.rooms and self.corridor == other.corridor

    def __hash__(self):
        return self._hash

    def get_next_states(self):
        def corridor_moves(start, curr):
            if curr <= start:
                if curr == start:
                    curr = start - 1
                else:
                    curr -= 1 + (curr > 2)
                if curr >= 0 and corridor[curr] == ' ':
                    return curr
            if curr <= start:
                curr = start + 1
            else:
                curr += 1 + (curr < 8)
            return curr if curr < 11 and corridor[curr] == ' ' else None

        def get_room_pos_enter(room_nr):
            door_char = chr(ord('A') + room_nr)
            pos = len(rooms[room_nr]) - 1
            while pos > 0 and rooms[room_nr][pos] == door_char:
                pos -= 1
            return pos if pos >= 0 and rooms[room_nr][pos] == ' ' else None

        next_states = []
        rooms = list(map(list, self.rooms))
        corridor = list(self.corridor)
        for i in range(len(corridor)):
            if corridor[i] != ' ':
                door_nr = ord(corridor[i]) - ord('A')
                door_i = 2 + door_nr * 2
                dist = abs(i - door_i)
                direct = pow(-1, (i > door_i))
                path_exists = all(corridor[ind] == ' ' for ind in
                                  range(i + direct, i + dist * direct, direct))
                if path_exists and (room_pos := get_room_pos_enter(door_nr)) is not None:
                    r = [x.copy() for x in rooms]
                    c = corridor.copy()
                    c[i] = ' '
                    r[door_nr][room_pos] = corridor[i]
                    cost = (dist + room_pos + 1) * (10 ** door_nr)
                    next_states.append((cost, BurrowState(r, c)))
        for i in range(len(rooms)):
            room_char = chr(ord('A') + i)
            if not all(x == ' ' or x == room_char for x in rooms[i]):
                room_pos = 0
                while rooms[i][room_pos] == ' ':
                    room_pos += 1
                ind = 2 + i * 2
                j = ind
                while (j := corridor_moves(ind, j)) is not None:
                    r = [x.copy() for x in rooms]
                    c = corridor.copy()
                    r[i][room_pos] = ' '
                    c[j] = rooms[i][room_pos]
                    cost = (abs(j - ind) + room_pos + 1) *\
                           (10 ** (ord(rooms[i][room_pos]) - ord('A')))
                    next_states.append((cost, BurrowState(r, c)))
        return next_states

    def is_final(self):
        return all(all(self.rooms[i][j] == chr(ord('A') + i)
                       for j in range(len(self.rooms[i])))
                   for i in range(len(self.rooms)))


def read_in():
    data = [[' '] * 2 for _ in range(4)]
    input(), input()
    for i in [0, 1]:
        value = input()
        for j in range(len(data)):
            data[j][i] = value[3 + 2 * j]
    input()
    return data


def dijkstra(state):
    # Essentially A* with trivial heuristic h(x) = 0
    dist = defaultdict(lambda: float('inf'))
    dist[state] = 0
    heap = []
    heappush(heap, (0, state))
    while heap:
        _, current = heappop(heap)
        if current.is_final():
            return dist[current]
        for cost, neighbour in current.get_next_states():
            new_dist = dist[current] + cost
            if new_dist < dist[neighbour]:
                dist[neighbour] = new_dist
                heappush(heap, (new_dist, neighbour))
    return float('inf')


def part_one(data):
    print(dijkstra(BurrowState(data)))


def part_two(data):
    to_append = [('D', 'D'), ('C', 'B'), ('B', 'A'), ('A', 'C')]
    for i in range(len(data)):
        data[i][1:1] = to_append[i]
    print(dijkstra(BurrowState(data)))
    pass


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
