#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cladire5.in");
ofstream out("cladire5.out");
int v[203][203],n,m,s;
int main()
{
    in>>n>>m>>s;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>v[i][j];

    for(int j=m-1;j>=1;--j)
        v[1][j]+=v[1][j+1];
    for(int i=2;i<=n;++i)
        v[i][m]+=v[i-1][m];

    for(int i=2;i<=n;++i)
        for(int j=m-1;j>=1;--j){
            if(v[i-1][j]<v[i][j+1])
                v[i][j]+=v[i-1][j];
            else
                v[i][j]+=v[i][j+1];
        }
    out<<s-v[n][1];
    return 0;
}
