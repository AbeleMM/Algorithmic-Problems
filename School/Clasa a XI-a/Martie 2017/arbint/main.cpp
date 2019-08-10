#include <iostream>
#include <fstream>
using namespace std;
ifstream in("arbint.in");
ofstream out("arbint.out");
int n,m,arb/*ore*/[400001],x,a,b;
int poz,val;
int mx,inc,sf;
inline int val_max(int a, int b){
    if(a>b)
        return a;
    return b;
}
void actualiz/*are*/(int nod, int st, int dr){
    if(st==dr)
        arb[nod]=val;
    else{
        int mj=(st+dr)/2;
        if(poz<=mj)
            actualiz(2*nod,st,mj);
        else
            actualiz(2*nod+1,mj+1,dr);
        arb[nod]=val_max(arb[2*nod],arb[2*nod+1]);
    }
}
void interog/*are*/(int nod, int st, int dr){
    if(inc<=st && dr<=sf){
        if(mx<arb[nod])
            mx=arb[nod];
    }
    else{
        int mj=(st+dr)/2;
        if(inc<=mj)
            interog(2*nod,st,mj);
        if(mj+1<=sf)
            interog(2*nod+1,mj+1,dr);
    }

}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i){
        in>>x;
        poz=i,val=x;
        actualiz(1,1,n);
    }
    for(int i=1;i<=m;++i){
        in>>x>>a>>b;
        if(x==0){
            mx=-1,inc=a,sf=b;
            interog(1,1,n);
            out<<mx<<"\n";
        }
        else{
            poz=a,val=b;
            actualiz(1,1,n);
        }
    }
    return 0;
}
