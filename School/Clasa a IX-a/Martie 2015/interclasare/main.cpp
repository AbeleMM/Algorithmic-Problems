#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int a[102],b[102],c[205],i,j,l,k,n,m;
int main()
{
    in>>n>>m;
    for(i=1;i<=n;++i)
        in>>a[i];
    for(j=1;j<=m;++j)
        in>>b[j];
    i=1; j=1;
    while(i<=n && j<=m)
    {
        k++;
        if(a[i]<b[j])
        {
           c[k]=a[i];
           i++;
        }
        else
        {
            c[k]=b[j];
            j++;
        }
    }
    if(i==n+1)
    {
        for(i=j;i<=m;++i)
        {
            k++;
            c[k]=b[i];
        }
    }
    if(j==m+1)
    {
        for(j=i;j<=n;++j)
        {
            k++;
            c[k]=a[j];
        }
    }
    for(l=1;l<=k;++l)
    {
        out<<c[l]<<" ";
    }
    return 0;
}
