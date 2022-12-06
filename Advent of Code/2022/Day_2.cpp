#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> readIn() {
    string line;
    vector<pair<int, int>> d;

    while (getline(cin, line) && !line.empty()) {
        d.emplace_back(line[0] - 'A', line[2] - 'X');
    }

    return d;
}

string partOne(const vector<pair<int, int>> &d) {
    int score = 0;

    for (const auto &[x, y]: d) {
        score += y + 1;
        if (x == y) {
            score += 3;
        } else if ((x + 1) % 3 == y) {
            score += 6;
        }
    }

    return to_string(score);
}

string partTwo(const vector<pair<int, int>> &d) {
    int score = 0;

    for (const auto &x: d) {
        score += 1 + x.second * 3;
        if (x.second == 0) {
            score += (x.first + 2) % 3;
        } else if (x.second == 1) {
            score += x.first;
        } else {
            score += (x.first + 1) % 3;
        }
    }

    return to_string(score);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
