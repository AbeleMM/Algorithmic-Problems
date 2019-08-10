#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct elem{
    long long val;
    int poz;
}vp[100001],vq[100001],vr[100001];
int n,p,q,r,c;
long long x;
bool cond(elem a, elem b){
    return a.val<b.val;
}
int main()
{
    /*scanf("%d %d %d %d",&n,&p,&q,&r);
    for(int i=1;i<=n;++i){
        scanf("%ll",&vp[i].val);
        vq[i].val=vr[i].val;
        vp[i].poz=vq[i].poz=vr[i].poz=i;
        vp[i].val*=p;
        vq[i].val*=q;
        vr[i].val*=r;
    }
    sort(vp+1,vp+n+1,cond);
    sort(vq+1,vq+n+1,cond);
    sort(vr+1,vr+n+1,cond);
    printf("%ll",&x);*/
    cout<<sizeof(int)<<"\n";
    cout<<sizeof(long)<<"\n";
    cout<<sizeof(long long)<<"\n";

    return 0;
}
