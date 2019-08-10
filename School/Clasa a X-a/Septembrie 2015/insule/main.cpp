#include <iostream>
#include <fstream>
using namespace std;
ifstream in("insule.in");
ofstream out("insule.out");
int n,m,NR,NG,NB,Lg,a[102][102],p;
int inc,sf,nrr,nrg,b[102][102];
char t;
struct optiuni{
    int s1;
    int s2;
    int f1;
    int f2;
}alt[10000];
struct labirint{
    int x;
    int y;
}c[10000];
void fill(int x, int y)
{
    if(a[x][y]==p)
    {
        a[x][y]=-p;
        fill(x+1,y);
        fill(x,y+1);
        fill(x-1,y);
        fill(x,y-1);
    }
}
void lee(int x0, int y0)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0)
                b[i][j]=0;
            else
                b[i][j]=-1;
        }
    b[x0][y0]=1;
    inc=0; sf=0;
    c[sf].x=x0;
    c[sf].y=y0;
    while(!(inc>sf))
    {
        if(b[c[inc].x][c[inc].y]!=-1)
        {
            x0=c[inc].x;
            y0=c[inc].y;
            inc++;
            if(b[x0+1][y0]>b[x0][y0]+1 && b[x0+1][y0]!=-1 && x0+1>0)
            {
                b[x0+1][y0]=b[x0][y0]+1;
                sf++;
                c[sf].x=x0+1;
                c[sf].y=y0;
            }
            if(b[x0-1][y0]>b[x0][y0]+1 && b[x0-1][y0]!=-1 && x0-1>0)
            {
                b[x0-1][y0]=b[x0][y0]+1;
                sf++;
                c[sf].x=x0-1;
                c[sf].y=y0;
            }
            if(b[x0][y0+1]>b[x0][y0]+1 && b[x0][y0+1]!=-1 && y0+1>0)
            {
                b[x0][y0+1]=b[x0][y0]+1;
                sf++;
                c[sf].x=x0;
                c[sf].y=y0+1;
            }
            if(b[x0][y0-1]>b[x0][y0]+1 && b[x0][y0-1]!=-1 && y0-1>0)
            {
                b[x0][y0-1]=b[x0][y0]+1;
                sf++;
                c[sf].x=x0;
                c[sf].y=y0-1;
            }
        }
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            in>>t;
            a[i][j]=t-48;
        }
    Lg=n*m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                p=1;
                NR++;
                fill(i,j);
            }
            if(a[i][j]==2)
            {
                p=2;
                NG++;
                fill(i,j);
            }
            if(a[i][j]==3)
            {
                p=3;
                NB++;
                fill(i,j);
            }
            if(a[i][j]==0 && (a[i+1][j]==1 || a[i][j+1]==1 || a[i-1][j]==1 || a[i][j-1]==1 || a[i+1][j]==-1 || a[i][j+1]==-1 || a[i-1][j]==-1 || a[i][j-1]==-1))
            {
                nrr++;
                alt[nrr].s1=i;
                alt[nrr].s2=j;
            }
            if(a[i][j]==0 && (a[i+1][j]==2 || a[i][j+1]==2 || a[i-1][j]==2 || a[i][j-1]==2 || a[i+1][j]==-2 || a[i][j+1]==-2 || a[i-1][j]==-2 || a[i][j-1]==-2))
            {
                nrg++;
                alt[nrg].f1=i;
                alt[nrg].f2=j;
            }
        }
    for(int i=1;i<=nrr;i++)
    {
        lee(alt[i].s1,alt[i].s2);
        for(int j=1;j<=nrg;j++)
            if(b[alt[j].f1][alt[j].f2]<Lg && b[alt[j].f1][alt[j].f2]!=0)
                Lg=b[alt[j].f1][alt[j].f2];
    }
    out<<NR<<" "<<NG<<" "<<NB<<" "<<Lg;
    return 0;
}
