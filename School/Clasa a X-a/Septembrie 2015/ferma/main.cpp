#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ferma1.in");
ofstream out("ferma1.out");
int v,nr,mx,n,m;
int aux[403][403],s,p1,p2;
char f[404][404],c;
struct tabel{
    int r;
    char e;
} t[160016];



//int ok, xt;



void fill(int x, int y)
{
    if(f[x][y]==c)
    {
        nr++;
        f[x][y]='1';
        fill(x+1,y);
        fill(x,y+1);
        fill(x-1,y);
        fill(x,y-1);
    }
}
void var1()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j]!='1')
            {
                nr=0;
                c=f[i][j];
                fill(i,j);
                if(nr>mx)
                    mx=nr;
            }
    out<<mx;
}
void fill2(int xz,int yz)
{
    if(f[xz][yz]==t[nr].e)
    {
        aux[xz][yz]=nr;
        s++;
        f[xz][yz]='1';
        fill2(xz+1,yz);
        fill2(xz,yz+1);
        fill2(xz-1,yz);
        fill2(xz,yz-1);
    }
}
void var2()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j]!='1')
            {
                nr++;
                s=0;
                t[nr].e=f[i][j];
                fill2(i,j);
                t[nr].r=s;




                /*if(s>mx){
                    mx=s;
                    xt=nr;
                }*/
           }



    /*int i=1; int j=1;
    while(i<=n && ok!=1)
        while(j<=m)
            if(aux[i][j]!=nr)
            {
                p1=i; p2=j;
                c=t[aux[i][j]].e;
                ok=1;
                break;
            }*/




    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(t[aux[i][j-1]].e==t[aux[i-1][j]].e && t[aux[i][j]].e!=t[aux[i][j-1]].e && t[aux[i][j]].r!=t[aux[i][j-1]].r && t[aux[i][j-1]].r!=t[aux[i-1][j]].r){
                s=t[aux[i][j-1]].r+t[aux[i-1][j]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i][j-1]].e;
                }
            }
            if(t[aux[i][j-1]].e==t[aux[i][j+1]].e && t[aux[i][j]].e!=t[aux[i][j-1]].e && t[aux[i][j]].r!=t[aux[i][j-1]].r && t[aux[i][j-1]].r!=t[aux[i][j+1]].r){
                s=t[aux[i][j-1]].r+t[aux[i][j+1]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i][j-1]].e;
                }
            }
            if(t[aux[i][j-1]].e==t[aux[i+1][j]].e && t[aux[i][j]].e!=t[aux[i][j-1]].e && t[aux[i][j]].r!=t[aux[i][j-1]].r && t[aux[i][j-1]].r!=t[aux[i+1][j]].r){
                s=t[aux[i][j-1]].r+t[aux[i+1][j]].r+1;
                 if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i][j-1]].e;
                }
            }

            if(t[aux[i-1][j]].e==t[aux[i][j+1]].e && t[aux[i][j]].e!=t[aux[i-1][j]].e && t[aux[i][j]].r!=t[aux[i-1][j]].r && t[aux[i-1][j]].r!=t[aux[i][j+1]].r){
                s=t[aux[i-1][j]].r+t[aux[i][j+1]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i-1][j]].e;
                }
            }
            if(t[aux[i-1][j]].e==t[aux[i+1][j]].e && t[aux[i][j]].e!=t[aux[i-1][j]].e && t[aux[i][j]].r!=t[aux[i-1][j]].r && t[aux[i-1][j]].r!=t[aux[i+1][j]].r){
                s=t[aux[i-1][j]].r+t[aux[i+1][j]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i-1][j]].e;
                }
            }

            if(t[aux[i][j+1]].e==t[aux[i+1][j]].e && t[aux[i][j]].e!=t[aux[i][j+1]].e && t[aux[i][j]].r!=t[aux[i][j+1]].r && t[aux[i][j+1]].r!=t[aux[i+1][j]].r){
                s=t[aux[i][j+1]].r+t[aux[i+1][j]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i][j+1]].e;
                }
            }
            if(t[aux[i][j-1]].r==t[aux[i+1][j]].r && t[aux[i+1][j]].r==t[aux[i][j+1]].r && t[aux[i][j+1]].r==t[aux[i+1][j]].r && t[aux[i][j]].r!=t[aux[i][j-1]].r){
                s=t[aux[i][j-1]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i][j-1]].e;
                }
            }

            if(t[aux[i][j-1]].e==t[aux[i-1][j]].e && t[aux[i-1][j]].e==t[aux[i][j+1]].e && t[aux[i][j-1]].r!=t[aux[i-1][j]].r && t[aux[i-1][j]].r!=t[aux[i][j+1]].r && t[aux[i][j-1]].r!=t[aux[i][j+1]].r){
                s=t[aux[i][j-1]].r+t[aux[i-1][j]].r+t[aux[i][j+1]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i][j-1]].e;
                }
            }
            if(t[aux[i-1][j]].e==t[aux[i][j+1]].e && t[aux[i][j+1]].e==t[aux[i+1][j]].e && t[aux[i-1][j]].r!=t[aux[i][j+1]].r && t[aux[i][j+1]].r!=t[aux[i+1][j]].r && t[aux[i-1][j]].r!=t[aux[i+1][j]].r){
                s=t[aux[i-1][j]].r+t[aux[i][j+1]].r+t[aux[i+1][j]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i-1][j]].e;
                }
            }
            if(t[aux[i][j+1]].e==t[aux[i+1][j]].e && t[aux[i+1][j]].e==t[aux[i][j-1]].e && t[aux[i][j+1]].r!=t[aux[i+1][j]].r && t[aux[i+1][j]].r!=t[aux[i][j-1]].r && t[aux[i][j+1]].r!=t[aux[i][j-1]].r){
                s=t[aux[i][j+1]].r+t[aux[i+1][j]].r+t[aux[i][j-1]].r+1;
                if(s>mx){
                    mx=s;
                    p1=i; p2=j;
                    c=t[aux[i][j+1]].e;
                }
            }

        }
    out<</*mx<<"\n"<<*/p1<<" "<<p2<<"\n"<<c;
}
int main()
{
    in>>v>>n>>m;
    for (int i=1;i<=n;i++)
        in>>f[i]+1;
    if(v==1)
        var1();
    if(v==2)
        var2();
    return 0;
}
