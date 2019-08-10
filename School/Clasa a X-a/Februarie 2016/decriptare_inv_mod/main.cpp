#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
char s[]="ABCDEFGHIJKLMNOPRSTUVXYZ",t[110];
int n,m,len;
long long exp(long long x, int n){
    if(n==0)
        return 1;
    if(n==1)
        return x;
    long long p=1;
    while(n>0){
        if(n%2==1){
            p=(p*x)%23;
            --n;
        }
        else{
            x=(x*x)%23;
            n/=2;
        }
    }
    return p%23;
}
int main()
{
    in>>n>>m;
    in.get();
    int i;
    in>>t;
    len=strlen(t);
    for(i=0;i<len;++i){
        int j=0;
        while(s[j]!=t[i])
            ++j;
        /*int k=0;
        while((j+23*k-m)%n!=0)
            ++k;
        out<<s[(j+23*k-m)/n];*/
        out<<s[((j+23-m)*exp(n,21))%23];
    }
    out<<"\n";
    return 0;
}
