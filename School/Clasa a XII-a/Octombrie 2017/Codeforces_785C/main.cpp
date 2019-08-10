#include <iostream>

using namespace std;
unsigned long long n,m,z;
unsigned long long caut_bin(unsigned long long st, unsigned long long dr){
    unsigned long long mij=st+(dr-st)/2;
    if(mij*(mij+1)>=2*(n-m)){
        if((mij-1)*mij<2*(n-m))
            return mij;
        else
            return caut_bin(st,mij-1);
    }
    else
        return caut_bin(mij+1,dr);
}
int main()
{
    cin>>n>>m;
    if(n<=m)
        cout<<n;
    else{
        z=caut_bin(1,2000000000);
        cout<<m+z;
    }
    return 0;
}
