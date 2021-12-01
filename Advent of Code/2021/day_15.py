from heapq import heappush, heappop


def read_in():
    data = []
    while value := input():
        data.append([int(x) for x in value])
    return data


offset_pairs = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def get_ind_neighbors(max_i, max_j, i, j):
    res = []
    for (offset_i, offset_j) in offset_pairs:
        new_i = i + offset_i
        new_j = j + offset_j
        if 0 <= new_i < max_i and 0 <= new_j < max_j:
            res.append((new_i, new_j))
    return res


def dijkstra(data):
    dist = [[float('inf') for _ in data[0]] for _ in data]
    dist[0][0] = 0
    # heap contains elements of the form (weight, (i, j))
    heap = []
    heappush(heap, (0, (0, 0)))
    while heap:
        _, (curr_i, curr_j) = heappop(heap)
        for i, j in get_ind_neighbors(len(data), len(data[0]), curr_i, curr_j):
            if dist[i][j] > dist[curr_i][curr_j] + data[i][j]:
                dist[i][j] = dist[curr_i][curr_j] + data[i][j]
                heappush(heap, (dist[i][j], (i, j)))
    return dist[-1][-1]


def part_one(data):
    print(dijkstra(data))


def part_two(data):
    t = 5
    mx_i = len(data)
    mx_j = len(data[0])
    tiled_data = [[0 for _ in range(t * mx_j)] for _ in range(t * mx_i)]
    for i in range(mx_i):
        for j in range(mx_j):
            for multi_i in range(t):
                for multi_j in range(t):
                    new_val = data[i][j] + multi_i + multi_j
                    new_val = new_val % 10 + (new_val > 9)
                    tiled_data[i + mx_i * multi_i][j + mx_j * multi_j] = new_val
    print(dijkstra(tiled_data))


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
