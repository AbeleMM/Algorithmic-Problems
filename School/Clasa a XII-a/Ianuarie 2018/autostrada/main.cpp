#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("autostrada.in");
ofstream out("autostrada.out");
int n, m, x, y;
int niv[51]/*nivel*/, p[51]/*parinte*/, nivMin[51]/*nivelul minim la care poate duce urmarirea muchiei*/;

int k;
struct muchie{
    int x, y;
}sol[121];

bool graf[51][51];
bool viz[51];

void dfs(int nod, int it) {
    int i;
    //initiem nivelul minim si nivelul curent cu numarul de ordine al apelului DFS
    nivMin[nod] = niv[nod] = it;
    viz[nod] = true;
    for(i=1; i<=n; i++)
        if(graf[nod][i] == true) {
            //daca i nu e vizitat
            if(viz[i] == false) {
                //setam parintele
                p[i] = nod;
                //parcurgem in adancime pentru i
                dfs(i, it+1);
                //actualizam nivMin al nodului cu nivMin al i (fiului) daca e cazul
                nivMin[nod] = min(nivMin[nod], nivMin[i]);
                //daca nodul nu are o muchie de revenire la un nivel superior
                if(nivMin[i] > niv[nod]){
                    ++k;
                    sol[k].x = min(nod, i);
                    sol[k].y = max(nod, i);
                }
            }
            //daca i nu este parintele nodului - verificam daca trebuie sa actualizam nivMin
            else if (i != p[nod])
                nivMin[nod] = min(nivMin[nod], niv[i]);
        }
}
inline bool crit(muchie a, muchie b) {
    return ((a.x < b.x) or (a.x == b.x and a.y < b.y));
}
int main()
{
    int i;
    in>>n>>m;
    for(i=1; i<=m; i++) {
        in>>x>>y;
        graf[x][y] = graf[y][x] = true;
    }
    //consideram nodul 1 radacina arborelui -> nu are parinte
    p[1] = -1;

    dfs(1, 0);
    out<<k<<"\n";

    //sortam elementele solutiei in ordine lexicografica
    sort(sol+1, sol+k+1, crit);

    for(i=1; i<=k; i++)
        out<<sol[i].x<<" "<<sol[i].y<<"\n";
    return 0;
}
