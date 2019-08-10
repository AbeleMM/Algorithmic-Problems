//programare dinamica
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long pd[100001],x,y,c;
unsigned int a,b,h,w,n;
unsigned int v[100001];
bool ok;
inline bool cond(int a, int b){
    return a>b;
}
int main()
{
    cin>>a>>b>>h>>w>>n;
    for(unsigned int i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1,cond);

    if(a>b) swap(a,b);
    if(h>w) swap(h,w);
    if(h>=a && w>=b)
        cout<<0;
    else{
        pd[h]=w;
        for(unsigned int i=1;i<=n && ok==0;++i)
            for(unsigned int j=b;j>=1 && ok==0;--j)
                if(pd[j]!=0){
                    c=pd[j];

                    x=c,y=j*v[i];
                    if(x>b) x=b;
                    if(y>b) y=b;
                    if(x>y) swap(x,y);
                    if(y>pd[x])
                        pd[x]=y;
                    if(x>=a && y>=b && ok==0)
                        cout<<i,ok=1;

                    x=j,y=c*v[i];
                    if(x>b) x=b;
                    if(y>b) y=b;
                    if(x>y) swap(x,y);
                    if(y>pd[x])
                        pd[x]=y;
                    if(x>=a && y>=b && ok==0)
                        cout<<i,ok=1;
                }
        if(ok==0)
            cout<<"-1";
    }
    return 0;
}
