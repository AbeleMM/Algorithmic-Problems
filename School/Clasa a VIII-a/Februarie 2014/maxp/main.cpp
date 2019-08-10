#include <iostream>
#include <fstream>
using namespace std;
ifstream in ("maxp.in");
ofstream out ("maxp.out");
int n,i,j,nr,p,pmax,aux;
int v[200005];
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>v[i];
    }
    for (i=1;i<=n;i++)
    {
        p=0;

        while (j>=1;j-- || v[i]>v[j])
        {
            p=p+1;
            j=j-1;
        }
        j=i+1;
        aux=p;
        while (j<=n || v[i]>v[j])
        {
            j=j+1;
            p=p+int;
        }
        if(p>pmax)
        {
            pmax=p;
            nr=1;
        }
        if (p==pmax)
        {
            nr=nr+1;
        }
    }
    out<<p<<"\n"<<nr;
    return 0;
}
