#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int x, y;

    bool operator<(const Pos &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

typedef vector<vector<int>> hill;

struct Instance {
    hill h;
    Pos s, e;
};

Instance readIn() {
    string line;
    Instance d{};
    int i = 0;

    while (getline(cin, line) && !line.empty()) {
        vector<int> v;
        v.reserve(line.size());
        int j = 0;

        for (const auto c: line) {
            if (c == 'S') {
                v.push_back(0);
                d.s = {i, j};
            } else if (c == 'E') {
                v.push_back(25);
                d.e = {i, j};
            } else {
                v.push_back(c - 'a');
            }

            j++;
        }

        d.h.push_back(std::move(v));
        v.clear();
        i++;
    }

    return d;
}

hill bfs(const hill &h, const Pos &start, bool inc) {
    queue<Pos> q;
    q.emplace(start);
    hill dist(h.size(), vector<int>(h[0].size(), std::numeric_limits<int>::max()));
    int multi = inc ? 1 : -1;
    dist[start.x][start.y] = 0;

    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();
        vector<Pos> neighbors;
        if (pos.x > 0) {
            neighbors.push_back({pos.x - 1, pos.y});
        }
        if (pos.y > 0) {
            neighbors.push_back({pos.x, pos.y - 1});
        }
        if (pos.x < h.size() - 1) {
            neighbors.push_back({pos.x + 1, pos.y});
        }
        if (pos.y < h[0].size() - 1) {
            neighbors.push_back({pos.x, pos.y + 1});
        }

        for (const auto &neigh: neighbors) {
            if (multi * h[neigh.x][neigh.y] <= multi * h[pos.x][pos.y] + 1 &&
                dist[neigh.x][neigh.y] > dist[pos.x][pos.y] + 1) {
                dist[neigh.x][neigh.y] = dist[pos.x][pos.y] + 1;
                q.push(neigh);
            }
        }
    }

    return dist;
}

string partOne(const Instance &d) {
    return to_string(bfs(d.h, d.s, true)[d.e.x][d.e.y]);
}

string partTwo(const Instance &d) {
    int distMin = std::numeric_limits<int>::max();
    auto dists = bfs(d.h, d.e, false);

    for (int i = 0; i < d.h.size(); i++) {
        for (int j = 0; j < d.h[0].size(); j++) {
            if (d.h[i][j] == 0) {
                distMin = min(distMin, dists[i][j]);
            }
        }
    }

    return to_string(distMin);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
