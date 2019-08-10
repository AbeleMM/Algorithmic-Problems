#include <iostream>
using namespace std;
short int n,m,t;
unsigned long long nr=0;
unsigned long long comb(short int n,short int k){
    unsigned long long c=1;
    for(int i=1;i<=k;++i){
        c*=n;
        c/=i;
        --n;
    }
    return c;
}
int main()
{
    cin>>n>>m>>t;
    short int ncur=4,mcur=t-4;
    while(ncur<=n && mcur>=1){
        nr+=comb(n,ncur)*comb(m,mcur);
        ++ncur;
        --mcur;
    }
    cout<<nr;
    return 0;
}
