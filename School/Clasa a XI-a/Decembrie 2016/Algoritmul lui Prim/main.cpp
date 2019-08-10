//algoritmul lui prim
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("apm.in");
ofstream out("apm.out");
int n,m,s;
struct nod{
    int vecin;
    int cost;
    struct nod *urm;
}*l[200001],*q;

int d[200001];

int pozitii[200001];

struct heap{
    int nod;
    int t;
}h[200001],auxh;
int nr;

struct fin{
    int x;
    int y;
}sol[200001];
int nalt;

void add_h(int nr){
    int poz=nr;
    while(poz>1 && d[poz/2]>d[poz]){
        auxh=h[poz/2];
        h[poz/2]=h[poz];
        h[poz]=auxh;

        int aux=pozitii[h[poz/2].nod];
        pozitii[h[poz/2].nod]=pozitii[h[poz].nod];
        pozitii[h[poz].nod]=aux;

        aux=d[poz/2];
        d[poz/2]=d[poz];
        d[poz]=aux;

        poz/=2;

    }
}
void del_vf(int &nr){
    h[1]=h[nr];
    pozitii[h[1].nod]=1;
    d[1]=d[nr];
    --nr;

    int poz=1;
    while(2*poz<=nr){
        int fiu=2*poz;
        if(fiu<=nr && d[fiu+1]<d[fiu])
            ++fiu;
        if(d[fiu]<d[poz]){
            auxh=h[poz];
            h[poz]=h[fiu];
            h[fiu]=auxh;

            int aux=pozitii[h[poz].nod];
            pozitii[h[poz].nod]=pozitii[h[fiu].nod];
            pozitii[h[fiu].nod]=aux;

            aux=d[poz];
            d[poz]=d[fiu];
            d[fiu]=aux;
        }
        else
            poz=nr;
    }
}
void prim(int inc){
    pozitii[inc]=-1;
    q=l[inc];
    while(q!=NULL){
        ++nr;
        h[nr].nod=q->vecin;
        h[nr].t=1;
        pozitii[h[nr].nod]=nr;
        d[nr]=q->cost;
        add_h(nr);

        q=q->urm;
    }

    while(nr>0){
        int mn=h[1].nod;
        s+=d[1];
        pozitii[h[1].nod]=-1;
        d[1]=0;

        ++nalt;
        sol[nalt].x=h[1].t;
        sol[nalt].y=h[1].nod;
        del_vf(nr);

        q=l[mn];
        while(q!=NULL){
            if(pozitii[q->vecin]==0){
                ++nr;
                h[nr].nod=q->vecin;
                h[nr].t=mn;
                pozitii[h[nr].nod]=nr;
                d[nr]=q->cost;
                add_h(nr);
            }
            else if(pozitii[q->vecin]!=-1){
                if(d[pozitii[q->vecin]]>q->cost){
                    d[pozitii[q->vecin]]=q->cost;
                    h[pozitii[q->vecin]].t=mn;
                }
                add_h(nr);
            }
            q=q->urm;
        }
    }
}
int main()
{
    in>>n>>m;
    int a,b,c;
    for(int i=1;i<=m;++i){
        in>>a>>b>>c;
        q=new nod;
        q->vecin=b;
        q->cost=c;
        q->urm=l[a];
        l[a]=q;

        q=new nod;
        q->vecin=a;
        q->cost=c;
        q->urm=l[b];
        l[b]=q;
    }
    prim(1);
    out<<s<<"\n"<<nalt<<"\n";
    for(int i=1;i<=nalt;++i)
        out<<sol[i].x<<" "<<sol[i].y<<"\n";
    return 0;
}
