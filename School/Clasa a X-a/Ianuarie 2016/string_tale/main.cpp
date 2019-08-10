#include <iostream>
#include <cstring>
using namespace std;
int n,pi[500020],k;
int nr=-1;
char t[500020],p[250010],aux[250010];
void prefix(){
    for(int i=1;i<=2*(n-1);++i)
    {
        while(k>0 && p[i]!=p[k])
            k=pi[k-1];
        if(p[k]==p[i])
            ++k;
        pi[i]=k;
    }
}
int main()
{
    cin>>n>>p>>t;
    strcpy(aux,t);
    strcat(t,aux);
    prefix();
    k=0;
    for(int i=0;i<=2*(n-1);++i){
        while(k>0 && t[i]!=p[k])
            k=pi[k-1];
        if(p[k]==t[i])
            ++k;
        if(k==n){
            nr=i-n+1;
            k=pi[k-1];
        }
    }
    cout<<nr;
    return 0;
}
