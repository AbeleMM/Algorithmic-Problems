#include <iostream>
#include <fstream>
using namespace std;
ifstream in("poarta.in");
ofstream out("poarta.out");
long long n,v[500005],nr;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>v[i],v[i]+=v[i-1];
    if(v[n]%3==0){
        long long pre=0,sum=v[n]/3;
        for(int i=1;i<n;++i){
            if(v[i]==2*sum && i!=1)
                nr+=pre;
            if(v[i]==sum && i!=n-1)
                ++pre;
        }
    }
    out<<nr;
    return 0;
}
