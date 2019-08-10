#include <iostream>
#include <fstream>
using namespace std;
ifstream in("puteri.in");
ofstream out("puteri.out");
int t,prim[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
unsigned long long a,b;
unsigned long long exp(unsigned long long x, int n){
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
unsigned long long caut(unsigned long long st, unsigned long long dr, int r, unsigned long long n){
    int mj=st+(dr-st)/2;
    if(exp(mj,r)>n)
        caut(st,mj-1,r,n);
    else{
        if(exp(mj+1,r)>n)
            return mj;
        else
            caut(mj+1,dr,r,n);
    }
}
unsigned long long calc(unsigned long long x){
    int i=0;
    unsigned long long s=0,c;
    c=caut(1,x,prim[i],x);
    s+=c;
    ++i;
    //cout<<c<<endl<<endl;
    c=caut(1,x,prim[i],x);
    while(c>1){
        //cout<<prim[i]<<": "<<c-1<<"\n";
        s+=<c-caut(1,x,prim[i]*prim[i],x);
        //cout<<c-caut(1,x,prim[i]*prim[i],x)<<endl;
        ++i;
        c=caut(1,x,prim[i],x);
    }
    if(x!=0)
        return s;
    else
        return 0;
}
int main()
{
    /*in>>t;
    for(int i=1;i<=t;++i){
        in>>a>>b;
        out<<calc(b)-calc(a-1)<<"\n";
    }*/
    cout<<calc(497);
    return 0;
}
