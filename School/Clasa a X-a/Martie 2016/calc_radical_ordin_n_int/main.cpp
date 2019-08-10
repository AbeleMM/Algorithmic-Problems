#include <iostream>

using namespace std;
int n,r;
unsigned long long exp(int x, int n){
    unsigned long long p=1;
    while(n>0){
        if(n%2==1){
            p=p*x;
            --n;
        }
        else{
            x=x*x;
            n/=2;
        }
    }
    return p;
}
int caut(int st, int dr){
    int mj=st+(dr-st)/2;
    if(exp(mj,r)>n)
        caut(st,mj-1);
    else{
        if(exp(mj+1,r)>n)
            return mj;
        else
            caut(mj+1,dr);
    }
}
int main()
{
    cin>>n>>r;
    cout<<caut(1,n);
    return 0;
}
