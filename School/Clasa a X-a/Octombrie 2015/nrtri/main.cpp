#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nrtri.in");
ofstream out("nrtri.out");
int n,v[850],c[30100],u[850],k,nr,mj,a,b;
int caut_bin(int st, int dr)
{
    if(st>dr)
        return -1;
    else{
        mj=st+(dr-st)/2;
        if(u[mj]>a+b)
            caut_bin(st,mj-1);
        else{
            if(mj==dr)
                return mj;
            else{
                if(u[mj+1]>a+b)
                    return mj;
                else
                    return caut_bin(mj+1,dr);
            }
        }
    }
}
int main()
{
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>v[i];
        if(v[i]>k)
            k=v[i];
    }
    for (int i=1;i<=n;i++)
    {
        c[v[i]]=c[v[i]]+1;
    }
    for (int i=1;i<=k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for (int i=1;i<=n;i++)
    {
        u[c[v[i]]-1]=v[i];
        c[v[i]]=c[v[i]]-1;
    }
    for(int i=0;i<n-2;i++)
    {
        a=u[i];
        for(int j=i+1;j<n-1;j++){
            b=u[j];
            mj=caut_bin(j+1,n-1);
            if(mj!=-1)
                nr+=mj-j;
        }
    }
    out<<nr;
    return 0;
}
