#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cuburi3.in");
ofstream out("cuburi3.out");
int n;
struct subsir{
    int o;
    int lmx;
}l[4001];
struct cub{
    int l;
    int g;
    int nr;
}v[4001],t;
void qs(int st, int dr){
    int i=st,j=dr,x=v[i+(j-i)/2].g;//x - mij
    do{
        while(i<dr && v[i].g<x)
            ++i;
        while(j>st && v[j].g>x)
            --j;
        if(i<=j){
            t=v[i];
            v[i]=v[j];
            v[j]=t;
            ++i;
            --j;
        }
    }while(i<=j);
    if(st<j)
        qs(st,j);
    if(i<dr)
        qs(i,dr);
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i){
        in>>v[i].l>>v[i].g;
        v[i].nr=i;
    }
    qs(1,n);

    int k=0;
    for(int i=n;i>=1;--i){
        l[i].o=1;
        l[i].lmx=v[i].l;
        for(int j=i+1;j<=n;++j)
            if(l[j].lmx+v[i].l>l[i].lmx && v[i].l<=v[j].l){
                l[i].lmx=l[j].lmx+v[i].l;
                l[i].o=l[j].o+1;
            }
        if(l[i].lmx>l[k].lmx)
            k=i;
    }

    out<<l[k].o<<" "<<l[k].lmx<<"\n";
    int s=l[k].lmx,nr=0,sol[4001];
    for(int i=k;i<=n;++i)
        if(s==l[i].lmx){
            ++nr;
            sol[nr]=v[i].nr;
            s-=v[i].l;
        }

    for(int i=nr;i>=1;--i)
        out<<sol[i]<<"\n";
    return 0;
}
