#include <iostream>
#include <fstream>
using namespace std;
ifstream in("foto.in");
ofstream out("foto.out");
int f[103][103],mx,n,m,nr;
void fill(int x, int y)
{
    if(f[x][y]==0 && x>0 && x<=n && y>0 && y<=m)
    {
        f[x][y]=2;
        nr++;
        fill(x+1,y);
        fill(x,y+1);
        fill(x-1,y);
        fill(x,y-1);
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            in>>f[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j]==0)
            {
                nr=0;
                fill(i,j);
                if(nr>mx)
                    mx=nr;
            }
    out<<mx;
    return 0;
}
