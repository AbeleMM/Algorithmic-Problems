#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,x,y,r,h;
bool viz [101];
struct nodLis { // lista vecini ca la oricare alt graf
    int vecin;
    struct nodLis *urm;
}*l[101],*cur;

struct nodArb { // nod arbore
    int inf;
    struct nodArb *st, *dr;
}*rad;

void creare (struct nodArb *&rad, int val) {
    rad = new nodArb;
    rad->inf = val;
    rad->st = rad->dr = NULL;
}

void dfs(struct nodArb *rad, int nod, int niv) {
    if(niv>h)
        h = niv;
    viz[nod] = true;
    for(struct nodLis *p=l[nod]; p!=NULL; p=p->urm) {
        int t = p->vecin;
        if (viz[t] == false) {
            if(rad->st == NULL) {
                creare(rad->st, t);
                dfs(rad->st, t, niv+1);
            }
            else if (rad->dr == NULL) {
                creare(rad->dr, t);
                dfs(rad->dr, t, niv+1);
            }
        }
    }
}

void afis_nivel (struct nodArb *rad, int niv_cur, int niv_caut) {
    if(rad!=NULL) {
        if(niv_cur == niv_caut)
            out<<rad->inf<<" ";
        afis_nivel(rad->st, niv_cur+1, niv_caut);
        afis_nivel(rad->dr, niv_cur+1, niv_caut);
    }
}

int main()
{
    in>>n; // citim numarul de noduri
    for(int i = 1; i < n; ++i) { // citim legaturile
        in>>x>>y;
        cur = new nodLis;
        cur->vecin = y;
        cur->urm = l[x];
        l[x] = cur;

        cur = new nodLis;
        cur->vecin = x;
        cur ->urm = l[y];
        l[y]=cur;
    }

    in>>r; // citim nodul radacina
    // cream radacina separat
    rad = new nodArb;
    rad->inf = r;
    rad->st = rad->dr = NULL;
    // parcurgere in adancime si creare arbore
    dfs(rad, r, 1);

    for(int i = 1; i <= h; ++i) {
        out<<"Nivelul "<<i<<": ";
        afis_nivel(rad, 1, i);
        out<<"\n";
    }
    return 0;
}
