#include <bits/stdc++.h>

using namespace std;

struct Monkey {
    vector<int> items;
    char op;
    int opVal, test, t, f;
};

vector<Monkey> readIn() {
    string line;
    vector<Monkey> d;

    while (getline(cin, line) && !line.empty()) {
        Monkey m{};

        getline(cin, line);
        istringstream s(line.substr(18));
        int x;
        char c;
        while (s >> x) {
            m.items.push_back(x);
            s >> c;
        }

        getline(cin, line);
        m.op = line[23];
        if (isdigit(line[25])) {
            m.opVal = stoi(line.substr(25));
        } else {
            m.opVal = -1;
        }

        getline(cin, line);
        m.test = stoi(line.substr(21));

        getline(cin, line);
        m.t = stoi(line.substr(29));

        getline(cin, line);
        m.f = stoi(line.substr(30));

        d.push_back(std::move(m));
        getline(cin, line);
    }

    return d;
}

string solve(const vector<Monkey> &d, const int nrRounds, int divide) {
    vector<int> inspections(d.size());
    vector<queue<long long>> qs;
    qs.reserve(d.size());
    long long mod = 1;

    for (const auto &m: d) {
        queue<long long> q;

        for (const auto &item: m.items) {
            q.push(item);
        }

        qs.push_back(std::move(q));
        mod *= m.test;
    }

    for (int i = 0; i < nrRounds; i++) {
        for (int j = 0; j < d.size(); j++) {
            while (!qs[j].empty()) {
                inspections[j]++;
                long long worry = qs[j].front();
                qs[j].pop();

                auto opVal = d[j].opVal == -1 ? worry : d[j].opVal;
                switch (d[j].op) {
                    case '+':
                        worry += opVal;
                        break;
                    case '*':
                        worry *= opVal;
                        break;
                }

                worry /= divide;
                worry %= mod;

                if (worry % d[j].test == 0) {
                    qs[d[j].t].push(worry);
                } else {
                    qs[d[j].f].push(worry);
                }
            }
        }
    }

    auto max1 = max(inspections[0], inspections[1]), max2 = min(inspections[0], inspections[1]);
    for (int i = 2; i < inspections.size(); i++) {
        if (inspections[i] > max1) {
            max2 = max1;
            max1 = inspections[i];
        } else if (inspections[i] > max2) {
            max2 = inspections[i];
        }
    }

    return to_string(static_cast<long long>(max1) * max2);
}

string partOne(const vector<Monkey> &d) {
    return solve(d, 20, 3);
}

string partTwo(const vector<Monkey> &d) {
    return solve(d, 10000, 1);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
