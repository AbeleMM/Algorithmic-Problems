#include <iostream>
#include <fstream>
using namespace std;
ifstream in("monkey.in");
ofstream out("monkey.out");
int r,c,mx,tabla[22][22],k,sol[441];
bool v[28];
struct traseu
{
    int x,y;
}tr[441];
char t;
int dx[]={0,1,-1,0,0}, dy[]={0,0,0,1,-1};
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
    v[tabla[tr[k-1].x][tr[k-1].y]]=false;
    return 0;
}
int valid(int k)
{

    if(tabla[tr[k].x][tr[k].y]==0)
        return 0;
    if(v[tabla[tr[k].x][tr[k].y]]==true)
        return 0;
    v[tabla[tr[k].x][tr[k].y]]=true;
    return 1;
}
int solutie(int k)
{
    if(v[tabla[tr[k].x+1][tr[k].y]]==1 && v[tabla[tr[k].x-1][tr[k].y]]==1 && v[tabla[tr[k].x][tr[k].y+1]]==1 && v[tabla[tr[k].x][tr[k].y-1]]==1)
        return 1;
    return 0;
}
void prelucrare(int k)
{
    if(k>mx)
        mx=k;
    v[tabla[tr[k].x][tr[k].y]]=false;
}
void bk(int k)
{
    init(k);
    while(succesor(k))
        if(valid(k))
        {
            if(solutie(k))
                prelucrare(k);
            else
                bk(k+1);
        }
}
int main()
{
    in>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        {
            in>>t;
            tabla[i][j]=t-64;
        }
    tr[0].x=1; tr[0].y=1;
    v[0]=true;
    v[tabla[1][1]]=true;
    bk(1);
    out<<mx+1;
    return 0;
}
