#include <bits/stdc++.h>

using namespace std;

const string digits = "=-012";
const int mid = int(digits.size()) / 2;


vector<string> readIn() {
    string line;
    vector<string> d;

    while (getline(cin, line) && !line.empty()) {
        d.push_back(std::move(line));
    }

    return d;
}

long long snafuToDec(string snafu) {
    long long dec = 0, pwr = 1;

    for (auto it = snafu.rbegin(); it != snafu.rend(); it++) {
        int place = int(find(digits.cbegin(), digits.cend(), *it) - digits.cbegin()) - mid;
        dec += pwr * place;
        pwr *= 5;
    }

    return dec;
}

string decToSnafu(long long dec) {
    bool neg = dec < 0;
    dec = abs(dec);
    string snafu;

    while (dec > 0) {
        auto rem = dec % 5;
        dec /= 5;
        if (rem == 3) {
            rem = -2;
            dec++;
        } else if (rem == 4) {
            rem = -1;
            dec++;
        }
        snafu += digits[rem * (neg ? -1 : 1) + mid];
    }

    std::reverse(snafu.begin(), snafu.end());

    return snafu;
}

string partOne(const vector<string> &d) {
    long long sum = 0;

    for (const auto &nr: d) {
        sum += snafuToDec(nr);
    }

    return decToSnafu(sum);
}

string partTwo(const vector<string> &d) {
    return "";
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
