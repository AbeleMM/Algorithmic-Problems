#include <iostream>
#include <fstream>
using namespace std;
ifstream in("bridge.in");
ofstream out("bridge.out");
void qs(int st,int dr,int m[2][1005]){
    int i=st,j=dr,t1,t2;
    int x=m[0][i+(j-i)/2];
    while(i<=j){
        while (i<dr && m[0][i]<x)
            ++i;
        while(j>st && m[0][j]>x)
            --j;
        if(i<=j){
            t1=m[0][i];
            t2=m[1][i];
            m[0][i]=m[0][j];
            m[1][i]=m[1][j];
            m[0][j]=t1;
            m[1][j]=t2;
            ++i;
            --j;
        }
    }
    if(st<j)
        qs(st,j,m);
    if(i<dr)
        qs(i,dr,m);
}
int caut_bin(int st,int dr,int x,int p[1005]){
    int mj=st+(dr-st)/2;
    if(dr<st)
        return -1;
    if(p[mj]>x){
        if(p[mj-1]<=x)
            return mj;
        else
            return caut_bin(st,mj-1,x,p);
    }
    else
        return caut_bin(mj+1,dr,x,p);
}
void scm(int n,int v[1005]){
    int p[1005],nr=0,i;
    nr=1;
    p[1]=v[1];
    for(i=2;i<=n;++i){
        if(v[i]<p[1])
            p[1]=v[i];
        else if(v[i]>=p[nr]){
            ++nr;
            p[nr]=v[i];
        }
        else{
            int poz=caut_bin(1,nr,v[i],p);
            if(poz!=-1)
                p[poz]=v[i];
        }
    }
    out<<nr<<"\n";
}
void rezolvare(){
    int n,m[2][1005];
    in>>n;
    for(int i=1;i<=n;++i)
        in>>m[0][i];
    for(int i=1;i<=n;++i)
        in>>m[1][i];
    qs(1,n,m);
    scm(n,m[1]);
}
int main()
{
    int t;
    in>>t;
    for(int i=1;i<=t;++i)
        rezolvare();
    return 0;
}
