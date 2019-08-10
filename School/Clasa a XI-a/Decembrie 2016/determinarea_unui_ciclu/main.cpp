//ERATHIA
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
bool mat[101][101];
short int viz[10001];
int n,m;
int p[10001],x,y,nr;
void scrie(int i,int k){
    while(k!=p[i]){
        out<<k<<" ";
        k=p[k];
    }
    /*OLD:
    out<<k<<" ";
    while(k!=i){
        k=p[k];
        out<<k<<" ";
    }*/
}
void df(int k){
    viz[k]=true;
    for(int i=1;i<=n;++i)
        if(mat[k][i]==true){
            if(viz[i]==0){
                p[i]=k;
                df(i);
            }
            else if(i!=p[k] && viz[i]==1){
                scrie(i,k);
                out<<"\n";
                viz[k]=2;
            }
        }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i){
        in>>x>>y;
        mat[x][y]=true;
        mat[y][x]=true;
    }
    df(1);//parcurgere in adancime
    return 0;
}
