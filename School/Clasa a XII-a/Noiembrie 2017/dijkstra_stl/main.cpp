#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#define inf 2147483647
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
int n,m;
priority_queue< pair < int,int > , vector< pair< int,int > >, greater< pair < int,int > > >pq;
struct graf{
    int vecin;
    int cost;
    struct graf *urm;
}*l[250003],*actual;
int d[50005];
void dijkstra(int p)
{
    int node;
    for(int i=1;i<=n;i++)
        d[i] = inf;
    d[p]=0;
    pq.push(make_pair(0, p));

    while(pq.empty()==false)
    {
        node=pq.top().second;
        pq.pop();
        struct graf *t;
        for(t=l[node];t!=NULL;t=t->urm)
        {
            if(d[node]+t->cost<d[t->vecin])
            {
                d[t->vecin]=d[node]+t->cost;
                pq.push(make_pair(d[t->vecin],t->vecin));
            }
        }
    }
}
int main()
{
    int x, y, c;
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y>>c;
        actual=new graf;
        actual->vecin=y;
        actual->cost=c;
        actual->urm=l[x];
        l[x]=actual;
    }

    dijkstra(1);

    for(int i=2;i<=n;i++){
        if(d[i] != inf)
            g<<d[i]<<" ";
        else
            g<<"0 ";
    }

    return 0;
}
