#include <bits/stdc++.h>

using namespace std;

const vector<pair<char, char>> dirs({{0,  1},   // R
                                     {1,  0},   // D
                                     {0,  -1},  // L
                                     {-1, 0}}); // U
const int dirsLen = int(dirs.size());

struct Notes {
    vector<vector<char>> board;
    vector<int> path; // -1 -> L, -2 -> R
};

struct Standing {
    int row{}, col{}, dirInd{};

    bool operator==(const Standing &rhs) const {
        return row == rhs.row && col == rhs.col && dirInd == rhs.dirInd;
    }
};

template<>
struct std::hash<Standing> {
    size_t operator()(const Standing &s) const {
        return static_cast<size_t>(s.row) << 32 | (static_cast<size_t>(s.col) << 16) | s.dirInd;
    }
};

Notes readIn() {
    string line;
    Notes d;

    while (getline(cin, line) && !line.empty()) {
        vector<char> row;
        row.reserve(line.size());

        for (char c: line) {
            switch (c) {
                case ' ':
                    row.push_back(0);
                    break;
                case '#':
                    row.push_back(1);
                    break;
                case '.':
                    row.push_back(2);
                    break;
                default:
                    break;
            }
        }

        d.board.push_back(std::move(row));
    }

    getline(cin, line);
    int val;
    size_t ind;
    while (!line.empty()) {
        switch (line[0]) {
            case 'L' :
                d.path.push_back(-1);
                ind = 1;
                break;
            case 'R' :
                d.path.push_back(-2);
                ind = 1;
                break;
            default:
                val = stoi(line, &ind);
                d.path.push_back(val);
                break;
        }
        line = line.substr(ind);
    }

    return d;
}

Standing calc2D(const Standing &oldS, const Notes &d) {
    Standing newS(oldS);
    const int nrRows = int(d.board.size());
    do {
        newS.row = (newS.row + dirs[newS.dirInd].first) % nrRows;
        newS.row += (newS.row == -1) * nrRows;
    } while (newS.col >= d.board[newS.row].size() || d.board[newS.row][newS.col] == 0);
    const int nrCols = int(d.board[newS.row].size());
    do {
        newS.col = (newS.col + dirs[newS.dirInd].second) % nrCols;
        newS.col += (newS.col == -1) * nrCols;
    } while (d.board[newS.row][newS.col] == 0);

    return newS;
}

Standing calc3D(const Standing &oldS, const unordered_map<Standing, Standing> &edgeMap) {
    auto it = edgeMap.find(oldS);
    if (it != edgeMap.cend()) {
        return (*it).second;
    }

    Standing newS(oldS);
    newS.row += dirs[newS.dirInd].first;
    newS.col += dirs[newS.dirInd].second;
    return newS;
}

void addMap2Way(Standing &a, Standing &b, unordered_map<Standing, Standing> &edgeMap) {
    edgeMap[a] = b;
    a.dirInd = (a.dirInd + dirsLen / 2) % dirsLen, b.dirInd = (b.dirInd + dirsLen / 2) % dirsLen;
    edgeMap[b] = a;
}

int solve(const Notes &d, const bool cube) {
    static const int l = 50;
    Standing stand{};
    unordered_map<Standing, Standing> edgeMap;

    while (d.board[stand.row][stand.col] == 0) {
        stand.col++;
    }

    // Hard-coded for: _12 / _3_ / 45_ / 6__
    if (cube) {
        Standing a, b;

        for (int off = 0; off < l; off++) {
            a = {off, l, 2}, b = {3 * l - 1 - off, 0, 0};                   // 1 <-> 4
            addMap2Way(a, b, edgeMap);

            a = {0, l + off, 3}, b = {3 * l + off, 0, 0};                   // 1 <-> 6
            addMap2Way(a, b, edgeMap);

            a = {l - 1, 2 * l + off, 1}, b = {l + off, 2 * l - 1, 2};       // 2 <-> 3
            addMap2Way(a, b, edgeMap);

            a = {off, 3 * l - 1, 0}, b = {3 * l - 1 - off, 2 * l - 1, 2};   // 2 <-> 5
            addMap2Way(a, b, edgeMap);

            a = {0, 2 * l + off, 3}, b = {4 * l - 1, off, 3};               // 2 <-> 6
            addMap2Way(a, b, edgeMap);

            a = {l + off, l, 2}, b = {2 * l, off, 1};                       // 3 <-> 4
            addMap2Way(a, b, edgeMap);

            a = {3 * l - 1, l + off, 1}, b = {3 * l + off, l - 1, 2};       // 5 <-> 6
            addMap2Way(a, b, edgeMap);
        }
    }

    for (const auto move: d.path) {
        if (move == -1) {
            stand.dirInd = dirsLen * (stand.dirInd == 0) + stand.dirInd - 1;
        } else if (move == -2) {
            stand.dirInd = (stand.dirInd + 1) % dirsLen;
        } else {
            for (int i = 0; i < move; i++) {
                Standing nextStand = cube ? calc3D(stand, edgeMap) : calc2D(stand, d);
                if (d.board[nextStand.row][nextStand.col] == 2) {
                    stand = nextStand;
                } else {
                    break;
                }
            }
        }
    }

    return 1000 * (stand.row + 1) + 4 * (stand.col + 1) + stand.dirInd;
}

string partOne(const Notes &d) {
    return to_string(solve(d, false));
}

string partTwo(const Notes &d) {
    return to_string(solve(d, true));
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
