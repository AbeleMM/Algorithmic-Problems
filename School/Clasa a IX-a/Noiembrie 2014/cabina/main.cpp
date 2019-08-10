#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cabina.in");
ofstream out("cabina.out");
int n,c[44],p[44],nro,consum,nrs;
void citire()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>c[i]>>p[i];
    }
}
void prelucrare()
{
    for (int i=1;i<=n;++i)
    {
        nro=nro+p[i];
        if(c[i]<c[i+1])
        {
            consum=consum+3*(c[i+1]-c[i]);
        }
        if(c[i]>c[i+1])
        {
            consum=consum+c[i]-c[i+1];
        }
        if(c[i]>c[i-1] && c[i]>c[i+1])
        {
            nrs++;
        }
        if(c[i]<c[i-1] && c[i]<c[i+1])
        {
            nrs++;
        }
    }
    consum=consum-c[n];
    if(c[1]>c[0] && c[1]>c[2])
    {
        nrs--;
    }
    if(c[n]>c[n-1] && c[n]>c[n+1])
    {
        nrs--;
    }
}
void afisare()
{
    out<<nro<<"\n"<<consum<<"\n"<<nrs;
}
int main()
{
    citire();
    prelucrare();
    afisare();
    return 0;
}
