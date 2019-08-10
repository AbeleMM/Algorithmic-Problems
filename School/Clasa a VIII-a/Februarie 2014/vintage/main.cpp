#include <iostream>
#include <fstream>
using namespace std;
ifstream in("vintage.in");
ofstream out("vintage.out");
int n,k,vmax,cmin,ok,aux;
struct masini{
int c;
int v;
int p;
}m[1003];
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;i++)
    {
        in>>m[i].c>>m[i].v;
        m[i].p=i;
    }
    do{
        ok=0;
        for(int i=1;i<n;i++)
        {
            if(m[i].v<m[i+1].v)
            {
                aux=m[i].v;
                m[i].v=m[i+1].v;
                m[i+1].v=aux;
                aux=m[i].c;
                m[i].c=m[i+1].c;
                m[i+1].c=aux;
                aux=m[i].p;
                m[i].p=m[i+1].p;
                m[i+1].p=aux;
                ok=1;
            }
            if(m[i].v==m[i+1].v && m[i].c>m[i+1].c)
            {
                aux=m[i].v;
                m[i].v=m[i+1].v;
                m[i+1].v=aux;
                aux=m[i].c;
                m[i].c=m[i+1].c;
                m[i+1].c=aux;
                aux=m[i].p;
                m[i].p=m[i+1].p;
                m[i+1].p=aux;
                ok=1;
            }
        }
    }while(ok==1);
    for(int i=1;i<=k;i++)
    {
        vmax+=m[i].v;
        cmin+=m[i].c;
    }
    do{
        ok=0;
        for(int i=1;i<k;i++)
            if(m[i].p>m[i+1].p)
            {
                aux=m[i].p;
                m[i].p=m[i+1].p;
                m[i+1].p=aux;
                ok=1;
            }
    }while(ok==1);
    out<<vmax<<" "<<cmin<<"\n";
    for(int i=1;i<=k;i++)
        out<<m[i].p<<" ";
    return 0;
}
