#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ozn1.in");
ofstream out("ozn1.out");
int n,k,i,j,target,x1,y1,x2,y2,nr,a[20000][20000],mmax,mx,y;
{
    in>>n>>k;
    for (i=1;i<=n;i++)
    {
        in>>x1>>y1>>x2>>y2>>nr;
        if (x2+y2>mmax)
        {
            mmax=x2+y2;
            mx=x2;
            my=y2;
        }
    int a[mx+1][my+1];
    for (i=1;i<=mx+1;i++)
    {
        for (j=1;j<=my+1;j++)
        {

        }
    }
    for (i=1;i<=k;i++)
    {
        out<<target<<"\n";
    }
    return 0;
}
