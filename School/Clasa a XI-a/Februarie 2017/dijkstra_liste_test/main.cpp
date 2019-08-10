#include <iostream>
#include <fstream>
#define inf 2147483647
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int n,m,mn,x;
long long d[50001];
bool viz[50001],ok=true;

struct nod{
    int vecin;
    int val;
    struct nod *urm;
}*l[50001],*cur;

void dijkstra(int p){
    for(int i=1;i<=n;++i)
        d[i]=inf;
    for(struct nod *cur=l[p];cur!=NULL;cur=cur->urm)
        d[cur->vecin]=cur->val;

    viz[p]=true;
    while(ok==true){
        ok=false;
        mn=inf;
        for(int j=1;j<=n;++j)
            if(viz[j]==false && d[j]<mn){
                mn=d[j];
                x=j;
                ok=true;
            }
        viz[x]=true;
        //cauta printre vecinii nodului extras
        for(struct nod *cur=l[x];cur!=NULL;cur=cur->urm){
            if(viz[cur->vecin]==false && d[cur->vecin]>d[x]+cur->val)
                d[cur->vecin]=d[x]+cur->val;
        }
    }
}

int main()
{
    in>>n>>m;
    int a,b,c;
    for(int i=1;i<=m;++i){
        in>>a>>b>>c;
        cur=new nod;
        cur->vecin=b;
        cur->val=c;
        cur->urm=l[a];
        l[a]=cur;
    }
    dijkstra(1);
    for(int i=2;i<=n;++i){
        if(d[i]!=inf)
            out<<d[i]<<" ";
        else
            out<<"0 ";
    }
    return 0;
}
