#include <bits/stdc++.h>

using namespace std;

vector<int> readIn() {
    string line;
    vector<int> d;

    while (getline(cin, line) && !line.empty()) {
        d.push_back(stoi(line));
    }

    return d;
}

inline int calcInd(const int init, const long long off, int len) {
    auto sum = init + off, final = sum % --len;
    if (final <= 0 && sum != 0) {
        final += len;
    }
    return int(final);
}


long long solve(const vector<int> &d, const int key, const int nrIt) {
    vector<long long> dMulti;
    vector<int> origIndices;
    const int fileLen = int(d.size());
    dMulti.reserve(fileLen);
    origIndices.reserve(fileLen);

    for (int i = 0; i < fileLen; i++) {
        dMulti.push_back(static_cast<long long>(d[i]) * key);
        origIndices.emplace_back(i);
    }

    for (int it = 0; it < nrIt; it++) {
        for (int i = 0; i < fileLen; i++) {
            int currPos = 0;

            while (origIndices[currPos] != i) {
                currPos++;
            }

            auto newPos = calcInd(currPos, dMulti[i], fileLen);
            origIndices.erase(origIndices.cbegin() + currPos);
            origIndices.insert(origIndices.cbegin() + newPos, i);
        }
    }

    int zeroInd = 0;
    while (dMulti[origIndices[zeroInd]] != 0) {
        zeroInd++;
    }

    long long sum = dMulti[origIndices[(zeroInd + 1000) % fileLen]] +
                    dMulti[origIndices[(zeroInd + 2000) % fileLen]] +
                    dMulti[origIndices[(zeroInd + 3000) % fileLen]];

    return sum;
}

string partOne(const vector<int> &d) {
    return to_string(solve(d, 1, 1));
}

string partTwo(const vector<int> &d) {
    return to_string(solve(d, 811589153, 10));
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
