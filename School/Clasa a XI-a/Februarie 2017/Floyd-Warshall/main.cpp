#include <iostream>
#include <fstream>
#define inf 1001
using namespace std;
ifstream in("royfloyd.in");
ofstream out("royfloyd.out");
int dist[101][101],n;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            in>>dist[i][j];
            if(dist[i][j]==0 && i!=j)//nu avem dist de la i la j
                dist[i][j]=inf;
        }
    for(int k=1;k<=n;++k){//luam k drept nod intermediar
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(dist[i][j]>dist[i][k]+dist[k][j] /*&& dist[i][k]!=inf && dist[k][j]!=inf && i!=k && j!=k*/)//daca dist de la i la j prin k este mai mica
                    dist[i][j]=dist[i][k]+dist[k][j];//actualizam
    }
    //afisare
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(dist[i][j]==inf)
                out<<"0 ";
            else
                out<<dist[i][j]<<" ";
        }
        out<<"\n";
    }
    return 0;
}
