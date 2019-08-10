#include <iostream>
#include <fstream>
using namespace std;
ifstream in("elicop.in");
ofstream out("elicop.out");
int n,m,e[105][105],k,nr,t1,t2,r;
struct aterizare
{
    int l1;
    int c1;
    int l2;
    int c2;
    int p;
    int ok;
}d[43];
void citire()
{
    int i,j;
    in>>m>>n;
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            in>>e[i][j];
        }
    }
    in>>k;
    for(i=1;i<=k;i++)
    {
        in>>d[i].l1;
        in>>d[i].c1;
        in>>d[i].l2;
        in>>d[i].c2;
        in>>d[i].p;
    }
}
void teren()
{
    int i,j,f;
    for(f=1;f<=k;f++)
    {
        for(i=d[f].l1;i<=d[f].l2;++i)
        {
            if(d[f].p==1 && d[f].c1>=d[f].c2)
            {
                for(j=d[f].c1;j<=d[f].c2-(i-d[f].l1);++j)
                {
                    r++;
                    if(e[i][j]==0)
                        nr++;
                }
            }
            if(d[f].p==1 && d[f].c2>d[f].c1)
            {
                for(j=d[f].c2;j>=d[f].c1+(i-d[f].l1);--j)
                {
                    r++;
                    if(e[i][j]==0)
                        nr++;
                }
            }
            if(d[f].p==-1 && d[f].c1>=d[f].c2)
            {
                for(j=d[f].c2;j>=d[f].c1+(i-d[f].l1);--j)
                {
                    r++;
                    if(e[i][j]==0)
                        nr++;
                }
            }
            if(d[f].p==-1 && d[f].c2>d[f].c1)
            {
                for(j=d[f].c1;j<=d[f].c2-(d[f].l2-i);++j)
                {
                    r++;
                    if(e[i][j]==0)
                        nr++;
                }
            }
        }
        if(nr==0)
            t1++;
        if(nr>r/2)
        {
            t2++;
            d[f].ok=1;
        }
    }
}
void afisare()
{
    out<<t1<<"\n"<<t2<<" ";
    for(int i=1;i<=k;i++)
    {
        if(d[i].ok==1)
            out<<i<<" ";
    }
}
int main()
{
    citire();
    teren();
    afisare();
    return 0;
}
