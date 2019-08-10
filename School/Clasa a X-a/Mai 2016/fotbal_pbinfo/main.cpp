#include <iostream>

using namespace std;
int x,y,m[13][13],i,j;
int main()
{
    cin>>x>>y;
    for(i=0;i<=y;++i)
        m[0][i]=1;
    for(i=0;i<=x;++i)
        m[i][0]=1;
    for(i=1;i<=x;++i)
        for(j=1;j<=y;++j)
            m[i][j]=m[i-1][j]+m[i][j-1];
    cout<<m[x][y];
    return 0;
}
