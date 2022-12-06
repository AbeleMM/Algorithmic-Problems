#include <bits/stdc++.h>

using namespace std;

class Value {
public:
    int val;

    explicit Value(int val) : val(val) {}

    virtual ~Value() = default;
};

class ValueList : public Value {
public:
    vector<shared_ptr<Value>> vec;

    ValueList() : Value(-1) {};

    explicit ValueList(const vector<shared_ptr<Value>> &vec) : Value(-1), vec(vec) {};

    explicit ValueList(int val) : ValueList() { vec.push_back(make_unique<Value>(val)); };
};


pair<unique_ptr<Value>, int> parseSingle(string line) {
    int i = 0;
    while (isdigit(line[i])) {
        i++;
    }
    if (i > 0) {
        return {make_unique<Value>(stoi(line.substr(0, i))), i};
    }
    auto vl = make_unique<ValueList>();
    i += line[i] == '[';
    while (line[i] != ']') {
        auto [val, len] = parseSingle(line.substr(i));
        vl->vec.push_back(std::move(val));
        i += len;
        i += line[i] == ',';
    }
    return {std::move(vl), i + 1};
}

vector<shared_ptr<Value>> readIn() {
    string line;
    vector<shared_ptr<Value>> d;

    while (getline(cin, line) && !line.empty()) {
        auto l = parseSingle(line).first;
        d.push_back(std::move(l));
        getline(cin, line);
        auto r = parseSingle(line).first;
        d.push_back(std::move(r));
        getline(cin, line);
    }

    return d;
}

int compareValues(const shared_ptr<Value> &l, const shared_ptr<Value> &r) {
    const auto lCast = dynamic_pointer_cast<ValueList>(l),
            rCast = dynamic_pointer_cast<ValueList>(r);

    if (lCast == nullptr && rCast == nullptr) {
        return l->val - r->val;
    } else if (lCast != nullptr && rCast != nullptr) {
        for (int i = 0; i < lCast->vec.size() && i < rCast->vec.size(); i++) {
            int compRes = compareValues(lCast->vec[i], rCast->vec[i]);
            if (compRes != 0) {
                return compRes;
            }
        }

        return int(lCast->vec.size() - rCast->vec.size());
    } else if (lCast == nullptr) {
        return compareValues(make_unique<ValueList>(l->val), r);
    } else {
        return compareValues(l, make_unique<ValueList>(r->val));
    }
}

string partOne(const vector<shared_ptr<Value>> &d) {
    int indSum = 0;

    for (int i = 0; i < d.size(); i += 2) {
        indSum += (compareValues(d[i], d[i + 1]) < 0) * (i / 2 + 1);
    }

    return to_string(indSum);
}

string partTwo(const vector<shared_ptr<Value>> &d) {
    vector<shared_ptr<Value>> dExtra(d);
    const auto div2 = make_shared<ValueList>(*make_unique<ValueList>(2)),
            div6 = make_shared<ValueList>(*make_unique<ValueList>(6));
    dExtra.push_back(div2);
    dExtra.push_back(div6);
    sort(dExtra.begin(),
         dExtra.end(),
         [](const shared_ptr<Value> &l, const shared_ptr<Value> &r) {
             return compareValues(l, r) < 0;
         });
    int res = 1, foundCount = 0;

    for (int i = 0; i < dExtra.size() && foundCount < 2; i++) {
        if (compareValues(dExtra[i], div2) == 0 || compareValues(dExtra[i], div6) == 0) {
            res *= i + 1;
            foundCount++;
        }
    }

    return to_string(res);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
