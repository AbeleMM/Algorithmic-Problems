#include <iostream>
#include <fstream>
#define inf 2147483647
using namespace std;
ifstream in("catun.in");
ofstream out("catun.out");
int n,m,k,sol[36001];
struct nod{
    int vecin;
    int cost;
    struct nod *urm;
}*l[36001],*cur;
int viz[36001];
int h[36001],nr;
int d[36001],mn;

void add_h(int nr){
    int poz=nr;
    while(poz>1 && d[h[poz/2]]>d[h[poz]]){
        swap(h[poz/2],h[poz]);
        swap(viz[h[poz/2]],viz[h[poz]]);

        poz/=2;
    }
}

void del_vf(int &nr){
    h[1]=h[nr];
    swap(viz[h[1]],viz[h[nr]]);
    --nr;
    int poz=1;
    while(2*poz<=nr){
        int fiu=2*poz;
        if(fiu+1<=nr && d[h[fiu+1]]<d[h[fiu]])
            ++fiu;
        if(d[h[fiu]]<d[h[poz]]){
            swap(h[poz],h[fiu]);
            swap(viz[h[poz]],viz[h[fiu]]);

            poz=fiu;
        }
        else
            poz=nr+1;
    }
}

void dijkstra(){

    while(nr>0){
        mn=h[1];
        viz[mn]=0;
        del_vf(nr);

        for(cur=l[mn];cur!=NULL;cur=cur->urm){
            if(d[cur->vecin]>d[mn]+cur->cost){
                d[cur->vecin]=d[mn]+cur->cost;
                sol[cur->vecin]=sol[mn];
                if(viz[cur->vecin]==0){
                    ++nr;
                    viz[cur->vecin]=nr;
                    h[nr]=cur->vecin;
                    add_h(nr);
                }
                else
                    add_h(viz[cur->vecin]);
            }
            else if(d[cur->vecin]==d[mn]+cur->cost && sol[cur->vecin]>sol[mn])
                sol[cur->vecin]=sol[mn];
        }
    }
}
int main()
{
    in>>n>>m>>k;
    int a,b,c;
    for(int i=1;i<=n;++i)
        d[i]=inf;
    for(int i=1;i<=k;++i){
        in>>a;
        d[a]=0;
        sol[a]=a;
        ++nr;
        viz[a]=nr;
        h[nr]=a;
        add_h(nr);
    }
    for(int i=1;i<=m;++i){
        in>>a>>b>>c;

        cur=new nod;
        cur->vecin=b;
        cur->cost=c;
        cur->urm=l[a];
        l[a]=cur;

        cur=new nod;
        cur->vecin=a;
        cur->cost=c;
        cur->urm=l[b];
        l[b]=cur;
    }
    dijkstra();
    for(int i=1;i<=n;++i){
        if(sol[i]!=i)
            out<<sol[i]<<" ";
        else
            out<<"0 ";
    }
    return 0;
}
