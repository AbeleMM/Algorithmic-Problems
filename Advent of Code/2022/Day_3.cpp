#include <bits/stdc++.h>

using namespace std;

vector<string> readIn() {
    string line;
    vector<string> d;

    while (getline(cin, line) && !line.empty()) {
        d.push_back(line);
    }

    return d;
}

int getScore(const char &c) {
    return islower(c) ? (c - 'a') + 1 : (c - 'A') + 27;
}

string partOne(const vector<string> &d) {
    int sum = 0;

    for (const auto &x: d) {
        const auto backHalf(x.substr(x.size() / 2));
        for (const auto c: x.substr(0, x.size() / 2)) {
            if (backHalf.find(c) != string::npos) {
                sum += getScore(c);
                break;
            }
        }
    }

    return to_string(sum);
}

string partTwo(const vector<string> &d) {
    int sum = 0;

    for (int i = 0; i < d.size(); i += 3) {
        for (const auto c: d[i]) {
            if (d[i + 1].find(c) != string::npos && d[i + 2].find(c) != string::npos) {
                sum += getScore(c);
                break;
            }
        }
    }

    return to_string(sum);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
