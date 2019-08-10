#include <iostream>
#include <fstream>
using namespace std;
ifstream in("comori.in");
ofstream out("comori.out");
int n,m,v[203][203],mx;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>v[i][j];
    for(int i=2;i<=n;++i)
        for(int j=1;j<=m;++j){
                if(v[i-1][j-1]>=v[i-1][j] && v[i-1][j-1]>=v[i-1][j+1])
                    v[i][j]+=v[i-1][j-1];
                else if(v[i-1][j]>=v[i-1][j-1] && v[i-1][j]>=v[i-1][j+1])
                    v[i][j]+=v[i-1][j];
                else if(v[i-1][j+1]>=v[i-1][j-1] && v[i-1][j+1]>=v[i-1][j])
                    v[i][j]+=v[i-1][j+1];
        }
    mx=v[n][1];
    for(int j=2;j<=m;++j)
        if(v[n][j]>mx)
            mx=v[n][j];
    out<<mx;
    return 0;
}
