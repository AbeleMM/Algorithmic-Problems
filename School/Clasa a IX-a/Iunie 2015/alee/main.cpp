#include <iostream>
#include <fstream>
using namespace std;
ifstream in("alee.in");
ofstream out("alee.out");
int c[177][177],n,m,x0,Y0,sf,inc,k,x2,y2;
struct labirint
{
    int x;
    int y;
}v[30630];
int vid()
{
    if(inc>sf)
        return 1;
    else
        return 0;
}
int main()
{
    in>>n;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j]=65535;

    in>>k;
    for(int i=1;i<=k;i++)
    {
        in>>x0>>Y0;
        c[x0][Y0]=-1;
    }
    in>>x0>>Y0;
    c[x0][Y0]=1;
    inc=0; sf=0;
    v[sf].x=x0;
    v[sf].y=Y0;
    in>>x2>>y2;
    while(!vid())
    {
        if(c[v[inc].x][v[inc].y]!=-1)
        {
            x0=v[inc].x;
            Y0=v[inc].y;
            inc++;
            if(c[x0+1][Y0]>c[x0][Y0]+1 && c[x0+1][Y0]!=-1 && x0+1<=n)
            {
                c[x0+1][Y0]=c[x0][Y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=Y0;
            }
            if(c[x0-1][Y0]>c[x0][Y0]+1 && c[x0-1][Y0]!=-1 && x0-1>0)
            {
                c[x0-1][Y0]=c[x0][Y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=Y0;
            }
            if(c[x0][Y0+1]>c[x0][Y0]+1 && c[x0][Y0+1]!=-1 && Y0+1<=n)
            {
                c[x0][Y0+1]=c[x0][Y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=Y0+1;
            }
            if(c[x0][Y0-1]>c[x0][Y0]+1 && c[x0][Y0-1]!=-1 && Y0-1>0)
            {
                c[x0][Y0-1]=c[x0][Y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=Y0-1;
            }
        }
    }
    out<<c[x2][y2];
}
