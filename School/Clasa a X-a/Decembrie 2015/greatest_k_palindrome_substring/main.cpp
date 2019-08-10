#include <iostream>
#include <cstring>
using namespace std;
char s[1100];
int lmax,n,l,nr,k,t;
int main()
{
    cin>>nr;
    for(int c=1;c<=nr;++c){
        cin>>s>>k;
        cin.get();
        n=strlen(s);
        for(int i=0;i<n;++i){
            l=1,t=0;
            while(i-l>=0 && i+l<n && (s[i-l]==s[i+l] || t<k)){
                if(s[i-l]!=s[i+l])
                    ++t;
                ++l;
            }
            if(lmax<2*l-1)
                lmax=2*l-1;
            l=0,t=0;
            while(i-l>=0 && i+l+1<n && (s[i-l]==s[i+l+1] || t<k)){
                if(s[i-l]!=s[i+l+1])
                    ++t;
                ++l;
            }
            if(lmax<2*l)
                lmax=2*l;
        }
        cout<<lmax;
        lmax=0;
    }
    return 0;
}
