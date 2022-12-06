#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int32_t x, y;

    bool operator==(const Pos &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator<(const Pos &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }

    Pos operator+(const Pos &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
};

template<>
struct std::hash<Pos> {
    size_t operator()(const Pos &p) const {
        return static_cast<size_t>(p.x) << 24 | p.y;
    }
};

struct PosTime {
    Pos pos;
    int t;

    bool operator==(const PosTime &rhs) const {
        return pos == rhs.pos && t == rhs.t;
    }

    bool operator<(const PosTime &rhs) const {
        return pos < rhs.pos || (pos == rhs.pos && t < rhs.t);
    }
};

template<>
struct std::hash<PosTime> {
    size_t operator()(const PosTime &pt) const {
        return hash<Pos>()(pt.pos) << 48 | pt.t;
    }
};

const unordered_map<char, Pos> dirMap({{' ', {0,  0}},
                                       {'^', {-1, 0}},
                                       {'v', {1,  0}},
                                       {'<', {0,  -1}},
                                       {'>', {0,  1}}});

pair<unordered_map<Pos, Pos>, Pos> readIn() {
    string line;
    unordered_map<Pos, Pos> tornadoes;
    getline(cin, line);
    Pos maxPos{0, int32_t(line.size()) - 2};

    while (getline(cin, line) && line[1] != '#') {
        for (int i = 1; i < line.size() - 1; i++) {
            auto it = dirMap.find(line[i]);
            if (it != dirMap.cend()) {
                tornadoes.insert({{maxPos.x, i - 1}, (*it).second});
            }
        }
        maxPos.x++;
    }

    return {std::move(tornadoes), maxPos};
}

vector<vector<bool>> getTornadoesAtStep(const pair<unordered_map<Pos, Pos>, Pos> &d, int step) {
    vector<vector<bool>> res(d.second.x, vector<bool>(d.second.y));

    for (const auto &[start, dir]: d.first) {
        auto indX = (start.x + dir.x * step) % d.second.x,
                indY = (start.y + dir.y * step) % d.second.y;
        indX += (indX < 0) * d.second.x;
        indY += (indY < 0) * d.second.y;
        res[indX][indY] = true;
    }

    return res;
}

int bfs(const pair<unordered_map<Pos, Pos>, Pos> &d, const PosTime &sPosTime, const Pos &fPos) {
    vector<vector<vector<bool>>> tornadoMaps({getTornadoesAtStep(d, sPosTime.t)});
    queue<PosTime> q({sPosTime});
    unordered_set<PosTime> visited({sPosTime});
    int retryTime = sPosTime.t;

    while (!q.empty()) {
        auto [p, t] = q.front();
        if (p == fPos) {
            return t;
        }
        q.pop();
        t++;

        if (t == sPosTime.t + tornadoMaps.size()) {
            tornadoMaps.push_back(getTornadoesAtStep(d, t));
        }

        if (!tornadoMaps[t - 1 - sPosTime.t][p.x][p.y]) {
            for (const auto &[_, off]: dirMap) {
                const Pos newP = p + off;
                const PosTime candidate{newP, t};
                if (clamp(newP.x, 0, d.second.x - 1) == newP.x &&
                    clamp(newP.y, 0, d.second.y - 1) == newP.y &&
                    !tornadoMaps[t - sPosTime.t][newP.x][newP.y] &&
                    visited.find(candidate) == visited.cend()) {
                    visited.insert(candidate);
                    q.push(candidate);
                }
            }
        }

        if (q.empty()) {
            q.push({sPosTime.pos, ++retryTime});
        }
    }

    return -1;
}

string partOne(const pair<unordered_map<Pos, Pos>, Pos> &d) {
    return to_string(bfs(d, {0, 0, 1}, {d.second.x - 1, d.second.y - 1}) + 1);
}

string partTwo(const pair<unordered_map<Pos, Pos>, Pos> &d) {
    int t = 1;
    t = bfs(d, {0, 0, t}, {d.second.x - 1, d.second.y - 1}) + 1;
    t = bfs(d, {d.second.x - 1, d.second.y - 1, t}, {0, 0}) + 1;
    t = bfs(d, {0, 0, t}, {d.second.x - 1, d.second.y - 1}) + 1;

    return to_string(t);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
