#include <iostream>
#include <fstream>
using namespace std;
ifstream in("taxe1.in");
ofstream out("taxe1.out");
int s,n,loc[105][105],sf,inc,x0,yalt,aux[105][105];
struct lab
{
    int x,y;
}v[100000];
int vid()
{
    if (inc>sf)
        return 1;
    return 0;
}
int main()
{
    in>>s>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            in>>loc[i][j];
            aux[i][j]=-65536;
        }
    inc=1,sf=1;
    v[1].x=v[1].y=1;
    aux[1][1]=s-loc[1][1];
    while(!vid())
    {
        x0=v[inc].x;
        yalt=v[inc].y;
        inc++;
        if(aux[x0+1][yalt]<aux[x0][yalt]-loc[x0+1][yalt] && x0+1>0 && x0+1<=n && yalt>0 && yalt<=n)
        {
            sf++;
            v[sf].x=x0+1;
            v[sf].y=yalt;
            aux[x0+1][yalt]=aux[x0][yalt]-loc[x0+1][yalt];
        }
        if(aux[x0-1][yalt]<aux[x0][yalt]-loc[x0-1][yalt] && x0-1>0 && x0-1<=n && yalt>0 && yalt<=n)
        {
            sf++;
            v[sf].x=x0-1;
            v[sf].y=yalt;
            aux[x0-1][yalt]=aux[x0][yalt]-loc[x0-1][yalt];
        }
        if(aux[x0][yalt+1]<aux[x0][yalt]-loc[x0][yalt+1] && x0>0 && x0<=n && yalt+1>0 && yalt+1<=n)
        {
            sf++;
            v[sf].x=x0;
            v[sf].y=yalt+1;
            aux[x0][yalt+1]=aux[x0][yalt]-loc[x0][yalt+1];
        }
        if(aux[x0][yalt-1]<aux[x0][yalt]-loc[x0][yalt-1] && x0>0 && x0<=n && yalt-1>0 && yalt-1<=n)
        {
            sf++;
            v[sf].x=x0;
            v[sf].y=yalt-1;
            aux[x0][yalt-1]=aux[x0][yalt]-loc[x0][yalt-1];
        }
    }
    if(aux[n][n]>=0)
        out<<aux[n][n];
    else
        out<<"-1";
    return 0;
}
