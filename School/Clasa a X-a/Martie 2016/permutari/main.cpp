#include <iostream>
#include <fstream>
using namespace std;
ifstream in("permutari.in");
ofstream out("permutari.out");
long long fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000};
int n,v[18],nr;
long long d,p;
int s[18]={0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
void perm_to_nr(int nalt){
    while(nalt>0){
        d+=s[v[n-nalt+1]]*fact[nalt-1];
        for(int i=v[n-nalt+1];i<=n;++i)
            --s[i];
        --nalt;
    }
}
void nr_to_perm(int s[18],long long nr){
    int salt[18];
    long long nrp=0;
    int i,nalt=n;
    for(i=0;i<n;++i){
        int j=0;
        while((j+1)*fact[n-i-1]+nrp<=nr && (j+1)<=nalt)
            ++j;
        nrp+=j*fact[n-i-1];
        salt[i]=s[j];
        int k;
        for(k=j;k<nalt-1;++k)
            s[k]=s[k+1];
        --nalt;
    }
    for(int i=0;i<n;++i)
        out<<salt[i]<<" ";
    out<<endl;
}
int main()
{

    in>>n;
    for(int i=1;i<=n;++i)
        in>>v[i];
    perm_to_nr(n);
    in>>nr;
    for(int i=1;i<=nr;++i){
        in>>p;
        for(int i=0;i<=14;++i)
            s[i]=i+1;
        nr_to_perm(s,d+p);
    }
    return 0;
}
