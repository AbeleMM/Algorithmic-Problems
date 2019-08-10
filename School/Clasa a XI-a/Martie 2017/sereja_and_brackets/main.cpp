#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
char s[1000002],ch;
int m,poz,inc,sf,tsol,osol,csol;
//nr secv corecte + nr paranteze deschise/inchise ce nu se afla in secv corecta
int t[2000002],o[2000002],c[2000002];

inline int mn(int x,int y){
    if(x<y)
        return x;
    return y;
}
void actualiz(int nod,int st,int dr){
    if(st==dr){
        if(ch=='(')
            o[nod]=1;
        else
            c[nod]=1;
    }
    else{
        int mj=(st+dr)/2;
        if(poz<=mj)
            actualiz(2*nod,st,mj);
        else
            actualiz(2*nod+1,mj+1,dr);

        int tmp=mn(o[2*nod],c[2*nod+1]);
        t[nod]=t[2*nod]+t[2*nod+1]+tmp;
        o[nod]=o[2*nod]+o[2*nod+1]-tmp;
        c[nod]=c[2*nod]+c[2*nod+1]-tmp;
    }

}
void interog(int nod, int st, int dr){
    if(inc<=st && dr<=sf){
        tsol+=t[nod];
        csol=c[nod];
        int tmp=mn(osol,csol);
        tsol+=tmp;
        osol-=tmp;
        osol+=o[nod];
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
    in>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;++i){
        poz=i,ch=s[i];
        actualiz(1,1,len);
    }
    in>>m;
    for(int i=1;i<=m;++i){
        in>>inc>>sf;
        tsol=osol=csol=0;
        interog(1,1,len);
        out<<2*tsol<<"\n";
    }
    return 0;
}
