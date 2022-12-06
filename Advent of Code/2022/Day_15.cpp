#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pos;

int readCoord(string &s) {
    s = s.substr(s.find('=') + 1);
    return stoi(s);
}

map<pos, pos> readIn() {
    string line;
    map<pos, pos> d;

    while (getline(cin, line) && !line.empty()) {
        d.insert({{readCoord(line), readCoord(line)},
                  {readCoord(line), readCoord(line)}});
    }

    return d;
}

inline int getOverlap(const pos &x, const pos &y) {
    return min(x.second, y.second) - max(x.first, y.first);
}

string partOne(const map<pos, pos> &d) {
    const int tgtY = 2000000;

    vector<pos> seg;
    seg.reserve(d.size());

    for (const auto &[k, v]: d) {
        int slack = abs(k.first - v.first) + abs(k.second - v.second) - abs(k.second - tgtY);
        if (slack >= 0) {
            int l = k.first - slack, r = k.first + slack;
            if (slack > 0 || v.second != tgtY) {
                l += v.first == l;
                r -= v.first == r;
                seg.emplace_back(l, r);
            }
        }
    }

    sort(seg.begin(), seg.end());
    int i = 0, nrCovered = 0;
    while (i < seg.size()) {
        auto chunk = seg[i];
        while (i + 1 < seg.size() && getOverlap(chunk, seg[i + 1]) >= 0) {
            chunk.second = max(chunk.second, seg[++i].second);
        }
        nrCovered += chunk.second - chunk.first + 1;
        i++;
    }

    return to_string(nrCovered);
}

string partTwo(const map<pos, pos> &d) {
    const int limLwr = 0, limUpr = 4000000;

    vector<vector<pos>> segLines(limUpr - limLwr + 1);
    long long res = limUpr;

    for (const auto &[k, v]: d) {
        int md = abs(k.first - v.first) + abs(k.second - v.second);
        for (int n = 0; n <= md; n++) {
            int slack = md - n;
            pos p = {clamp(k.first - slack, limLwr, limUpr),
                     clamp(k.first + slack, limLwr, limUpr)};
            int l = k.second - n, r = k.second + n;
            if (l >= limLwr && l <= limUpr) {
                segLines[l - limLwr].emplace_back(p);
            }
            if (r >= limLwr && r <= limUpr && l != r) {
                segLines[r - limLwr].emplace_back(p);
            }
        }
    }

    for (int i = 0; i < segLines.size(); i++) {
        auto &segLine = segLines[i];
        sort(segLine.begin(), segLine.end());
        int xMx = segLine[0].second, y = limLwr + i;

        if (segLine[0].first == limLwr + 1 && d.find({limLwr, y}) == d.cend()) {
            res = res * limLwr + y;
            return to_string(res);
        }

        int j = 1;
        while (j < segLine.size() && segLine[j].first - 1 <= xMx) {
            xMx = max(xMx, segLine[j++].second);
        }

        if (xMx < limUpr && d.find({xMx + 1, y}) == d.cend()) {
            res = res * (xMx + 1) + y;
            return to_string(res);
        }
    }

    return "-1";
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
