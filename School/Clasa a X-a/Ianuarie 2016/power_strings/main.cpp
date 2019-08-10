#include <iostream>
#include <cstring>
using namespace std;
int n,m,pi[500002],k;
int nr;
char t[1000002],p[500002];
bool ok=false;
void prefix(){
    for(int i=0;i<=m;++i){
        while(k>0 && p[i]!=p[k])
            k=pi[k-1];
        if(p[k]==p[i])
            ++k;
        pi[i]=k;
    }
}
int main()
{
    while(ok==false){
        m=0;
        bool alt=false;
        cin.get(t,1000002);
        cin.get();
        n=strlen(t);
        if(t[0]=='.' && n==1)
            ok=true;
       while(ok==false && alt==false  && m<n/2){
            p[m]=t[m];
            p[m+1]='\0';
            k=0,nr=0;
            prefix();
            k=0;
            for(int i=0;i<n;++i){
                while(k>0 && t[i]!=p[k])
                    k=pi[k-1];
                if(p[k]==t[i])
                    ++k;
                if(k==m)
                    nr++;
            }
            if(nr*(m+1)==n-1){
                cout<<nr;
                alt=true;
            }
            ++m;
        }
        if(alt==false && ok==false)
            cout<<"1";
    }
    return 0;
}
