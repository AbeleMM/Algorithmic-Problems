#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cladire1.in");
ofstream out("cladire1.out");
int v[1002][1002],n,m,k;
int a,b;
int main()
{
    in>>n>>m>>k;
    for(int i=1;i<=k;++i)
        in>>a>>b,v[a][b]=-1;
    v[1][1]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(v[i][j]!=-1){
                if(v[i-1][j]!=-1)
                    v[i][j]=(v[i][j]+v[i-1][j])%9901;
                if(v[i][j-1]!=-1)
                    v[i][j]=(v[i][j]+v[i][j-1])%9901;
            }
        }

    /*for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            out<<v[i][j]<<" ";
        out<<endl;
    }*/
    out<<v[n][m];
    return 0;
}
