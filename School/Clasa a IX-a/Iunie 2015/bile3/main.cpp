#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream in("bile3.in");
ofstream out("bile3.out");
int n,a[2002],b[2002],c,sf,p,t;
char s[4000001];
int vid()
{
    if(sf==0)
        return 1;
    else
        return 0;
}
int main()
{
    in>>n;
    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int i=1; i<=n; i++)
    {
        in>>c;
        while(b[sf]!=c && t<n)
        {
            sf++;
            t++;
            b[sf]=a[t];
            s[p]='I';
            p++;
        }
        if(b[sf]==c)
        {
            sf--;
            s[p]='O';
            p++;
        }
    }
    if(vid()==1)
        out<<s;
    else
        out<<"imposibil";
}
