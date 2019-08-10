#include <iostream>
#include <fstream>
using namespace std;
ifstream in("TIR.IN");
ofstream out ("TIR.OUT");
int a[151][151],i,j,k,nr,p;
int main()
{
    in>>n;
    if (n%2==0)
    {
        k=n/2;
    }
    else
    {
        k=n/2+1;
    }
    for (p=1;p<=k;p++)
    {
        for(j=p;j<=n-p+1;j++)
        {
            a[p][j]=nr;
            nr=nr+1;
        }
        for (i=p+1;i<=n-p+1;i++)
        {
            a[i][n-p+1]=nr;
            nr=nr+1;
        }
        for (j=n-p;j>=p;j--)
        {
            a[n-p+1][j]=nr;
            nr=nr+1;
        }
        for (i=n-p;i>=p+1;i--)
        {
            a[i][p]=nr;
            nr=nr+1;
        }
    }
    return 0;
}
