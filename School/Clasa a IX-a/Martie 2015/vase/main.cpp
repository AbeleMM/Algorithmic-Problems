#include <iostream>
#include <fstream>
using namespace std;
ifstream in("vase.in");
ofstream out("vase.out");
int n,x;
long long ss,sd,ms,md;
struct substante
{
    int nr;
    char t;
}v[100004];
int main()
{
    int i;
    in>>n;
    for(i=1;i<=n;++i)
    {
        in>>v[i].nr>>v[i].t;
        if(v[i].t=='S')
            ss=ss+v[i].nr;
        if(v[i].t=='D')
            sd=sd+v[i].nr;
    }
    in>>x;
    out<<(ss+sd)/2<<"\n";
    return 0;
}
