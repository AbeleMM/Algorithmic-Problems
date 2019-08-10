#include <iostream>
#include <fstream>
using namespace std;
ifstream in("soarece.in");
ofstream out("soarece.out");
int n,m,lab[13][13],is,js,ib,jb,sol[121],k,nr;
struct traseu{
    int x,y;
}tr[121];
int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
void init(int k)
{
    sol[k]=0;
}
int succesor(int k)
{
    if(sol[k]<4){
        sol[k]++;
        tr[k].x=tr[k-1].x+dx[sol[k]];
        tr[k].y=tr[k-1].y+dy[sol[k]];
        return 1;
    }
    return 0;
}
int valid(int k)
{
    if(lab[tr[k].x][tr[k].y]==1)
        return 0;
    for(int i=0;i<k;i++)
        if(tr[i].x==tr[k].x && tr[i].y==tr[k].y)
            return 0;
    return 1;
}
int solutie(int k)
{
    if(tr[k].x==ib && tr[k].y==jb)
        return 1;
    return 0;
}
void bk(int k)
{
    init(k);
    while(succesor(k))
        if(valid(k))
        {
            if(solutie(k))
                nr++;
            else
                bk(k+1);
        }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            in>>lab[i][j];
    in>>is>>js>>ib>>jb;
    for(int i=0;i<=n+1;i++)
    {
        lab[i][0]=1;
        lab[i][m+1]=1;
    }
    for(int j=0;j<=m+1;j++)
    {
        lab[0][j]=1;
        lab[n+1][j]=1;
    }
    tr[0].x=is;tr[0].y=js;
    bk(1);
    out<<nr;
    return 0;
}
