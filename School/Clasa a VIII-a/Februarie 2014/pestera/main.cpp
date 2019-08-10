#include <iostream>
#include <fstream>
using namespace std;
ifstream in("PESTERA1.IN");
ofstream out("PESTERA1.OUT");
int n,a[103][103],i,j,S,mn,m,OK,S2;
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            in>>a[i][j];
        }
    }
    for (i=1;i<=n;i++)
    {
        S=0;
        mn=0;
        for (j=1;j<=n;j++)
        {
            S=S+a[i][j];
        }
        if (S>mn)
        {
            mn=S;
            m=i;
            out<<m<<" ";
        }
    }
    out<<"\n";
    OK=0;
    for (i=1;i<=n;i++)
    {
        S2=0;
        for (j=1;j<=n;j++)
        {
            S2=S2+a[i][j];
        }
        if (S2==1)
        {
            out<<i<<" ";
            OK=1;
        }
    }

    if (OK==0)
    {
        out<<"Nu exista.";
    }
    out<<"\n";
    return 0;
}
