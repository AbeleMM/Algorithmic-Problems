#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
char s[50],salt[50];
long long nr,nrp;
int n;
long long fact(int n){
    long long alt=1;
    for(int i=2;i<=n;++i)
        alt*=i;
    return alt;
}
void perm_to_nr(){
    for(int i=0;i<n;++i){
        int j;
        for(j=0;j<n;++j)
            if(s[j]==salt[j])
                break;
        nr+=j*fact(n-i-1);
        for(int k=j;k<n-1;++k)
            s[k]=s[k+1];
    }
    out<<nr;
}
int main()
{
    in>>s;
    in.get();
    in>>salt;
    in>>nrp;
    n=strlen(s);
    perm_to_nr();
    return 0;
}
