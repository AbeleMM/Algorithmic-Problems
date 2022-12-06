#include <bits/stdc++.h>

using namespace std;

vector<int> readIn() {
    string line;
    vector<int> d;

    while (getline(cin, line) && !line.empty()) {
        if (line.size() == 4) { // noop
            d.push_back(0);
        } else { // addx
            d.push_back(stoi(line.substr(5)));
        }
    }

    return d;
}

string partOne(const vector<int> &d) {
    int sum = 0, x = 1, cycle = 1;

    for (const auto e: d) {
        cycle++;
        sum += cycle * x * ((cycle - 20) % 40 == 0);

        if (e != 0) {
            cycle++;
            x += e;
            sum += cycle * x * ((cycle - 20) % 40 == 0);
        }
    }

    return to_string(sum);
}

string partTwo(const vector<int> &d) {
    int x = 1, dInd = 0;
    bool adding = false;
    ostringstream strStream;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 40; j++) {
            if (abs(x - j) < 2) {
                strStream << '#';
            } else {
                strStream << '.';
            }

            if (adding) {
                x += d[dInd++];
                adding = false;
            } else if (d[dInd] == 0) {
                dInd++;
            } else {
                adding = true;
            }
        }
        strStream << endl;
    }

    return strStream.str();
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
