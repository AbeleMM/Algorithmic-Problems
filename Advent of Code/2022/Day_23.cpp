#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int32_t x, y;

    bool operator==(const Pos &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    Pos operator+(const Pos &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
};

template<>
struct std::hash<Pos> {
    size_t operator()(const Pos &p) const {
        return static_cast<size_t>(p.x) << 32 | p.y;
    }
};

const vector<Pos> dirs({{-1, 0},
                        {1,  0},
                        {0,  -1},
                        {0,  1}});
const vector<vector<Pos>> sides({{{0,  -1}, {0, 0}, {0, 1}},
                                 {{-1, 0},  {0, 0}, {1, 0}}});

unordered_set<Pos> readIn() {
    string line;
    unordered_set<Pos> d;
    int x = 0;

    while (getline(cin, line) && !line.empty()) {
        for (int y = 0; y < line.size(); y++) {
            if (line[y] == '#') {
                d.insert({x, y});
            }
        }
        x++;
    }

    return d;
}


void runStep(unordered_set<Pos> &grove, size_t &startDirInd) {
    unordered_map<Pos, Pos> oldToNewPos;
    unordered_map<Pos, int> newCount;

    for (const auto &oldP: grove) {
        size_t i = 0;

        for (int xOff = -1; xOff < 2; xOff++) {
            for (int yOff = -1; yOff < 2; yOff++) {
                Pos off{xOff, yOff};
                i += (xOff != 0 || yOff != 0) && (grove.find(oldP + off) != grove.cend());
            }
        }

        if (i > 0) {
            i = startDirInd;
            do {
                Pos newP = oldP + dirs[i];
                bool free = true;

                for (const auto &off: sides[i / (dirs.size() / 2)]) {
                    free = free && (grove.find(newP + off) == grove.cend());
                }

                if (free) {
                    oldToNewPos[oldP] = newP;
                    newCount[newP]++;
                    break;
                }
                i = (i + 1) % dirs.size();
            } while (i != startDirInd);
        }
    }

    for (const auto &[oldP, newP]: oldToNewPos) {
        if (newCount[newP] == 1) {
            grove.erase(oldP);
            grove.insert(newP);
        }
    }

    startDirInd = (startDirInd + 1) % dirs.size();
}

string partOne(const unordered_set<Pos> &d) {
    unordered_set<Pos> grove(d);
    size_t startDirInd = 0;

    for (int round = 0; round < 10; round++) {
        runStep(grove, startDirInd);
    }

    Pos mn{}, mx{};
    for (const auto &p: grove) {
        mn.x = min(mn.x, p.x), mn.y = min(mn.y, p.y);
        mx.x = max(mx.x, p.x), mx.y = max(mx.y, p.y);
    }

    return to_string((mx.x - mn.x + 1) * (mx.y - mn.y + 1) - grove.size());
}

string partTwo(const unordered_set<Pos> &d) {
    unordered_set<Pos> oldGrove, grove(d);
    size_t startDirInd = 0, steps = 0;

    while (oldGrove != grove) {
        oldGrove = grove;
        runStep(grove, startDirInd);
        steps++;
    }

    return to_string(steps);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
