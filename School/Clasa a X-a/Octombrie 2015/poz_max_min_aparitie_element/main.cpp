#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cautbin.in");
ofstream out("cautbin.out");
int n,v[100100],mj,x,nr,a;
int cautare_poz_max(int st, int dr){
    if(st>dr)
        return -1;
    mj=st+(dr-st)/2;
    if(x>v[mj])
        return cautare_poz_max(mj+1,dr);
    if(x<v[mj])
        return cautare_poz_max(st,mj-1);
    if(x==v[mj]){
        if(mj==dr)
            return mj;
        else
        {
            if(v[mj+1]>x)
                return mj;
            else
                return cautare_poz_max(mj+1,dr);
        }
    }
}
int cautare_poz_ante_min(int st, int dr){
    mj=st+(dr-st)/2;
    if(v[mj]>x)
        return cautare_poz_ante_min(st,mj-1);
    else{
        if(mj==dr)
            return mj;
        else
        {
            if(v[mj+1]>x)
                return mj;
            else
                return cautare_poz_ante_min(mj+1,dr);
        }

    }
}
int cautare_poz_post_max(int st,int dr){
    mj=st+(dr-st)/2;
    if(v[mj]<x)
        return cautare_poz_ante_min(mj+1,dr);
    else{
        if(mj==st)
            return mj;
        else
        {
            if(v[mj-1]<x)
                return mj;
            else
                return cautare_poz_ante_min(st,mj-1);
        }
    }
}
int main()
{
    in>>n;
    for(int i=1;i<=n;i++)
        in>>v[i];
    in>>nr;
    for(int i=1;i<=nr;i++)
    {
        in>>a>>x;
        if(a==0)
            out<<cautare_poz_max(1,n)<<"\n";
        if(a==1)
            out<<cautare_poz_ante_min(1,n)<<"\n";
        if(a==2)
            out<<cautare_poz_post_max(1,n)<<"\n";
    }
    return 0;
}
