//#include <bits/stdc++.h>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
set <int> s;
pair <int,int> v[300000];
int n,x,l=1,nr;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        if(s.find(x)!=s.end()){
            nr++;
            v[nr]=make_pair(l,i);
            l=i+1;
            s.clear();
        }
        else
            s.insert(x);
    }
    if(nr>0){
        if(!s.empty())
            v[nr].second=n;
        printf("%d\n",nr);
        for(int i=1;i<=nr;++i)
            printf("%d %d\n",v[i].first,v[i].second);
    }
    else
        printf("%d\n",-1);
    return 0;
}
