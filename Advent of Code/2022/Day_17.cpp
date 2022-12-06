#include <bits/stdc++.h>

using namespace std;

// Beware of terminal line-length buffer size limitations.
vector<char> readIn() {
    string line;
    getline(cin, line);
    vector<char> d;
    d.reserve(line.size());

    for (const auto &c: line) {
        d.push_back(c == '<' ? -1 : 1);
    }

    return d;
}

size_t solve(const vector<char> &d, size_t nrRocks) {
    static const int w = 7;
    static const vector<vector<pair<size_t, size_t>>> shapes(
            {{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
             {{0, 1}, {1, 0}, {1, 1}, {1, 2}, {2, 1}},
             {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}},
             {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
             {{0, 0}, {0, 1}, {1, 0}, {1, 1}}});
    size_t maxHeight = 0, shapesInd = 0, dInd = 0, rockInd = 0, cycleStart = 0;
    vector<vector<bool>> board;
    vector<tuple<size_t, size_t, size_t>> history;

    while (cycleStart == 0) {
        board.resize(maxHeight + 4, vector<bool>(w));
        auto shape = shapes[shapesInd];
        bool moving = true;

        for (auto &[row, col]: shape) {
            row += board.size() - 1;
            col += 2;
        }

        while (moving) {
            bool push = true;

            for (const auto &[row, col]: shape) {
                if ((d[dInd] == -1 &&
                     (col == 0 || (row < board.size() && board[row][col - 1]))) ||
                    (d[dInd] == 1 &&
                     (col == w - 1 || (row < board.size() && board[row][col + 1])))) {
                    push = false;
                    break;
                }
            }

            for (auto &[row, col]: shape) {
                col += d[dInd] * push;
                if (row == 0 || (row < board.size() && board[row - 1][col])) {
                    moving = false;
                    if (!push) {
                        break;
                    }
                }
            }

            if (moving) {
                for (auto &[row, _]: shape) {
                    row--;
                }
            } else {
                for (auto &[row, col]: shape) {
                    board[row][col] = true;
                    maxHeight = max(maxHeight, row + 1);
                }
            }

            dInd = (dInd + 1) % d.size();
        }

        if (rockInd + 1 == nrRocks) {
            return maxHeight;
        }

        history.emplace_back(shapesInd, dInd, maxHeight);
        size_t historyEnd = history.size() - 1;

        bool hit = false;
        for (int i = 0; i < historyEnd; i++) {
            if (get<0>(history[i]) == get<0>(history[historyEnd]) &&
                get<1>(history[i]) == get<1>(history[historyEnd])) {
                cycleStart = hit * i;
                hit = true;
            }
        }

        shapesInd = (shapesInd + 1) % shapes.size();
        rockInd++;
    }

    size_t remaining = nrRocks - rockInd, cycleLen = history.size() - cycleStart - 1,
            startHeight = get<2>(history[cycleStart]),
            cycleHeight = get<2>(history[history.size() - 1]) - startHeight;

    maxHeight += (remaining / cycleLen) * cycleHeight +
                 (get<2>(history[cycleStart + (remaining % cycleLen)]) - startHeight);

    return maxHeight;
}

string partOne(const vector<char> &d) {
    return to_string(solve(d, 2022));
}

string partTwo(const vector<char> &d) {
    return to_string(solve(d, 1000000000000));
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
