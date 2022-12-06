#include <bits/stdc++.h>

using namespace std;

struct Valve {
    int flow{};
    vector<int> valves;
};

unordered_map<string, int> nameMap;

pair<int, vector<Valve>> readIn() {
    string line;
    vector<Valve> d;

    while (getline(cin, line) && !line.empty()) {
        string key = line.substr(6, 2);
        if (nameMap.find(key) == nameMap.cend()) {
            nameMap[key] = int(nameMap.size());
        }
        if (nameMap[key] >= d.size()) {
            d.resize(nameMap[key] + 1);
        }
        Valve &valve = d[nameMap[key]];
        valve.flow = stoi(line.substr(23));

        for (auto i = line.size() - 1; isupper(line[i]); i -= 4) {
            string s = line.substr(i - 1, 2);
            if (nameMap.find(s) == nameMap.cend()) {
                nameMap[s] = int(nameMap.size());
            }
            valve.valves.push_back(nameMap[s]);
        }
    }

    return {nameMap["AA"], d};
}

vector<int> bfs(const int start, const vector<Valve> &v) {
    queue<int> q;
    q.push(start);
    vector<int> dists(v.size(), std::numeric_limits<int>::max());
    dists[start] = 0;

    while (!q.empty()) {
        const auto curr = q.front();

        for (const auto neigh: v[curr].valves) {
            if (dists[neigh] > dists[curr] + 1) {
                dists[neigh] = dists[curr] + 1;
                q.push(neigh);
            }
        }

        q.pop();
    }

    return dists;
}

int solveSolo(const int t, const int curr, vector<bool> &open,
              const vector<vector<int>> &distCache,
              const vector<Valve> &v) {
    static const int tMx = 30;
    if (t == tMx) {
        return 0;
    }

    open[curr] = true;
    int maxPressure = 0;
    auto &dists = distCache[curr];

    for (int i = 0; i < dists.size(); i++) {
        if (!open[i] && dists[i] < tMx - t && v[i].flow > 0) {
            maxPressure = max(maxPressure, solveSolo(t + dists[i] + 1, i, open, distCache, v));
        }
    }

    open[curr] = false;

    return maxPressure + (tMx - t) * v[curr].flow;
}

int solveDuo(const int t, const pair<int, int> H, const pair<int, int> E,
             vector<bool> &open, const vector<vector<int>> &distCache,
             const vector<Valve> &v) {
    static const int tMx = 26;
    if (t == tMx) {
        return 0;
    }

    // E, H: first -> destination, second -> ETA
    vector<int> nextH(v.size()), nextE(v.size());
    int maxPressure = 0, newFlow = 0;

    if (t == H.second) {
        open[H.first] = true;
        auto &dists = distCache[H.first];
        bool empty = true;
        newFlow += v[H.first].flow;

        for (int i = 0; i < dists.size(); i++) {
            if (!open[i] && dists[i] < tMx - t && v[i].flow > 0 && i != E.first) {
                nextH[i] = t + dists[i] + 1;
                empty = false;
            }
        }

        nextH[H.first] = empty * tMx;
    } else {
        nextH[H.first] = H.second;
    }

    if (t == E.second) {
        open[E.first] = true;
        auto &dists = distCache[E.first];
        bool empty = true;
        newFlow += v[E.first].flow;

        for (int i = 0; i < dists.size(); i++) {
            if (!open[i] && dists[i] < tMx - t && v[i].flow > 0 && i != H.first) {
                nextE[i] = t + dists[i] + 1;
                empty = false;
            }
        }

        nextE[E.first] = empty * tMx;
    } else {
        nextE[E.first] = E.second;
    }

    for (int i = 0; i < nextH.size(); i++) {
        if (nextH[i] > 0 && nextE[i] > 0) {
            if (nextH[i] < nextE[i]) {
                nextE[i] = 0;
            } else if (nextE[i] < nextH[i]) {
                nextH[i] = 0;
            }
        }
    }

    for (int i = 0; i < nextH.size(); i++) {
        if (nextH[i] == 0) {
            continue;
        }
        for (int j = 0; j < nextE.size(); j++) {
            if (nextE[j] == 0 || i == j) {
                continue;
            }
            maxPressure = max(maxPressure, solveDuo(
                    min(nextH[i], nextE[j]), {i, nextH[i]}, {j, nextE[j]}, open, distCache, v));
        }
    }

    if (t == H.second) {
        open[H.first] = false;
    }
    if (t == E.second) {
        open[E.first] = false;
    }

    return maxPressure + (tMx - t) * newFlow;
}

string partOne(const pair<int, vector<Valve>> &d) {
    vector<bool> open(d.second.size());
    vector<vector<int>> distCache;
    distCache.reserve(d.second.size());

    for (int i = 0; i < d.second.size(); i++) {
        distCache.push_back(bfs(i, d.second));
    }

    return to_string(solveSolo(0, d.first, open, distCache, d.second));
}

string partTwo(const pair<int, vector<Valve>> &d) {
    vector<bool> open(d.second.size());
    vector<vector<int>> distCache;
    distCache.reserve(d.second.size());

    for (int i = 0; i < d.second.size(); i++) {
        distCache.push_back(bfs(i, d.second));
    }

    return to_string(solveDuo(0, {d.first, 0}, {d.first, 0}, open, distCache, d.second));
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
