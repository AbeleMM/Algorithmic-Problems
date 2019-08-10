#include <iostream>
#include <fstream>
using namespace std;
ifstream in("casa.in");
ofstream out("casa.out");
int p,n,m,t,nr;
struct casa
{
    int x;
    int y;
}v[10001];
int grid[1001][1001];
char c;
/*int mutare(int x, int y)
{
    for (int i=1;i<=;i++)
}*/
void cerinta1()
{
    int a; char b;
    in>>t;
    v[1].x=1; v[1].y=1;
    grid[1][1]=1;
    for(int i=2;i<=t;i++)
    {
        in>>a>>b;
        v[i].x=v[a].x;
        v[i].y=v[a].y;
        if(b=='N')
            v[i].x--;
        if(b=='S')
            v[i].x++;
        if(b=='E')
            v[i].y++;
        if(b=='V')
            v[i].y--;
        grid[v[i].x][v[i].y]=1;
        if(v[i].x>n)
            n=v[i].x;
        if(v[i].y>m)
            m=v[i].y;
    }
    out<<n<<" "<<m<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            out<<grid[i][j]<<" ";
        }
        out<<"\n";
    }
}
void cerinta2()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            in>>grid[i][j];
            nr+=grid[i][j];
        }
    }
}
int main()
{
    in>>p;
    if(p==1)
        cerinta1();
    if(p==2)
        cerinta2();
    return 0;
}
