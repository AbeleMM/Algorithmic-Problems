#include <iostream>
#include <cstring>
using namespace std;
char s[1100];
int lmax,n,l,start,finish;
int main()
{
    cin.get(s,1100);
    cin.get();
    n=strlen(s);
    for(int i=0;i<n;++i){
        l=1;
        while(i-l>=0 && i+l<n && s[i-l]==s[i+l])
            ++l;
        if(lmax<2*l-1){
            lmax=2*l-1;
            start=i-l+1;
            finish=i+l-1;
        }
        l=0;
        while(i-l>=0 && i+l+1<n && s[i-l]==s[i+l+1])
            ++l;
        if(lmax<2*l){
            lmax=2*l;
            start=i-l+1;
            finish=i+l;
        }
    }
    for(int i=start;i<=finish;++i)
            cout<<s[i];
    return 0;
}
