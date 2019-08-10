#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,i,j,S,a[38][38],mx,ml;
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
    mx=-11;
    for (i=1;i<=n;i++)
    {
        S=0;
        for (j=1;j<=m;j++)
        {
            S=S+a[i][j];
        }
        out<<S<<"\n";
        if (S>mx)
        {
            mx=S;
            ml=i;
        }
    }
    out<<ml;
    return 0;
}
