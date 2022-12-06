#include <bits/stdc++.h>

using namespace std;

vector<pair<char, int>> readIn() {
    string line;
    vector<pair<char, int>> d;

    while (getline(cin, line) && !line.empty()) {
        d.emplace_back(line[0], stoi(line.substr(2)));
    }

    return d;
}

string simulateRope(const vector<pair<char, int>> &d, const int ropeSize) {
    vector<pair<int, int>> rope;
    rope.reserve(ropeSize);
    set<pair<int, int>> visited({{0, 0}});

    for (int i = 0; i < ropeSize; i++) {
        rope.emplace_back(0, 0);
    }

    for (const auto &[c, x]: d) {
        int dirHX = 0, dirHY = 0;

        switch (c) {
            case 'U':
                dirHX = -1;
                break;
            case 'D':
                dirHX = 1;
                break;
            case 'L':
                dirHY = -1;
                break;
            case 'R':
                dirHY = 1;
                break;
            default:
                break;
        }

        for (int n = 0; n < x; n++) {
            rope[0].first += dirHX;
            rope[0].second += dirHY;

            for (int i = 1; i < rope.size(); i++) {
                auto &h = rope[i - 1], &t = rope[i];
                if (abs(h.first - t.first) > 1 || abs(h.second - t.second) > 1) {
                    int dirTX = 0, dirTY = 0;

                    if (h.first != t.first) {
                        dirTX = -1 + 2 * (h.first > t.first);
                    }
                    if (h.second != t.second) {
                        dirTY = -1 + 2 * (h.second > t.second);
                    }

                    t.first += dirTX;
                    t.second += dirTY;
                }
            }

            visited.emplace(rope[ropeSize - 1].first, rope[ropeSize - 1].second);
        }
    }

    return to_string(visited.size());
}

string partOne(const vector<pair<char, int>> &d) {
    return simulateRope(d, 2);
}

string partTwo(const vector<pair<char, int>> &d) {
    return simulateRope(d, 10);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
