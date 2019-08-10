#include <iostream>

using namespace std;
 int n,var,vm;
long long v[100001];
long long s;
bool ok=true;
inline long long mx(long long a,long long b){
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>var;
        v[var]++;
        if(var>vm)
            vm=var;
    }
    for(int i=2;i<=vm;++i)
        v[i]=mx(v[i-1],v[i-2]+v[i]*i);
    cout<<v[vm];
    return 0;
}
