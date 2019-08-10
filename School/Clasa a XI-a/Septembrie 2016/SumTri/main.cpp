#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sumtri.in");
ofstream out("sumtri.out");
int v[102][102],n,mx;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            in>>v[i][j];
    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j){
            if(v[i-1][j-1]>v[i-1][j])
                v[i][j]+=v[i-1][j-1];
            else
                v[i][j]+=v[i-1][j];
        }
    mx=v[n][1];
    for(int i=2;i<=n;++i)
        if(v[n][i]>mx)
            mx=v[n][i];
    out<<mx;
    return 0;
}
