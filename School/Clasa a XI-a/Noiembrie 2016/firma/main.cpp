#include <iostream>
#include <fstream>
#define inf 655360
using namespace std;
ifstream in("firma.in");
ofstream out("firma.out");
int n,m,c[102][102],val1,val2,val3;
int d[101],mn,x,smn=inf,ialt;
long long sol[101];
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
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
                c[i][j]=inf;
    for(int i=1;i<=m;++i){
        in>>val1>>val2>>val3;
        c[val1][val2]=val3;
        c[val2][val1]=val3;
    }
    dijkstra(1);
    d[1]=0;
    for(int j=1;j<=n;++j)
        sol[1]+=d[j];
    for(int i=2;i<=n;++i){
        for(int j=1;j<=100;++j)
            viz[j]=false;
        dijkstra(i);
        d[i]=0;
        for(int j=1;j<=n;++j)
            sol[i]+=d[j];
    }
    for(int i=1;i<=n;++i)
        if(sol[i]<smn){
            smn=sol[i];
            ialt=i;
        }
    out<<ialt;
    return 0;
}
