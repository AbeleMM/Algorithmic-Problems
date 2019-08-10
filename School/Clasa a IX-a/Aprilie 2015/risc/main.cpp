#include <iostream>
#include <fstream>
using namespace std;
ifstream in("risc.in");
ofstream out("risc.out");
int p,n,nr,c,z,ok,s,d,v[10000],t,x;
void p1()
{
    int i;
    for(i=1;i<=n;i++)
    {
        in>>nr;
        if(nr>c)
        {
            c=nr;
            z=i;
        }
    }
    in.close();
    in.open("risc.in");
    ok=1;
    nr=0;
    in>>p>>n;
    i=1;
    while(i<=z && ok==1)
    {
        in>>c;
        if(c<=nr)
            ok=0;
        if(i==z-1)
            s=c;
        nr=c;
        i++;
    }
    i=z+1;
    while(i<=n && ok==1)
    {
        in>>c;
        if(c>=nr)
            ok=0;
        if(i==n)
            d=c;
        nr=c;
        i++;
    }
    if(s>=d)
        ok=0;
    if(ok==1)
        out<<z;
   else
        out<<-1;
}
void p2()
{
    for(int i=1;i<=n;i++)
    {
        in>>nr;
        if(nr>c)
        {
            c=nr;
            z=i;
        }
    }
    in.close();
    in.open("risc.in");
    in>>p>>n;
    for(int i=1;i<=z-z%3;i+=3)
    {
        in>>s>>nr>>d;
        if(s<nr && nr>d)
        {
            ok++;
            v[ok]=nr;
            ++t;
        }
        if(nr==c)
            x=s;
    }
    for(int i=1;i<=z%3;i++)
    {
        s=nr;
        nr=d;
        in>>d;
        if(s<nr && nr<d)
        {
            ok++;
            v[ok]=nr;
            ++t;
        }
        if(nr==c)
            x=s;
    }
    //for(int i=z+1)
    out<<t;
}
int main()
{
    in>>p>>n;
    if(p==1)
        p1();
    if(p==2)
        p2();
    return 0;
}
