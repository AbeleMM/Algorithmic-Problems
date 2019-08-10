#include <iostream>
#include <cstring>
using namespace std;
int nr,len;
char s[22];
//long long fact[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};
long long p,alt;
long long fact[22];
void qs(int st, int dr){
    int i=st,j=dr,t;
    int x=s[i+(j-i)/2];
    while(i<=j){
        while(i<dr && s[i]<x)
            i++;
        while(j>st && s[j]>x)
            j--;
        if(i<=j)
        {
            t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
    }
    if(st<j)
        qs(st,j);
    if(i<dr)
        qs(i,dr);
}
void nr_to_perm(char s[22],long long nr){
    char salt[22];
    long long nrp=0;
    int i;
    for(i=0;i<len;++i){
        int len2=strlen(s);
        int j=0;
        while((j+1)*fact[len-i-1]+nrp<=nr && (j+1)<len2)
            ++j;
        nrp+=j*fact[len-i-1];
        salt[i]=s[j];
        int k;
        for(k=j;k<len-1;++k)
            s[k]=s[k+1];
        s[k]='\0';
    }
    salt[i]='\0';
    cout<<salt<<"\n";
}
int main()
{
    for(int i=0;i<=20;++i){
        fact[i]=1;
        for(int j=2;j<=i;++j)
            fact[i]*=j;
    }
    cin>>nr;
    for(int i=1;i<=nr;++i){
        cin.get();
        cin>>s;
        cin>>p;
        len=strlen(s);
        qs(0,len-1);
        nr_to_perm(s,p);
    }
    return 0;
}
