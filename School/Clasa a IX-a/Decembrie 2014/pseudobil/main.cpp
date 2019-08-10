#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("pseudobil.in");
ofstream out("pseudobil.out");
int p,n,K,D,m,masa[1503][1503],a,b,x,y,ajut[1503][1503],nr,s;
void citire1()
{
    in>>n>>K>>D;
}
void prelucrare1()
{
        s=(D-1)+(D-2)*(D-2)/2;
}
void afisare1()
{
    out<<s;
}
void citire2()
{
    int i;
    in>>n>>K>>D;
    for(i=1;i<=K;++i)
    {
        in>>a>>b;
        masa[a][b]=1;
    }
    in>>m;
}
void prelucrare_afisare2()
{
    int i,j;
    for(i=1;i<=n;++i)
    {
        s=0;
        for(j=1;j<=n;++j)
        {
            s=s+masa[i][j];
            ajut[i][j]=s;
        }
    }
    for(i=1;i<=m;++i)
    {
        in>>x>>y;
        nr=0;
        for(j=x;j<=x+D/2;++j)
        {
            nr=nr+ajut[j][y+j-x]-ajut[j][y-j+x];
        }
        for(j=x+D/2+1;j<=x+D;++j)
        {
            nr=nr+ajut[j][y+j-(x+D/2)]-ajut[j][y-j+(x+D/2)];
        }
        out<<nr<<"\n";
    }
}
int main()
{
    in>>p;
    if (p==1)
    {
        citire1();
        prelucrare1();
        afisare1();
    }
    if(p==2)
    {
        citire2();
        prelucrare_afisare2();
    }
    return 0;
}
