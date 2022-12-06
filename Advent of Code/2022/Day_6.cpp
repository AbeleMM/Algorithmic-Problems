#include <bits/stdc++.h>

using namespace std;

string readIn() {
    string line;

    getline(cin, line);

    return line;
}

string findMarkerPos(const string &d, int len) {
    for (int i = len - 1; i < d.size(); i++) {
        set<char> charSet;
        for (int j = 0; j < len; j++) {
            charSet.insert(d[i - j]);
        }
        if (charSet.size() == len) {
            return to_string(i + 1);
        }
    }

    return "";
}

string partOne(const string &d) {
    return findMarkerPos(d, 4);
}

string partTwo(const string &d) {
    return findMarkerPos(d, 14);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
