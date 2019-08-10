#include <iostream>
#include <fstream>
using namespace std;
ifstream in("megapromo.in");
ofstream out("megapromo.out");
int n,m,vm[1000001],vn[1000001],em,en,poz;
long long s;
bool type;
int caut_max_mic(int st,int dr,int x){
    if(st>dr)
        return -1;
    int mj=st+(dr-st)/2;
    if(vn[mj]+x<=s){
        if(vn[mj+1]+x>s)
            return mj;
        else
            return caut_max_mic(mj+1,dr,x);
    }
    else
        return caut_max_mic(st,mj-1,x);
}
int caut_min_mare(int st,int dr, int x){
    if(st>dr)
        return -1;
    int mj=st+(dr-st)/2;
    if(vn[mj]+x>=s){
        if(vn[mj-1]+x<s)
            return mj;
        else
            return caut_min_mare(st,mj-1,x);
    }
    else
        return caut_min_mare(mj+1,dr,x);
}
int main()
{
    in>>s>>m>>n;
    for(int i=1;i<=m;++i)
        in>>vm[i];
    for(int i=1;i<=n;++i)
        in>>vn[i];

    for(int i=1;i<=m;++i){
        poz=caut_max_mic(1,n,vm[i]);
        if(poz!=-1){
            if(s-(vm[i]+vn[poz])<s-(em+en) && type==0)
                em=vm[i],en=vn[poz],type=0;

            if(s-(vm[i]+vn[poz])<(em+en)-s && type==1)
                em=vm[i],en=vn[poz],type=0;
        }

        poz=caut_min_mare(1,n,vm[i]);
        if(poz!=-1){
            if(s-(vm[i]+vn[poz])>s-(em+en) && type==0)
                em=vm[i],en=vn[poz],type=1;
            if(s-(vm[i]+vn[poz])>(em+en)-s && type==1)
                em=vm[i],en=vn[poz],type=1;
        }

    }
    out<<em<<" "<<en;
    out<<"\n";
    if(em+en<s)
        out<<s-(em+en);
    else
        out<<(em+en)-s;
    return 0;
}
