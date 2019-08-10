#include <iostream>
#include <fstream>
#define inf 250001
using namespace std;
ifstream in("lanterna.in");
ofstream out("lanterna.out");

int n, m, k, mj, distMj, wattMax, mnD, mnL, x;
bool prieten[51], viz[51], ok;

struct baza {
    int timp;
    int watt;
} graf[51][51], d[51];

void dijkstra(int wattCur) {
    int i, temp;
    for(i = 1; i<=n; i++)
        d[i].timp = graf[1][i].timp, d[i].watt = graf[1][i].watt, viz[i] = false;
    viz[1] = ok = true;
    wattCur = wattMax = 0;

    while(ok == true and wattMax <= wattCur) {
        mnD = mnL = inf;
        ok = false;
        for(i=1; i<=n; i++)
            if(viz[i] == false) {
                if((mnD > d[i].timp) or (mnD == d[i].timp and mnL > d[i].watt)) {
                    x = i, mnD = d[i].timp, mnL = d[i].watt, ok = true;
                }
            }
        viz[x] = true;
        for(i=1; i<=n; i++)
            if(viz[i] == false) {

                if((d[i].timp > d[x].timp + graf[x][i].timp) or ((d[i].timp == d[x].timp + graf[x][i].timp) and (d[i].watt > d[x].watt + graf[x][i].watt))){
                    d[i].timp = d[x].timp + graf[x][i].timp;
                    d[i].watt = d[x].watt + graf[x][i].watt;

                    if(d[i].watt>wattMax)
                        wattMax = d[i].watt;
                }
            }
    }
}

void cautare(int st, int dr) {
    mj = st + (dr-st)/2;
    if(st <= dr) {
        dijkstra(mj);
        if(d[n] == inf)
            cautare(mj+1, dr);
        else {
            dijkstra(mj-1);
            if(d[n] == inf)
                out<<distMj<<" "<<mj;
            else
                cautare(st, mj-1);
        }
    }
}

int main()
{
    int i, j, x, y;
    in>>n>>k;
    for(i=1; i<=n; i++)
        in>>prieten[i];
    in>>m;

    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
                if(i != j)
                    graf[i][j].timp = graf[i][j].watt = inf;

    for(i=1; i<=m; i++) {
        in>>x>>y;
        in>>graf[x][y].timp>>graf[x][y].watt;
        graf[x][y]. watt *= (!prieten[y]);
        graf[y][x].timp = graf[x][y].timp;
        graf[y][x].watt = graf[x][y].watt;
    }

    //cautare(1, k);
    dijkstra(6);
    out<<d[n];
    return 0;
}
