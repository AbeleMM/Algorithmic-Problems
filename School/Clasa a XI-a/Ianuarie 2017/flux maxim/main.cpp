#include <iostream>
#include <fstream>
using namespace std;
ifstream in("maxflow.in");
ofstream out("maxflow.out");
int n,m,flow;
struct nod{
    int vecin;
    struct nod *urm;
}*l[1001],*q;//graf
bool viz[1001];
int c[1001][1001];//matricea costurilor
int p/*arinti*/[1001],coada/*pt. parcurgere latime*/[1001];

inline int mn(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

void actualizare(int st, int dt){
    int mini=2147483647;
    //stabilesc valoarea minima a fluxului pe drumul gasit
    int aux=dt;
    while(aux>st){
        mini=mn(mini,c[p[aux]][aux]);
        aux=p[aux];//parcurg din parinte in parinte
    }
    flow+=mini;
    //actualizez matricea costurilor
    aux=dt;
    while(aux>st){
        c[p[aux]][aux]-=mini;//scad din fluxul disponibil cat am folosit pentru drumul curent
        c[aux][p[aux]]+=mini;//adaug fluxul folosit in drumul rezidual
        aux=p[aux];
    }
}

bool bfs(int st, int dt){// parametri - start si destinatie
    for(int i=1;i<=n;++i)
        viz[i]=false;

    int inc=1,sf=1,noda;
    coada[sf]=st;
    viz[st]=true;
    bool ok=false;

    while(inc<=sf){
        noda=coada[inc];
        for(struct nod *q=l[noda];q!=NULL;q=q->urm){
            if(viz[q->vecin]==false && c[noda][q->vecin]>0){//daca nod vecin nevizitat & muchie formata nesaturata
                p[q->vecin]=noda;
                if(q->vecin==dt){//daca vecin=destinatie
                    actualizare(st,dt);
                    ok=true;//marchez ca am gasit drum
                }
                else{//altfel adaug in coada
                    ++sf;
                    coada[sf]=q->vecin;
                    viz[q->vecin]=true;
                }
            }
        }
        ++inc;
    }
    return ok;
}
int main()
{
    in>>n>>m;
    int a,b,val;
    for(int i=1;i<=m;++i){
        in>>a>>b>>val;
        c[a][b]=val;

        q=new nod;
        q->vecin=b;
        q->urm=l[a];
        l[a]=q;

        q=new nod;
        q->vecin=a;
        q->urm=l[b];
        l[b]=q;
    }
    while(bfs(1,n)==true){}
    out<<flow;
    return 0;
}
