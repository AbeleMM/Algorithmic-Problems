#include <iostream>
#include <fstream>
using namespace std;
ifstream in("roata.in");
ofstream out("roata.out");
long n,p,v[100005],c,nalt,mn,mna;
struct roata
{
    long nr;
    long t;
}r[361];
long long s;
int main()
{
    in>>n>>p;
    mna=100005;
    for(int i=1;i<=p;++i)
    {
        in>>v[i];
        s=s+v[i];
        if(i<=n)
        {
            r[i].nr=i;
            r[i].t=v[i];
            if(r[i].t<mna)
            mna=r[i].t;
        }
    }
    out<<s<<"\n";
    int j;
    if(s/p==v[1] && v[1]==v[p])
    {
        for (j=1;j<=p;j++)
        {
            out<<j<<" ";
        }
        out<<"\n"<<p%n;
    }
    else
    {
        mn=mna;
    while(nalt!=p)
    {
        mna=100005;
        for(j=1;j<=n;j++)
        {
            r[j].t=r[j].t-mn;
            if(r[j].t==0)
            {
                out<<r[j].nr<<" ";
                nalt++;
                r[j].nr=n+nalt;
                r[j].t=v[n+nalt];
                c=j;
            }
            if(r[j].t<mna && r[j].t>0)
                mna=r[j].t;
        }
        mn=mna;
    }
    out<<"\n"<<c;
    }
    return 0;
}
