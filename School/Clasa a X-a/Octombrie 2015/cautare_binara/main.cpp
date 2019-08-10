#include <iostream>
using namespace std;
int n,m,v1[25005],v2,mj;
int cautare(int st,int dr)
{
    if(st>dr)
        return 0;
    mj=st+(dr-st)/2;
    if(v2>v1[mj])
        return cautare(mj+1,dr);
    if(v2<v1[mj])
        return cautare(st,mj-1);
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>v2;
        cout<<cautare(1,n)<<" ";
    }
    return 0;
}
