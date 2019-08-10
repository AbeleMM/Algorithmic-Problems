#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,k,dmax;
int v[51];// val max = k
bool l[102];//val max = n
int main()
{
    l[0]=true;
    in>>n>>k;
    for(int i=1;i<=n;++i)
        in>>v[i];
    for(int i=1;i<=k;++i)
    for(int j=dmax;j>=0;--j){
        if(l[j]==true)
            l[j+v[i]]=true;
        if(dmax<j+v[i])
            dmax=j+v[i];
    }
    for(int i=0;i<=dmax;++i)
        cout<<l[i]<<" ";
    return 0;
}
