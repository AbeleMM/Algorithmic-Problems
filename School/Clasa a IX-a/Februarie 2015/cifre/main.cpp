#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cifre.in");
ofstream out("cifre.out");
int n,k,nr;
long p;
int t1,t2,t3,t4,e;
void citire()
{
    in>>n>>k>>p;
}
void prelucrare()
{
    t1=1;
    t2=1;
    t3=2;
    if(t1==k)
        nr++;
    if(p==1)
        e=t1;
    if(t2==k)
        nr++;
     if(p==2)
        e=t2;
    if(t3==k)
        nr++;
     if(p==3)
        e=t3;
    int i=4;
    while(i<=n)
    {
        t4=(t1+t2+t3)%10;
        t1=t2;
        t2=t3;
        t3=t4;
        if(t4==k)
            nr++;
        if(i==p)
            e=t4;
        ++i;
    }
    while(i<=p)
    {
        t4=(t1+t2+t3)%10;
        t1=t2;
        t2=t3;
        t3=t4;
        ++i;
    }
    e=t4;
}
void afisare()
{
    out<<nr<<"\n"<<e;
}
int main()
{
    citire();
    prelucrare();
    afisare();
    return 0;
}
