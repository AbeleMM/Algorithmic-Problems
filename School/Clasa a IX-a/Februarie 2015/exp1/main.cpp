#include <iostream>
#include <fstream>
using namespace std;
ifstream in("exp1.in");
ofstream out("exp1.out");
int m,n,v[5002],ok,nr,mx;
struct descompunere
{
    int f;
    int p;
}d[30003];
void citire()
{
    in>>m>>n;
    int i;
    for(i=1;i<=n;++i)
    {
        in>>v[i];
         if(v[i]>mx)
        {
            mx=v[i];
        }
    }
}
void ciur()
{
    int i,j;
    for(i=3;i*i<=mx;i+=2)
    {
        if(d[i].f==0)
        {
            for(j=3;j<=mx/i;j+=2)
            {
                d[j*i].f=1;
            }
        }
    }

}
void prelucrare()
{
    int i,j;
    for(i=1;i<=n;++i)
    {
        while(v[i]>1)
        {
            if(d[2].f==0)
                {
                    while(v[i]%2==0)
                    {
                        d[2].p++;
                        v[i]=v[i]/2;
                    }
                }
            for(j=3;j<=mx;j+=2)
            {
                if(d[j].f==0)
                {
                    while(v[i]%j==0)
                    {
                        d[j].p++;
                        v[i]=v[i]/j;
                    }
                }
            }
        }
    }
    if(d[2].p>0 && d[2].p%m==0)
            ok=1;
        if(d[2].p>0 && d[2].p%m==!0)
            ok=0;
    for(i=3;i<=mx;i+=2)
    {
        if(d[i].p>0 && d[i].p%m==0)
            ok=1;
        if(d[i].p>0 && d[i].p%m==!0)
            ok=0;
    }
}
void afisare()
{
    int i;
    if(ok==0)
        out<<ok;
    if(ok==1)
    {
        out<<ok<<"\n";
        if(d[2].p>0)
            out<<2<<" "<<d[2].p/m<<"\n";
        for(i=3;i<=mx;i+=2)
            if(d[i].p>0)
            out<<i<<" "<<d[i].p/m<<"\n";
    }
}
int main()
{
    citire();
    ciur();
    prelucrare();
    afisare();
    return 0;
}
