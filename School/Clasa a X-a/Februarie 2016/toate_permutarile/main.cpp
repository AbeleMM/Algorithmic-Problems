#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
char s[30];
int sol[30],c[30];
int n;
long long nr;
void init(int k){
    sol[k]=-1;
}
int succesor(int k){
    if(sol[k]<n-1){
        ++sol[k];
        return 1;
    }
    return 0;
}
int valid(int k){
    for(int i=0;i<k;++i)
        if(sol[i]==sol[k])
            return 0;
    return 1;
}
int solutie(int k){
    if(k==n-1)
        return 1;
    return 0;
}
void afisare(int k){
    for(int i=0;i<=k;++i)
        out<<s[sol[i]];
    out<<"\n";
}
void bk(int k){
    init(k);
    while(succesor(k)){
        if(valid(k)){
            if(solutie(k))
                afisare(k);
            else
                bk(k+1);
        }
    }
}
void qs(int st, int dr){
    int i=st,j=dr,mj=st+(dr-st)/2;
    char t;
    while(i<=j){
        while(i<dr && s[i]<s[mj])
            ++i;
        while(j>0 && s[j]>s[mj])
            --j;
        if(i<=j){
            t=s[i];
            s[i]=s[j];
            s[j]=t;
            ++i;
            --j;
        }
    }
    if(i<dr)
        qs(i,dr);
    if(st<j)
        qs(st,j);
}
long long fact(int n){
    long long nr=1;
    for(int i=2;i<=n;++i)
        nr*=i;
    return nr;
}
int main()
{
    in>>s;
    n=strlen(s);
    qs(0,n-1);
    bk(0);
    //+nr permutari unice
    for(int i=0;i<n;++i)
        ++c[s[i]-'a'];
    nr=fact(n);
    for(int i=1;i<=25;++i)
        nr/=fact(c[i]);
    out<<nr;
    return 0;
}
