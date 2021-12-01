import copy


class BingoBoard:
    def __init__(self, board):
        self._board = copy.deepcopy(board)

    def draw(self, x):
        for i in range(len(self._board)):
            for j in range(len(self._board[i])):
                if self._board[i][j] == x:
                    self._board[i][j] = -1
                    break

    def check_win(self):
        for row in self._board:
            if row.count(-1) == len(row):
                return True
        return any(all(self._board[i][j] == -1 for i in range(len(self._board)))
                   for j in range(len(self._board[0])))

    def get_sum_unmarked(self):
        s = 0
        for row in self._board:
            for e in row:
                if e != -1:
                    s += e
        return s


def list_str_to_int(arr):
    return list(map(int, arr))


def read_in():
    numbers = list_str_to_int(input().split(','))
    boards = []
    input()
    while True:
        board = []
        if first_row := list_str_to_int(input().split()):
            board.append(first_row)
            while row := list_str_to_int(input().split()):
                board.append(row)
            boards.append(BingoBoard(board))
        else:
            break
    return numbers, boards


def part_one(data):
    for v in data[0]:
        for board in data[1]:
            board.draw(v)
            if board.check_win():
                print(board.get_sum_unmarked() * v)
                return


def part_two(data):
    boards = data[1].copy()
    last_res = 0
    for v in data[0]:
        to_remove = []
        for board in boards:
            board.draw(v)
            if board.check_win():
                last_res = board.get_sum_unmarked() * v
                to_remove.append(board)
        for board in to_remove:
            boards.remove(board)
    print(last_res)


if __name__ == '__main__':
    d = read_in()
    part_one(d)
    print()
    part_two(d)
