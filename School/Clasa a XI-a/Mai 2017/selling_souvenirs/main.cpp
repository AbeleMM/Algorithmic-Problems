#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,sol,val;
long long dp[300002];
int ind=1;
struct obiect{
    long long g,val;
}v[300002];
inline bool cond(struct obiect a, struct obiect b){
    if(a.g==b.g)
        return a.val>b.val;
    else
        return a.g>b.g;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>v[i].g>>v[i].val;
    sort(v+1,v+n+1,cond);
    while(v[ind].g==3)
        ++ind;

    for(int i=ind;i<=n;++i){
        for(int j=m-v[i].g;j>=1;--j)
            if(dp[j]>0 && dp[j]+v[i].val>dp[j+v[i].g])
                dp[j+v[i].g]=dp[j]+v[i].val;
        if(v[i].val>dp[v[i].g])
            dp[v[i].g]=v[i].val;
    }

    for(int i=0;i<=m;++i){
        val=dp[i];
        for(int j=1;j<=(m-i)/3 && j<ind;++j)
            val+=v[j].val;
        if(val>sol)
            sol=val;
    }
    cout<<sol;
    return 0;
}
