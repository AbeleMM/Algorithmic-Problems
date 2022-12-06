#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> readIn() {
    string line;
    vector<vector<int>> d;
    vector<int> food;

    while (getline(cin, line) && !(line.empty() && food.empty())) {
        if (line.empty()) {
            d.push_back(std::move(food));
            food.clear();
        } else {
            food.push_back(stoi(line));
        }
    }

    return d;
}

string getTopNSums(const vector<vector<int>> &d, int n) {
    vector<int> foodSums;

    transform(d.cbegin(), d.cend(), back_inserter(foodSums),
              [](const vector<int> &food) { return reduce(food.cbegin(), food.cend()); });
    sort(foodSums.begin(), foodSums.end(), greater<>());

    return to_string(reduce(foodSums.cbegin(), foodSums.cbegin() + n));
}

string partOne(const vector<vector<int>> &d) {
    return getTopNSums(d, 1);
}

string partTwo(const vector<vector<int>> &d) {
    return getTopNSums(d, 3);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
