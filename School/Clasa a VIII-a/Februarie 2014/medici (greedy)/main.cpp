#include <iostream>
#include <fstream>
using namespace std;
ifstream in("medici.in");
ofstream out("medici.out");
int n,i,j,aux;
struct medici
    {
        int hi,hs,ord;
    }v[1005],aux,sol[1005];
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>v[i].hi;
    }
    for (j=1;j<=n;j++)
    {
        in>>v[j].hs;
    }
    for (i=1;i<=h-1;i++)
    {
        for (j=1;j<n;j++)
        {
            if (v[i].hs>v[j].hs)
            {
                aux=v[i];
                v[j=v[i];
                v[j]=aux;
            }
        }
    }
    nr=1;
    sol[1]=v[1];
    t=v[1].hs;
    i=2;
    while (i<=n)
    {
        if (v[i].hi>=t)
        {
            nr=nr+1;
            sol[nr]=v[i];
            t=v[i].hs;
        }
        i=i+1;
    }

    return 0;
}
