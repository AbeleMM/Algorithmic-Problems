#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("spion.in");
ofstream out("spion.out");
int p,nr,n;
char s[100005];
unsigned long long t=1;
unsigned long long inv_mod(long long x){
    int c=100001;
    unsigned long long r=1;
    while(c>0){
        if(c%2==1){
            r=(r*x)%100003;
            --c;
        }
        else{
            x=(x*x)%100003;
            c/=2;
        }
    }
    return r%100003;
}
int main()
{
    in>>p;
    in>>s;
    if(p==1){
        nr=1;
        n=strlen(s);
        for(int i=0;i<n;++i)
            if(s[i]=='E')
                ++nr;
        out<<nr;
    }
    if(p==2){
        n=strlen(s);
        for(int i=0;i<n;++i){
            if(s[i]=='E')
                ++nr;
        }
        if(n-nr>nr)
            nr=n-nr;
        for(int i=1;i<=nr;++i,--n)
            t=(t*((n*inv_mod(i))%100003))%100003;
        out<<t;
    }
    return 0;
}
