#include <bits/stdc++.h>

using namespace std;

struct Blueprint {
    int oreBotOreCost, clayBotOreCost,
            obsidianBotOreCost, obsidianBotClayCost,
            geodeBotOreCost, geodeBotObsidianCost;
};

struct Status {
    int t = 1, ore{}, clay{}, obsidian{},
            oreBots = 1, clayBots{}, obsidianBots{}, geodeBots{};
};

int readNr(string &s, const string &tgt) {
    s = s.substr(s.find(tgt) + tgt.size());
    return stoi(s);
}

vector<Blueprint> readIn() {
    string line;
    vector<Blueprint> d;

    while (getline(cin, line) && !line.empty()) {
        d.push_back({readNr(line, "s "), readNr(line, "s "), readNr(line, "s "),
                     readNr(line, "d "), readNr(line, "s "), readNr(line, "d ")});
    }

    return d;
}

int solveBlueprint(const Status &oldS, const Blueprint &bp, const int maxT) {
    if (oldS.t == maxT) {
        return oldS.geodeBots;
    }

    int maxVal = 0;
    Status newS;

    int ttOreBot = ceil(double(bp.oreBotOreCost - oldS.ore) / oldS.oreBots);
    ttOreBot = max(0, ttOreBot) + 1;
    int newT = oldS.t + ttOreBot;
    const bool buildMoreOreBots = oldS.oreBots < max(
            {bp.oreBotOreCost, bp.clayBotOreCost, bp.obsidianBotOreCost, bp.geodeBotOreCost});
    if (newT <= maxT - 1 && buildMoreOreBots) {
        int newOre = oldS.ore + ttOreBot * oldS.oreBots - bp.oreBotOreCost;
        newS = {oldS.t + ttOreBot, newOre, oldS.clay + ttOreBot * oldS.clayBots,
                oldS.obsidian + ttOreBot * oldS.obsidianBots, oldS.oreBots + 1, oldS.clayBots,
                oldS.obsidianBots, oldS.geodeBots};
        maxVal = max(maxVal, ttOreBot * oldS.geodeBots + solveBlueprint(newS, bp, maxT));
    }

    int ttClayBot = ceil(double(bp.clayBotOreCost - oldS.ore) / oldS.oreBots);
    ttClayBot = max(0, ttClayBot) + 1;
    newT = oldS.t + ttClayBot;
    if (newT <= maxT - 2 && oldS.clayBots < bp.obsidianBotClayCost) {
        int newOre = oldS.ore + ttClayBot * oldS.oreBots - bp.clayBotOreCost;
        newS = {newT, newOre, oldS.clay + ttClayBot * oldS.clayBots,
                oldS.obsidian + ttClayBot * oldS.obsidianBots, oldS.oreBots, oldS.clayBots + 1,
                oldS.obsidianBots, oldS.geodeBots};
        maxVal = max(maxVal, ttClayBot * oldS.geodeBots + solveBlueprint(newS, bp, maxT));
    }

    int ttObsidianBot = int(max(
            ceil(double(bp.obsidianBotOreCost - oldS.ore) / oldS.oreBots),
            ceil(double(bp.obsidianBotClayCost - oldS.clay) / oldS.clayBots)));
    ttObsidianBot = max(0, ttObsidianBot) + 1;
    newT = oldS.t + ttObsidianBot;
    if (newT <= maxT - 1 && oldS.clayBots > 0 && oldS.obsidianBots < bp.geodeBotObsidianCost) {
        int newOre = oldS.ore + ttObsidianBot * oldS.oreBots - bp.obsidianBotOreCost;
        int newClay = oldS.clay + ttObsidianBot * oldS.clayBots - bp.obsidianBotClayCost;
        newS = {newT, newOre, newClay,
                oldS.obsidian + ttObsidianBot * oldS.obsidianBots, oldS.oreBots, oldS.clayBots,
                oldS.obsidianBots + 1, oldS.geodeBots};
        maxVal = max(maxVal, ttObsidianBot * oldS.geodeBots + solveBlueprint(newS, bp, maxT));
    }

    int ttGeodeBot = int(max(
            ceil(double(bp.geodeBotOreCost - oldS.ore) / oldS.oreBots),
            ceil(double(bp.geodeBotObsidianCost - oldS.obsidian) / oldS.obsidianBots)));
    ttGeodeBot = max(0, ttGeodeBot) + 1;
    newT = oldS.t + ttGeodeBot;
    if (newT <= maxT && oldS.obsidianBots > 0) {
        int newOre = oldS.ore + ttGeodeBot * oldS.oreBots - bp.geodeBotOreCost;
        int newObsidian = oldS.obsidian + ttGeodeBot * oldS.obsidianBots - bp.geodeBotObsidianCost;
        newS = {newT, newOre, oldS.clay + ttGeodeBot * oldS.clayBots,
                newObsidian, oldS.oreBots, oldS.clayBots,
                oldS.obsidianBots, oldS.geodeBots + 1};
        maxVal = max(maxVal, ttGeodeBot * oldS.geodeBots + solveBlueprint(newS, bp, maxT));
    }

    maxVal = max(maxVal, (maxT - oldS.t + 1) * oldS.geodeBots);

    return maxVal;
}

string partOne(const vector<Blueprint> &d) {
    int res = 0;

    for (int i = 0; i < d.size(); i++) {
        Status status;
        status.t += min(d[i].oreBotOreCost, d[i].clayBotOreCost);
        status.ore = status.t - 1;
        res += (i + 1) * solveBlueprint(status, d[i], 24);
    }

    return to_string(res);
}

string partTwo(const vector<Blueprint> &d) {
    int res = 1;

    for (int i = 0; i < min(size_t(3), d.size()); i++) {
        Status status;
        status.t += min(d[i].oreBotOreCost, d[i].clayBotOreCost);
        status.ore = status.t - 1;
        res *= solveBlueprint(status, d[i], 32);
    }

    return to_string(res);
}

int main() {
    auto d = readIn();
    cout << partOne(d) << endl << partTwo(d) << endl;
    return 0;
}
