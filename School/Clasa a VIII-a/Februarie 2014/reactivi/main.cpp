#include <iostream>
#include <fstream>
using namespace std;
ifstream in("reactivi.in");
ofstream out("reactivi.out");
int i,j,t,nr,n;
struct reactivi
{
    int tmin,tmax;
}v[8005],aux;
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>v[i].tmin;in>>v[i].tmax;
    }
    for (i=1;i<n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (v[i].tmax>v[j].tmax)
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
    nr=1;
    i=2;
    t=v[1].tmax;
    while (i<=n)
    {
        if (v[i].tmin>t)
        {
            nr=nr+1;
            t=v[i].tmax;
        }
        i++;
    }
    out<<nr;
    return 0;
}
