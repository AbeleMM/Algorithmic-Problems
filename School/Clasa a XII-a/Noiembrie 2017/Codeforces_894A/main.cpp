#include <iostream>
#include <cstring>
using namespace std;
char c[102];
int len,nr,nrq,s;
struct a{
    int l,r;
}v[102];
int main()
{
    cin>>c;
    len=strlen(c);
    for(int i=0;i<len;++i){
        if(c[i]=='Q')
            nrq++;
        if(c[i]=='A'){
            ++nr;
            v[nr].l=nrq;
        }
    }

    nrq=0;
    int alt=nr;
    for(int i=len-1;i>=0;--i){
        if(c[i]=='Q')
            nrq++;
        if(c[i]=='A'){
            v[alt].r=nrq;
            --alt;
        }
    }
    for(int i=1;i<=nr;++i){
            s+=v[i].l*v[i].r;
    }
    cout<<s;
    return 0;
}
