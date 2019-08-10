#include <iostream>
#include <fstream>
using namespace std;
ifstream in("taxe.in");
ofstream out("taxe.out");
int n,m,v[203][203],mn;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>v[i][j];
    for(int i=0;i<=n+1;++i)
        v[i][0]=201,v[i][m+1]=201;
    for(int j=0;j<=m+1;++j)
        v[0][j]=201,v[n+1][j]=201;
    for(int j=2;j<=m;++j)
        for(int i=1;i<=n;++i){
                if(v[i-1][j-1]<=v[i][j-1] && v[i-1][j-1]<=v[i+1][j-1] /*&& v[i-1][j-1]!=0*/)
                    v[i][j]+=v[i-1][j-1];
                else if(v[i][j-1]<=v[i-1][j-1] && v[i][j-1]<=v[i+1][j-1] /*&& v[i][j-1]!=0*/)
                    v[i][j]+=v[i][j-1];
                else if(v[i+1][j-1]<=v[i-1][j-1] && v[i+1][j-1]<=v[i][j-1] /*&& v[i+1][j-1]!=0*/)
                    v[i][j]+=v[i+1][j-1];
        }
    mn=v[1][m];
    for(int i=2;i<=n;++i)
        if(v[i][m]<mn)
            mn=v[i][m];
    /*for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
                out<<v[i][j]<<" ";
        out<<endl;
    }*/
    out<<mn;
    return 0;
}
