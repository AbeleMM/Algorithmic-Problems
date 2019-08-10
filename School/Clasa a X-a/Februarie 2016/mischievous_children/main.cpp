#include <iostream>
#include <cstring>
using namespace std;
int n,l[28];
char s[22];
long long fact(int n){
    long long nr=1;
    for(int i=2;i<=n;++i)
        nr*=i;
    return nr;
}
void perm(char s[22],int d){
    int l[27];
    for(int i=0;i<=27;++i)
        l[i]=0;
    int len=strlen(s);
    for(int i=0;i<len;++i)
        ++l[s[i]-'A'];
    long long nr=fact(len);
    for(int i=0;i<=25;++i){
        if(l[i]>1)
            nr/=fact(l[i]);
    }
    cout<<"Data set "<<d<<": "<<nr<<"\n";
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin.get();
        cin>>s;
        perm(s,i);
    }
    return 0;
}
