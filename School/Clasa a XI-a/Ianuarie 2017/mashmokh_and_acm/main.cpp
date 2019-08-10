#include <iostream>
// http://codeforces.com/blog/entry/11470
// http://codeforces.com/problemset/problem/414/B
using namespace std;
int n,k,m[2001][2001];
int main()
{
    cin>>n>>k;
    for(int j=1;j<=n;++j)
        m[1][j]=1;
    for(int i=1;i<=k)
        m[i][1]=k;
    for(int i=2;i<=k;++i)
        for(int j=2;j<=n;++j)

    /*1...n
    ...
    k
    return 0;
}
