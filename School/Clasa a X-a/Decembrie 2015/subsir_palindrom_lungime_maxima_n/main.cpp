#include <iostream>
#include <cstring>
using namespace std;
char s[1005],t[2011];
int c,r,n,lmax,cmax,lps[2011],nr=1;
int i,ii;
bool expand=false;
int main()
{
    cin>>s;
    n=strlen(s);
    t[0]='#';
    for(i=0;i<n;++i){
        t[nr]=s[i];
        t[nr+1]='#';
        nr+=2;
    }
    t[nr]='\0';
    lps[1]=1;
    c=1, r=2, lmax=1, cmax=1;
    for(i=2;i<nr;++i){
        expand=false;
        ii=2*c-i;
        if(r<=i){
            lps[i]=0;
            expand=true;
        }
        else{
            if(lps[ii]<r-i)
                lps[i]=lps[ii];
            else{
                if(lps[ii]==r-i)
                    lps[i]=lps[ii];
                else
                    lps[i]=r-i;
                expand=true;
            }
        }
        while(i-lps[i]>0 && i+lps[i]<nr && expand==true){
            if((i-lps[i]-1)%2==0)
                ++lps[i];
            else{
                if(t[i-lps[i]-1]==t[i+lps[i]+1])
                    ++lps[i];
                else
                    expand=false;
            }
        }
        if(lmax<lps[i]){
            lmax=lps[i];
            cmax=i;
        }
        if(i+lps[i]>r){
            r=i+lps[i];
            c=i;
        }
    }
    for(i=cmax-lmax;i<cmax+lmax;++i)
        if(t[i]!='#')
            cout<<t[i];
    return 0;
}
