#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cladire.in");
ofstream out("cladire.out");
int v[1002][1002],n,m;
int main()
{
    in>>n>>m;
    v[1][1]=1;
    for(int j=2;j<=m;++j)
        v[1][j]=1;
    for(int i=2;i<=n;++i)
        v[i][1]=1;
    for(int i=2;i<=n;++i)
        for(int j=2;j<=m;++j)
            v[i][j]=(v[i-1][j]+v[i][j-1])%9901;
    out<<v[n][m];
    return 0;
}
