#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,a[101][101],i,j;
int main()
{
    in>>n>>m;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
       {
           in>>a[i][j];
       }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            out<<a[i][j]<<" ";
        }
        out<<"\n";
    }
    return 0;
}
