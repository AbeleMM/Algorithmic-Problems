#include <bits/stdc++.h>

using namespace std;

const string root = "root", humn = "humn";

unordered_map<string, vector<string>> readIn() {
    string line;
    unordered_map<string, vector<string>> d;

    while (getline(cin, line) && !line.empty()) {
        istringstream iss(line);
        string key, str;
        iss >> key;
        key.pop_back();
        vector<string> value;
        while (iss >> str) {
            value.push_back(str);
        }
        d.insert({key, std::move(value)});
    }

    return d;
}

unordered_map<string, double> solve(const unordered_map<string, vector<string>> &d,
                                    const string &start,
                                    const unordered_map<string, double> &initAssign) {
    unordered_map<string, double> assigned(initAssign);
    stack<string> s({start});

    while (!s.empty()) {
        const auto &[key, val] = *d.find(s.top());
        if (assigned.find(key) != assigned.cend()) {
            continue;
        } else if (val.size() == 1) {
            assigned[key] = stoi(val[0]);
            s.pop();
        } else if (val.size() == 3) {
            auto itL = assigned.find(val[0]), itR = assigned.find(val[2]);

            if (itR == assigned.cend()) {
                s.push(val[2]);
            }
            if (itL == assigned.cend()) {
                s.push(val[0]);
            }

            if (itL != assigned.cend() && itR != assigned.cend()) {
                if (val[1] == "+") {
                    assigned[key] = (*itL).second + (*itR).second;
                } else if (val[1] == "-") {
                    assigned[key] = (*itL).second - (*itR).second;
                } else if (val[1] == "*") {
                    assigned[key] = (*itL).second * (*itR).second;
                } else if (val[1] == "/") {
                    assigned[key] = (*itL).second / (*itR).second;
                }

                s.pop();
            }
        }
    }

    return assigned;
}

string partOne(const unordered_map<string, vector<string>> &d) {
    auto assigned = solve(d, root, {});
    return to_string(static_cast<long long>(assigned[root]));
}

string partTwo(const unordered_map<string, vector<string>> &d) {
    auto &rootVal = (*d.find(root)).second;
    auto assignedL = solve(d, rootVal[0], {}), assignedR = solve(d, rootVal[2], {});
    string toSearch;
    double tgtVal;
    if (assignedL.find(humn) == assignedL.cend()) {
        toSearch = rootVal[2];
        tgtVal = assignedL[rootVal[0]];
    } else {
        toSearch = rootVal[0];
        tgtVal = assignedR[rootVal[2]];
    }
    auto low = std::numeric_limits<long long>::min() / 2,
            high = std::numeric_limits<long long>::max() / 2;
    long long mid;
    bool inc = solve(d, toSearch, {{humn, low}})[toSearch] <
               solve(d, toSearch, {{humn, high}})[toSearch];

    while (low < high) {
        mid = low + (high - low) / 2;
        auto res = solve(d, toSearch, {{humn, mid}})[toSearch];
        if (res == tgtVal) {
            break;
        }
        if (inc + (res < tgtVal) != 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return to_string(mid);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
