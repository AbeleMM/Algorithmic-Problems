#include <bits/stdc++.h>

using namespace std;

const pair<int, int> sandSource(0, 500);

enum Status {
    rest, moving, out
};

void updateMax(vector<vector<bool>> &d, pair<int, int> &mx, const pair<int, int> p) {
    if (p.first >= mx.first) {
        mx.first = p.first + 1;
        d.resize(mx.first, vector<bool>(mx.second));
    }
    if (p.second >= mx.second) {
        mx.second = p.second + 1;
        for (auto &row: d) {
            row.resize(mx.second);
        }
    }
}

vector<vector<bool>> readIn() {
    string line;
    pair<int, int> mx = sandSource;
    vector<vector<bool>> d(mx.first, vector<bool>(mx.second));
    char c;
    string s;
    pair<int, int> prev, curr;

    while (getline(cin, line) && !line.empty()) {
        istringstream stream(line);
        stream >> prev.second >> c >> prev.first >> s;
        updateMax(d, mx, prev);

        do {
            stream >> curr.second >> c >> curr.first;
            updateMax(d, mx, curr);

            for (int i = min(prev.first, curr.first); i <= max(prev.first, curr.first); i++) {
                d[i][curr.second] = true;
            }
            for (int j = min(prev.second, curr.second); j <= max(prev.second, curr.second); j++) {
                d[curr.first][j] = true;
            }

            prev = curr;
        } while (stream >> s);
    }

    return d;
}

int runAllUnits(vector<vector<bool>> &dSand) {
    int units = 0;
    bool flow = true;

    while (flow) {
        Status status = moving;
        auto [posX, posY] = sandSource;

        while (status == moving) {
            if (posX + 1 < dSand.size() && !dSand[posX + 1][posY]) {
                posX++;
            } else if (posX + 1 < dSand.size()) {
                if (posY - 1 >= 0) {
                    if (!dSand[posX + 1][posY - 1]) {
                        posX++, posY--;
                    } else if (posY + 1 < dSand[0].size()) {
                        if (!dSand[posX + 1][posY + 1]) {
                            posX++, posY++;
                        } else {
                            dSand[posX][posY] = true;
                            status = rest;
                        }
                    } else {
                        status = out;
                    }
                } else {
                    status = out;
                }
            } else {
                status = out;
            }
        }

        flow = status == rest;
        units += flow;
        flow &= make_pair(posX, posY) != sandSource;
    }

    return units;
}

string partOne(const vector<vector<bool>> &d) {
    vector<vector<bool>> dSand(d);
    return to_string(runAllUnits(dSand));
}

string partTwo(const vector<vector<bool>> &d) {
    vector<vector<bool>> dSand(d);
    pair<int, int> oldMx(d.size(), d[0].size()),
            newMx(d.size() + 1, sandSource.second + d.size() - sandSource.first + 2);
    updateMax(dSand, oldMx, newMx);

    for (auto &&b: dSand[dSand.size() - 1]) {
        b = true;
    }

    return to_string(runAllUnits(dSand));
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
