#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cool.in");
ofstream out("cool.out");
int p,N,K,v[5003],mx,mn,s,d[1004],nr,l,lmax;
struct Gigel
{

}
void citire()
{
    int i;
    in>>p>>N>>K;
    if(p==1)
    {
        mn=1001;
        for(i=1;i<=K;++i)
        {
            in>>v[i];
            ++d[v[i]];
            s=s+v[i];
            if(v[i]>mx)
                mx=v[i];
            if(v[i]<mn)
                mn=v[i];
        }
    }
    if(p==2)
        for(i=1;i<=N;++i)
            in>>v[i];
}
void prelucrare_afisare()
{
    if(s==mx*(mx+1)/2-(mn-1)*mn/2)
        out<<mx;
    else
    {
        for(int i=1;i<=mx;++i)
        {
            if(d[i]==1)
                nr++;
        }
        out<<nr;
    }
}
void prelucrare2()
{
    //mn=1; mx=1; d[v[1]]=1;
    //for(int i=2;i<=N;++i)
    {
        //s=d[v[i]];
        //if(s==0 || i-mn>=s)
            //s++;
        //else
        {
            //if (mn>mx)
            {
                //mx=mn;
                //mn=i-s;
            }
        }
        //d[v[i]]=i;
    }
    //if(mn>mx)
        //mx=mn;
    int i=1;
    while(i<=N)
    {
        d[v[i]].r++;
        if(d[v[i]].r==2)
        {
            i=d[v[i]].p+1;
            d[v[i]].r=0;
            mn=0;
            mx=0;
            l=0;
            s=0;
        }
        d[v[i]].p=i;
        s=s+v[i];
        if(v[i]>mx)
            mx=v[i];
        if(v[i]<mn)
            mn=v[i];
        if(s==mx*(mx+1)/2-(mn-1)*mn/2)
            l=mx-mn+1;
        if(l>lmax)
            lmax=l;
        ++i;
    }
}
void afisare2()
{
    out<<lmax<<"\n"<<nr;
}
int main()
{
    citire();
    if(p==1)
    {
        prelucrare_afisare();
    }
    if(p==2)
    {
        prelucrare2();
        afisare2();
    }
    return 0;
}
