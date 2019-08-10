#include <iostream>
#include <fstream>
#define inf 655360
using namespace std;
ifstream in("parc.in");
ofstream out("parc.out");
int n,m,c[102][102],val1,val2,val3,p,cc,v;
int d[101],mn,x,smn=inf,ialt;
bool viz[101];

void dijkstra(int p){
    for(int i=1;i<=n;++i)
        d[i]=c[p][i];
    viz[p]=true;
    for(int i=1;i<=n-1;++i){
        mn=inf;
        for(int j=1;j<=n;++j)
            if(viz[j]==false && mn>d[j]){
                x=j;
                mn=d[j];
            }
        viz[x]=true;
        for(int j=1;j<=n;++j)
            if(viz[j]==false && d[j]>d[x]+c[x][j])
                d[j]=d[x]+c[x][j];
    }
}
int main()
{
    in>>n>>m>>cc;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
                c[i][j]=inf;
    for(int i=1;i<=m;++i){
        in>>val1>>val2>>val3;
        c[val1][val2]=val3;
        c[val2][val1]=val3;
    }
    in>>p;
    in>>v;
    dijkstra(v);
    d[v]=0;
    if(d[cc]<smn){
        ialt=v;
        smn=d[cc];
    }
    for(int i=2;i<=p;++i){
        for(int j=1;j<=100;++j)
            viz[j]=false;
        in>>v;
        dijkstra(v);
        d[v]=0;
        if(d[cc]<smn){
            ialt=v;
            smn=d[cc];
        }
    }
    out<<ialt;
    return 0;
}
