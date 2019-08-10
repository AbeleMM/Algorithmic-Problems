#include <iostream>
#include <fstream>
using namespace std;
ifstream in("forcoding.in");
ofstream out("forcoding.out");
int n,v[10003],fin[10003],mx,smax=0,s;
struct lim{
    int l;
    int r;
}alt[10003];
int build(int i){
    int salt,saltm=0,j;
    for(j=1;j<=i-1-alt[i].l;++j){
        salt=build(j);
        if(salt>saltm)
            saltm=salt;
    }
    for(j=i+1+alt[i].r;j<=n;++j){
        salt=build(j);
        if(salt>saltm)
            saltm=salt;
    }
    return v[i]+saltm;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>v[i];
    for(int i=1;i<=n;++i)
        in>>alt[i].l;
    for(int i=1;i<=n;++i)
        in>>alt[i].r;
    for(int i=1;i<=n;++i){
        s=build(i);
        if(s>smax)
            smax=s;
    }
    out<<smax;
    return 0;
}
