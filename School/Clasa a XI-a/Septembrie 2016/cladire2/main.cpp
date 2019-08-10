#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cladire2.in");
ofstream out("cladire2.out");
int v[203][203],n,m;
void fct(int i,int j){
    if(i!=1 || j!=1){
        if(v[i-1][j]>v[i][j-1])
            fct(i-1,j);
        else
            fct(i,j-1);
    }
    out<<i<<" "<<j<<"\n";
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>v[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(v[i-1][j]>v[i][j-1])
                v[i][j]+=v[i-1][j];
            else
                v[i][j]+=v[i][j-1];
        }
    out<<v[n][m]<<"\n";
    fct(n,m);
    return 0;
}
