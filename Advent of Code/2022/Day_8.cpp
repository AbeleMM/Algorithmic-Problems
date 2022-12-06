#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> readIn() {
    string line;
    vector<vector<int>> d;

    while (getline(cin, line) && !line.empty()) {
        vector<int> v;
        v.reserve(line.length());

        for (const auto c: line) {
            v.push_back(c - '0');
        }

        d.push_back(v);
    }

    return d;
}

string partOne(const vector<vector<int>> &d) {
    auto sum = 2 * (d.size() + d[0].size() - 2);

    for (int i = 1; i < d.size() - 1; i++) {
        for (int j = 1; j < d[i].size() - 1; j++) {
            int maxU = -1, maxD = -1, maxL = -1, maxR = -1;

            int k = 0;
            while (k < i) {
                maxU = max(maxU, d[k][j]);
                k++;
            }
            k++;
            while (k < d.size()) {
                maxD = max(maxD, d[k][j]);
                k++;
            }

            k = 0;
            while (k < j) {
                maxL = max(maxL, d[i][k]);
                k++;
            }
            k++;
            while (k < d[i].size()) {
                maxR = max(maxR, d[i][k]);
                k++;
            }

            sum += min({maxU, maxD, maxL, maxR}) < d[i][j];
        }
    }

    return to_string(sum);
}

string partTwo(const vector<vector<int>> &d) {
    int maxScore = 0;

    for (int i = 1; i < d.size() - 1; i++) {
        for (int j = 1; j < d[i].size() - 1; j++) {
            int k = i - 1;
            while (k >= 0 && d[k][j] < d[i][j]) {
                k--;
            }
            int sU = i - k - (k == -1);
            k = i + 1;
            while (k < d.size() && d[k][j] < d[i][j]) {
                k++;
            }
            int sD = k - i - (k == d.size());

            k = j - 1;
            while (k >= 0 && d[i][k] < d[i][j]) {
                k--;
            }
            int sL = j - k - (k == -1);
            k = j + 1;
            while (k < d[i].size() && d[i][k] < d[i][j]) {
                k++;
            }
            int sR = k - j - (k == d[i].size());

            maxScore = max(maxScore, sU * sD * sL * sR);
        }
    }

    return to_string(maxScore);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
