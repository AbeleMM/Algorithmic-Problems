#include <iostream>
#include <fstream>
using namespace std;
ifstream in("patru.in");
ofstream out("patru.out");
int n,k,v[20000],p[40000],nr,t,p4,s4;
int cauta(int s, int d, int key)
{
    int mj;
    while(s<=d)
    {
        mj=s+(d-s)/2;
        if(key==p[mj])
            return 1;
        if(key<p[mj])
            d=mj-1;
        if(key>p[mj])
            s=mj+1;
    }
    return 0;
}
int main()
{
    int x,y,i,z,val;
    for (x=1;x<=178;x++)
    {
        for(y=x;y<=178;y++)
        {
            val=x*x*x*x+y*y*y*y;
            nr++;
            p[nr]=val;
            z=nr-1;
            while(p[z]>val)
            {
                p[z+1]=p[z];
                z--;
            }
            p[z+1]=val;
        }
    }
    in>>n>>k;
    for(i=1;i<=n;i++)
    {
        in>>v[i];
        if(cauta(1,nr,v[i])==1)
            p4++;
    }
    for(i=1;i<=k;++i)
        t=t+(v[i]%10)*(v[i]%10)*(v[i]%10)*(v[i]%10);
    if(t%10==4)
        s4++;
    i=2;
    while(i<=n-k+1)
    {
        t=t-(v[i-1]%10)*(v[i-1]%10)*(v[i-1]%10)*(v[i-1]%10)+(v[i-1+k]%10)*(v[i-1+k]%10)*(v[i-1+k]%10)*(v[i-1+k]%10);
        if(t%10==4)
            s4++;
        i++;
    }
    out<<p4<<"\n"<<s4;
    return 0;
}
