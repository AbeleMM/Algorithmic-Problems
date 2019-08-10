#include <iostream>
#include <fstream>
using namespace std;
ifstream in("caroiaj.in");
ofstream out("caroiaj.out");
int c[1000][1000],n,m,x0,y0,sf,inc,k;
struct labirint
{
    int x;
    int y;
}v[1000001];
int vid()
{
    if(inc>sf)
        return 1;
    else
        return 0;
}
/*int plin
{
    if(sf==dmax-1)
        return 1;
    else
        return 0;
}*/
int main()
{
    in>>n>>m;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[i][j]=65535;
    in>>x0>>y0;
    c[x0][y0]=0;
    inc=0; sf=0;
    v[sf].x=x0;
    v[sf].y=y0;
    in>>k;
    for(int i=1;i<=k;i++)
    {
        in>>x0>>y0;
        c[x0][y0]=-1;
    }
    while(!vid())
    {
        if(c[v[inc].x][v[inc].y]!=-1)
        {
            x0=v[inc].x;
            y0=v[inc].y;
            inc++;
            if(c[x0+1][y0]>c[x0][y0]+1 && c[x0+1][y0]!=-1 && x0+1>0)
            {
                c[x0+1][y0]=c[x0][y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=y0;
            }
            if(c[x0-1][y0]>c[x0][y0]+1 && c[x0-1][y0]!=-1 && x0-1>0)
            {
                c[x0-1][y0]=c[x0][y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=y0;
            }
            if(c[x0][y0+1]>c[x0][y0]+1 && c[x0][y0+1]!=-1 && y0+1>0)
            {
                c[x0][y0+1]=c[x0][y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=y0+1;
            }
            if(c[x0][y0-1]>c[x0][y0]+1 && c[x0][y0-1]!=-1 && y0-1>0)
            {
                c[x0][y0-1]=c[x0][y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=y0-1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            out<<c[i][j]<<" ";
        out<<"\n";
    }
    return 0;
}
