#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,a[99][99],i,j,S,S2;
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
        out<<a[i][i]<<" ";
    }
    out<<"\n";
    for (i=1;i<=n;i++)
    {
        out<<a[i][n+1-i]<<" ";
    }
    out<<"\n";
    S=0;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i+j<n+1)
            {
                S=S+a[i][j];
            }
            if (i+j>n+1 && i<j)
            {
                S2=S2+a[i][j];
            }
        }
    }
    out<<S;
    out<<"\n";
    out<<S2;
    return 0;
}
