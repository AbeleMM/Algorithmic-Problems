#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int t;
int rezolvare(){
    int n,i,j,mx=0;
    int m[106],v[103];
    in>>n;
    for(int i=1;i<=n;++i)
        in>>v[i];
    for(int i=1;i<=n;++i)
        m[i]=v[i];
    for(i=2;i<=n;++i)
        for(j=1;j<i;++j)
            if(v[i]>v[j] && m[i]<m[j]+v[i])
                m[i]=m[j]+v[i];
    for(i=1;i<=n;++i)
        if(mx<m[i])
            mx=m[i];
    return mx;
}
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
        out<<rezolvare()<<"\n";
    return 0;
}
