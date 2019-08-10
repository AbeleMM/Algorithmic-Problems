#include <iostream>
#include <fstream>
using namespace std;
ifstream in("datematrice.in");
ofstream out("datematrice.out");
int n,val,i,j,t,u,S;
int a[199][199];
int main()
{
    in>>n>>val;
    for (i=1;i<=n;i++)
    {
        a[1][i]=val;
    }
    for (i=1;i<=n;i++)
    {
        a[i][1]=val;
    }
    for (i=2;i<=n;i++)
    {
        for (j=2;j<=n;j++)
        {
            a[i][j]=a[i][j-1]+a[i-1][j];
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            out<<a[i][j]<<" ";
        }
        out<<"\n";
    }
    out<<"\n";
    for (i=2;i<=n;i++)
    {
        for(j=2;j<=n;j++)
        {
            S=0;
            for(t=1;t<=i-1;t++)
            {
                for (u=1;u<=j-1;u++)
                {
                    S=S+a[t][u];
                }
            }
            a[i][j]=S;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            out<<a[i][j]<<" ";
        }
        out<<"\n";
    }
    return 0;
}
