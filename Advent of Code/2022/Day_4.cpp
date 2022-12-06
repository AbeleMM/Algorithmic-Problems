#include <bits/stdc++.h>

using namespace std;

struct AssignmentPair {
    const int sOne, tOne, sOther, tOther;

    AssignmentPair(const int sOne, const int tOne, const int sOther, const int tOther) :
            sOne(sOne), tOne(tOne), sOther(sOther), tOther(tOther) {}
};

vector<AssignmentPair> readIn() {
    string line;
    vector<AssignmentPair> d;
    int sOne, tOne, sOther, tOther;
    char sep;

    while (getline(cin, line) && !line.empty()) {
        istringstream lineStream(line);
        lineStream >> sOne >> sep >> tOne >> sep >> sOther >> sep >> tOther;
        d.emplace_back(sOne, tOne, sOther, tOther);
    }

    return d;
}

string partOne(const vector<AssignmentPair> &d) {
    int sum = 0;

    for (const auto &ap: d) {
        sum += (ap.sOne >= ap.sOther && ap.tOne <= ap.tOther) ||
               (ap.sOne <= ap.sOther && ap.tOne >= ap.tOther);
    }

    return to_string(sum);
}

string partTwo(const vector<AssignmentPair> &d) {
    int sum = 0;

    for (const auto &ap: d) {
        sum += ap.sOne <= ap.tOther && ap.tOne >= ap.sOther;
    }

    return to_string(sum);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
