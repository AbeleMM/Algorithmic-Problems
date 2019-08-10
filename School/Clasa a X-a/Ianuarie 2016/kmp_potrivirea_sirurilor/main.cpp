#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("strmatch.in");
ofstream out("strmatch.out");
int n,m,pi[2000010],k;
int nr,sol[1003];
char t[2000010],p[2000010];
void prefix(){
    for(int i=1;i<=m-1;++i)
    {
        while(k>0 && p[i]!=p[k])
            k=pi[k-1];
        if(p[k]==p[i])
            ++k;
        pi[i]=k;
    }
}
int main()
{
    in>>p>>t;
    n=strlen(t);
    m=strlen(p);
    prefix();
    k=0;
    for(int i=0;i<=n-1;++i){
        while(k>0 && t[i]!=p[k])
            k=pi[k-1];
        if(p[k]==t[i])
            ++k;
        if(k==m){
            nr++;
            if(nr<=1000)
                sol[nr]=i-m+1;
            k=pi[k-1];
        }
    }
    out<<nr<<endl;
    if(nr<=1000)
        for(int i=1;i<=nr;++i)
            out<<sol[i]<<" ";
    else
        for(int i=1;i<=1000;++i)
            out<<sol[i]<<" ";
    return 0;
}
