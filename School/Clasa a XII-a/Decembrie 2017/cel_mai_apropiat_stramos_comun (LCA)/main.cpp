//Cel mai mic stramos comun / Lowest Common Ancestor
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lca.in");
ofstream out("lca.out");
int n,m,x,y;
bool viz[100001];
int t;

struct nodLis {
    int vecin;
    struct nodLis *urm;
}*l[100001],*cur;

struct nodArb {
    int inf;
    struct nodArb *st,*dr;
}*rad;

void creare(struct nodArb *&rad, int val) {
    rad = new nodArb;
    rad->inf = val;
    rad->st = rad->dr = NULL;
}

void dfs(struct nodArb *rad, int nod) {
    viz[nod] = true;

    for(struct nodLis *p = l[nod]; p!=NULL; p = p->urm) {
        t = p->vecin;
        if(viz[t] == false){
            if(rad->st == NULL){
                creare(rad->st, t);
                dfs(rad->st, t);
            }
            else if(rad->dr == NULL){
                creare(rad->dr, t);
                dfs(rad->dr, t);
            }
        }
    }
}

int lca(struct nodArb *rad, int nod1, int nod2) {
    if(rad == NULL)
        return 0;

    if(rad->inf == nod1 || rad->inf == nod2)
        return rad->inf;

    int st = lca(rad->st, nod1, nod2);
    int dr = lca (rad->dr, nod1, nod2);

    if(st != 0 and dr != 0)
        return rad->inf;

    if(st == 0 and dr == 0)
        return 0;

    if(st !=0)
        return st;
    else
        return dr;
}

int main()
{
    in>>n>>m;
    // m - numarul de intrebari
    for(int i=2;i<=n;++i){
        in>>x;
        cur = new nodLis;
        cur->vecin = x;
        cur->urm = l[i];
        l[i] = cur;

        cur = new nodLis;
        cur->vecin = i;
        cur->urm = l[x];
        l[x]=cur;
    }

    rad = new nodArb;
    rad->inf = 1;
    rad->st = rad->dr = NULL;

    dfs(rad, 1); // transformar nodLis in nodArb

    for(int i=1;i<=m;++i){
        in>>x>>y;
        out<<lca(rad, x, y)<<"\n";
    }
    return 0;
}
