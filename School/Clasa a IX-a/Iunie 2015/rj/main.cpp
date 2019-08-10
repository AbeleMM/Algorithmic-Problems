#include <iostream>
#include <fstream>
using namespace std;
ifstream in("rj.in");
ofstream out("rj.out");
int n,m,b[103][103],f[103][103],inc,sf,tmin,x0,y0,c1,c2;
char t;
struct coada{
    int x;
    int y;
}v[10005];
int vid()
{
    if(inc>sf)
        return 1;
    else
        return 0;
}
int main()
{
    in>>n>>m;
    in.get();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            in.get(t);
            if(t==' ')
            {
                b[i][j]=65536;
                f[i][j]=65536;
            }
            if(t=='X')
            {
                b[i][j]=-1;
                f[i][j]=-1;
            }
            if(t=='R')
            {
                b[i][j]=0;
                v[sf].x=x0;
                v[sf].y=y0;
            }
            if(t=='J')
            {
                f[i][j]=0;
                c1=i;
                c2=j;
            }

        }
        in.get(t);
    }
    while(!vid())
    {
        if(b[v[inc].x][v[inc].y]!=-1)
        {
            x0=v[inc].x;
            y0=v[inc].y;
            inc++;
            if(b[x0+1][y0]>b[x0][y0]+1 && b[x0+1][y0]!=-1 && x0+1>0)
            {
                b[x0+1][y0]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=y0;
            }
            if(b[x0-1][y0]>b[x0][y0]+1 && b[x0-1][y0]!=-1 && x0-1>0)
            {
                b[x0-1][y0]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=y0;
            }
            if(b[x0][y0+1]>b[x0][y0]+1 && b[x0][y0+1]!=-1 && y0+1>0)
            {
                b[x0][y0+1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=y0+1;
            }
            if(b[x0][y0-1]>b[x0][y0]+1 && b[x0][y0-1]!=-1 && y0-1>0)
            {
                b[x0][y0-1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=y0-1;
            }
            if(b[x0+1][y0+1]>b[x0][y0]+1 && b[x0+1][y0+1]!=-1 && y0+1>0 && x0+1>0)
            {
                b[x0+1][y0+1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=y0+1;
            }
            if(b[x0-1][y0-1]>b[x0][y0]+1 && b[x0-1][y0-1]!=-1 && y0-1>0 && x0-1>0)
            {
                b[x0-1][y0-1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=y0-1;
            }
            if(b[x0+1][y0-1]>b[x0][y0]+1 && b[x0+1][y0-1]!=-1 && y0-1>0 && x0+1>0)
            {
                b[x0+1][y0-1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=y0-1;
            }
            if(b[x0-1][y0+1]>b[x0][y0]+1 && b[x0-1][y0+1]!=-1 && y0+1>0 && x0-1>0)
            {
                b[x0-1][y0+1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=y0+1;
            }
        }
    }
    inc=0; sf=0;
    v[sf].x=c1;
    v[sf].y=c2;
    while(!vid())
    {
        if(f[v[inc].x][v[inc].y]!=-1)
        {
            x0=v[inc].x;
            y0=v[inc].y;
            inc++;
            if(f[x0+1][y0]>f[x0][y0]+1 && f[x0+1][y0]!=-1 && x0+1>0)
            {
                f[x0+1][y0]=f[x0][y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=y0;
            }
            if(f[x0-1][y0]>f[x0][y0]+1 && f[x0-1][y0]!=-1 && x0-1>0)
            {
                f[x0-1][y0]=f[x0][y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=y0;
            }
            if(f[x0][y0+1]>f[x0][y0]+1 && f[x0][y0+1]!=-1 && y0+1>0)
            {
                f[x0][y0+1]=f[x0][y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=y0+1;
            }
            if(f[x0][y0-1]>f[x0][y0]+1 && f[x0][y0-1]!=-1 && y0-1>0)
            {
                f[x0][y0-1]=f[x0][y0]+1;
                sf++;
                v[sf].x=x0;
                v[sf].y=y0-1;
            }
            if(b[x0+1][y0+1]>b[x0][y0]+1 && b[x0+1][y0+1]!=-1 && y0+1>0 && x0+1>0)
            {
                b[x0+1][y0+1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=y0+1;
            }
            if(b[x0-1][y0-1]>b[x0][y0]+1 && b[x0-1][y0-1]!=-1 && y0-1>0 && x0-1>0)
            {
                b[x0-1][y0-1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=y0-1;
            }
            if(b[x0+1][y0-1]>b[x0][y0]+1 && b[x0+1][y0-1]!=-1 && y0-1>0 && x0+1>0)
            {
                b[x0+1][y0-1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0+1;
                v[sf].y=y0-1;
            }
            if(b[x0-1][y0+1]>b[x0][y0]+1 && b[x0-1][y0+1]!=-1 && y0+1>0 && x0-1>0)
            {
                b[x0-1][y0+1]=b[x0][y0]+1;
                sf++;
                v[sf].x=x0-1;
                v[sf].y=y0+1;
            }
        }
    }
    tmin=65536;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j]==f[i][j] && b[i][j]<tmin && b[i][j]!=-1)
            {
                tmin=b[i][j];
                x0=i;
                y0=j;
            }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<f[i][j]<<" ";
        cout<<endl;
    }
    out<<x0<<" "<<y0<<" "<<tmin<<" ";
    return 0;
}
