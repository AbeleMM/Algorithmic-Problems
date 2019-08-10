#include <iostream>
#include <fstream>
using namespace std;
ifstream in("stalpi.in");
ofstream out("stalpi.out");
int n,m,h[100003],s,k,ult;
int main()
{
    in>>n;
    for(int i=1;i<=n;i++)
        in>>h[i];
    in>>m;
    for(int i=1;i<=m;i++)
    {
        in>>k;
        ult=h[k];
        s=0;
        for(int j=k+1;j<=n;j++)
            if(h[j]>ult)
            {
                ult=h[j];
                s++;
            }
        out<<s<<"\n";
    }
    return 0;
}
