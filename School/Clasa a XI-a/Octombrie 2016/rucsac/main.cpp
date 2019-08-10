#include <iostream>
#include <fstream>
using namespace std;
ifstream in("rucsac.in");
ofstream out("rucsac.out");
int n,g,val,masa,v[10002];
int main()
{
    in>>n>>g;
    for(int i=1;i<=n;++i){
        in>>masa>>val;
        for(int j=g;j>=0;--j)
            if(j+masa<=g && v[j]+val>v[j+masa])
                v[j+masa]=v[j]+val;
    }
    int mx=v[g];
    for(int i=g;i>=0;--i)
        if(v[i]>mx)
            mx=v[i];
    out<<mx;
    return 0;
}
