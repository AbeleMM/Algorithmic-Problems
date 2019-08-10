#include <iostream>
#include <fstream>

using namespace std;
ifstream in("dragoni.in");
ofstream out("dragoni.out");
int p, n, m;
int drag[801];
bool viz[801];
struct nod {
    int vecin;
    int dist;
    struct nod *urm;
}*l[801], *cur;
int i, x, y, val;
int dragmax;

void dfs(int nod) {
    if(drag[nod] > dragmax)
        dragmax = drag[nod];
    viz[nod] = true;
    for(struct nod *cur = l[nod]; cur!=NULL; cur=cur->urm){
        if(viz[cur->vecin] == false and cur->dist <= drag[1]){
            dfs(cur->vecin);
        }
    }
}

int main()
{
    in>>p>>n>>m;
    for(i=1; i<=n; ++i)
        in>>drag[i];
    for(i=1; i<=m; ++i) {
        in>>x>>y>>val;

        cur = new nod;
        cur->vecin = y;
        cur->dist = val;
        cur->urm = l[x];
        l[x] = cur;

        cur = new nod;
        cur->vecin = x;
        cur->dist = val;
        cur->urm = l[y];
        l[y] = cur;
    }
    if(p == 1) {
        dfs(1);
        out<<dragmax;
    }
    else if(p == 2) {

    }
    return 0;
}
