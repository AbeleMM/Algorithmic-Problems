#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int x{}, y{}, z{};

    bool operator==(const Pos &rhs) const {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }
};

template<>
struct std::hash<Pos> {
    size_t operator()(const Pos &p) const {
        return static_cast<size_t>(p.x) << 32 | (static_cast<size_t>(p.y) << 16) | p.z;
    }
};

int readCoord(string &s) {
    s = s.substr(s.find(',') + 1);
    return stoi(s);
}

vector<Pos> readIn() {
    string line;
    vector<Pos> d;

    while (getline(cin, line) && !line.empty()) {
        d.push_back({stoi(line), readCoord(line), readCoord(line)});
    }

    return d;
}

string partOne(const vector<Pos> &d) {
    auto area = d.size() * 6;

    for (int i = 0; i < d.size(); i++) {
        for (int j = i + 1; j < d.size(); j++) {
            area -= 2 *
                    ((abs(d[i].x - d[j].x) + abs(d[i].y - d[j].y) + abs(d[i].z - d[j].z)) == 1);
        }
    }

    return to_string(area);
}

vector<Pos> getNeighbors(const Pos &pos) {
    return {{pos.x - 1, pos.y,     pos.z},
            {pos.x + 1, pos.y,     pos.z},
            {pos.x,     pos.y - 1, pos.z},
            {pos.x,     pos.y + 1, pos.z},
            {pos.x,     pos.y,     pos.z - 1},
            {pos.x,     pos.y,     pos.z + 1}};
}

string partTwo(const vector<Pos> &d) {
    int area = 0;
    unordered_set<Pos> cubes(d.cbegin(), d.cend()), visited(cubes);
    Pos mn, mx;

    for (const auto &pos: d) {
        mn.x = min(mn.x, pos.x), mn.y = min(mn.y, pos.y), mn.z = min(mn.z, pos.z);
        mx.x = max(mx.x, pos.x), mx.y = max(mx.y, pos.y), mx.z = max(mx.z, pos.z);
    }

    mn.x--, mn.y--, mn.z--;
    mx.x++, mx.y++, mx.z++;

    queue<Pos> q({mn});
    visited.insert(mn);

    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();

        for (const auto &neighbor: getNeighbors(pos)) {
            area += cubes.find(neighbor) != cubes.cend();
            if (clamp(neighbor.x, mn.x, mx.x) == neighbor.x &&
                clamp(neighbor.y, mn.y, mx.y) == neighbor.y &&
                clamp(neighbor.z, mn.z, mx.z) == neighbor.z &&
                visited.find(neighbor) == visited.cend()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    return to_string(area);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
