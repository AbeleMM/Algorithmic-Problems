#include <iostream>
#include <fstream>
using namespace std;
ifstream in("betasah.in");
ofstream out ("betasah.out");
int a[101][101],n,d,k,M,P,i,j,nr,mx,x,y,b[101],c[101];
int main()
{
    in>>n>>d>>k;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=i;j++)
        {
            a[i][j]=0;
        }
    }
    for (i=1;i<=d;i++)
    {
        in>>x>>y;
        a[x][y]=1;
        b[i]=x;
        c[i]=y;
    }
    for (i=1;i<=k;i++)
    {
        in>>x>>y;
        a[x][y]=2;
    }
    for (i=1;i<=n;i++)
    {
        nr=0;
        for (j=1;j<=i;j++)
            if (a[i][j]!=2)
            {
                nr=nr+1;
            }
            if(nr>M)
            {
                M=nr;
            }
    }
    out<<M<<"\n";
    for (i=0;i<=n+1;i++)
    {
        a[i][0]=a[n+1][i]=a[0][i]=2;
    }
    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            a[i][j]=2;
        }
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x-1][y]==0 || a[x-1][y]==3)
    {
        x=x-1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x+1][y]==0 || a[x+1][y]==3)
    {
        x=x+1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x][y+1]==0 || a[x][y+1]==3)
    {
        y=y+1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x][y-1]==0 || a[x][y-1]==3)
    {
        y=y-1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x-1][y+1]==0 || a[x-1][y+1]==3)
    {
        x=x-1;
        y=y+1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x+1][y-1]==0 || a[x+1][y-1]==3)
    {
        x=x+1;
        y=y-1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x+1][y+1]==0 || a[x+1][y+1]==3)
    {
        x=x+1;
        y=y+1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    for (i=1;i<=d;i++)
    {
        x=b[i];
        y=c[i];
    }
    while (a[x-1][y-1]==0 || a[x-1][y-1]==3)
    {
        x=x-1;
        y=y-1;
        if (a[x][y]==0)
        {
            P=P+1;
        }
        a[x][y]=3;
    }
    out<<P;
    return 0;
}
