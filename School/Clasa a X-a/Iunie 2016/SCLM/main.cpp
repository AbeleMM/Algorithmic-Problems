#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sclm.in");
ofstream out("sclm.out");
int n,m,prim;
int a[1005],l[1005],poz[1005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>a[i];
    for(int i=n;i>=1;--i){
        l[i]=1, poz[i]=0;
        for(int j=i+1;j<=n;++j)
            if(a[i]<a[j] && l[i]<l[j]+1){
                l[i]=l[j]+1;
                poz[i]=j;
            }
        if(m<l[i]){
            m=l[i];
            prim=i;
        }
    }
    out<<m<<"\n";
    for(int i=prim;i>0;i=poz[i])
        out<<i<<" ";
    return 0;
}
