#include <bits/stdc++.h>

using namespace std;

struct Node {
    const weak_ptr<Node> parent;
    vector<shared_ptr<Node>> children;
    const string name;
    const bool isDir;
    int size = 0;

    Node(const shared_ptr<Node> &parent, string name, const int size) :
            parent(parent),
            name(std::move(name)),
            isDir(size == 0),
            size(size) {}

    void addChild(shared_ptr<Node> &child) {
        children.push_back(child);
        size += child->size;
        auto node = parent.lock();
        while (node != nullptr) {
            node->size += child->size;
            node = node->parent.lock();
        }
    }
};

shared_ptr<Node> readIn() {
    string line;
    auto d = make_shared<Node>(nullptr, "/", 0);
    auto currentNode = d;

    while (getline(cin, line) && !line.empty()) {
        if (line[0] == '$') {
            if (line.size() > 4) { // cd
                if (line[5] == '/') {
                    currentNode = d;
                } else if (line[5] == line[6] && line[6] == '.') {
                    currentNode = shared_ptr(currentNode->parent);
                } else {
                    for (const auto &child: currentNode->children) {
                        const auto target = line.substr(5);
                        if (child->name == target) {
                            currentNode = child;
                            break;
                        }
                    }
                }
            }
        } else {
            bool isDir = line.substr(0, 3) == "dir";
            auto spaceInd = line.find(' ');
            auto child = make_shared<Node>(currentNode,
                                           isDir ? line.substr(4) : line.substr(spaceInd + 1),
                                           isDir ? 0 : stoi(line.substr(0, spaceInd)));
            currentNode->addChild(child);
        }
    }

    return d;
}

string partOne(const shared_ptr<Node> &d) {
    queue<shared_ptr<Node>> q({d});
    int sum = 0;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node->isDir && node->size <= 100000) {
            sum += node->size;
        }
        for (const auto &child: node->children) {
            q.push(child);
        }
    }

    return to_string(sum);
}

string partTwo(const shared_ptr<Node> &d) {
    queue<shared_ptr<Node>> q({d});
    int size = std::numeric_limits<int>::max(), minFree = d->size - 40000000;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node->isDir && node->size >= minFree & node->size < size) {
            size = node->size;
        }
        for (const auto &child: node->children) {
            q.push(child);
        }
    }

    return to_string(size);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
