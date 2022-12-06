#include <bits/stdc++.h>

using namespace std;

struct Move {
    const int n, o, d;

    Move(const int n, const int o, const int d) : n(n), o(o), d(d) {}
};

pair<vector<deque<char>>, vector<Move>> readIn() {
    string s;
    string line;
    pair<vector<deque<char>>, vector<Move>> d;

    // Assumes single-digit stack numbers
    getline(cin, line);
    d.first = vector<deque<char>>((line.size() > 2) + (line.size() - 3) / 4);

    while (!isdigit(line[1])) {
        for (int i = 0; i < d.first.size(); i++) {
            char c = line[1 + i * 4];
            if (c != ' ') {
                d.first[i].push_front(c);
            }
        }

        getline(cin, line);
    }
    getline(cin, line);

    while (getline(cin, line) && !line.empty()) {
        istringstream lineStream(line);
        int n, orig, dest;
        lineStream >> s >> n >> s >> orig >> s >> dest;
        orig--;
        dest--;
        d.second.emplace_back(n, orig, dest);
    }

    return d;
}

string execMoves(const pair<vector<deque<char>>, vector<Move>> &d, bool aux) {
    string res;
    vector<stack<char>> stacks;
    stack<char> auxStack, *stackPointer;

    for (const auto &deq: d.first) {
        stacks.emplace_back(deq);
    }

    for (const auto &move: d.second) {
        stackPointer = aux ? &auxStack : &stacks[move.d];
        for (int i = 0; i < move.n; i++) {
            stackPointer->push(stacks[move.o].top());
            stacks[move.o].pop();
        }
        for (int i = 0; i < move.n && aux; i++) {
            stacks[move.d].push(auxStack.top());
            auxStack.pop();
        }
    }

    for (const auto &stack: stacks) {
        res += stack.top();
    }

    return res;
}

string partOne(const pair<vector<deque<char>>, vector<Move>> &d) {
    return execMoves(d, false);
}

string partTwo(const pair<vector<deque<char>>, vector<Move>> &d) {
    return execMoves(d, true);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
