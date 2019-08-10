#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cladire3.in");
ofstream out("cladire3.out");
int n,m,v[202][202];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>v[i][j];

    for(int j=2;j<=m;++j)
        v[n][j]+=v[n][j-1];
    for(int i=n-1;i>=1;--i)
        v[i][1]+=v[i+1][1];

    for(int i=n-1;i>=1;--i)
        for(int j=2;j<=m;++j){
            if(v[i+1][j]<v[i][j-1])
                v[i][j]+=v[i+1][j];
            else
                v[i][j]+=v[i][j-1];
        }
    out<<v[1][m];
    return 0;
}
