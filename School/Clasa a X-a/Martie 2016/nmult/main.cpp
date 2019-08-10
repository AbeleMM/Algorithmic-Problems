#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nmult.in");
ofstream out("nmult.out");
int n,k,w;
unsigned long long put(unsigned long long x){
    int n=666011;
    unsigned long long p=1;
    while(n>0){
        if(n%2==1){
            p=(p*x)%666013;
            --n;
        }
        else{
            x=(x*x)%666013;
            n/=2;
        }
    }
    return p;
}
int main()
{
    in>>n>>k>>w;
    while(w>1 && n>=k){
        --w;
        n=n-k+1;
    }
    if(n-k>k)
        k=n-k;
    unsigned long long t=1,z;
    for(int i=1;i<=k;++i,--n){
        z=(n*put(i))%666013;
        t=(t*z)%666013;
    }
    out<<t;
    return 0;
}
