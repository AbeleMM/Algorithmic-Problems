#include <iostream>
#include <fstream>
using namespace std;
ifstream in("transport.in");
ofstream out("transport.out");
int n,k,v[16010];
long s,mx;
int nT(long a)
{
    int nr=0,x=0;
    for(int i=1;i<=n;i++)
    {
        if(x+v[i]<=a)
            x+=v[i];
        else
        {
            x=v[i],nr++;
        }
    }
    nr++;
    return nr;
}
int cautare(long st, long dr)
{
    long mj=st+(dr-st)/2;
    if(nT(mj)>k)
        return cautare(mj+1,dr);
    else{
        if(mj==st)
            return mj;
        else{
            if(nT(mj-1)>k)
                return mj;
            else
                return cautare(st,mj-1);
        }
    }
}
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;i++){
        in>>v[i];
        s+=v[i];
        if(v[i]>mx)
            mx=v[i];
    }
    out<<cautare(mx,s);
    return 0;
}
