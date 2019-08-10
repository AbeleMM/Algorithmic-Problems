#include <iostream>
#include <fstream>
using namespace std;
ifstream in("avioane.in");
ofstream out("avioane.out");
int t,n,m,joc[27][27],nr;
char aux;
struct actiuni
{
    int x;
    int y;
}a[627];
void citire()
{
    in>>t>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            in>>joc[i][j];
    in>>m;
    for(int i=1;i<=m;i++)
    {
        in>>aux>>a[i].y;
        a[i].x=aux-'A'+1;
    }
}
void prelucrare1()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(joc[i][j]==1)
                nr++;
    nr=nr/10;
}
void prelucrare2()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(joc[i][j]==1 && ((joc[i+3][j+1]==1 && joc[i+3][j-1]==1) || (joc[i-3][j+1]==1 && joc[i-3][j-1]==1) || (joc[i-1][j+3]==1 && joc[i+1][j+3]==1) || (joc[i+1][j-3]==1 && joc[i-1][j-3]==1)))
                joc[i][j]=2;
    for(int i=1;i<=m;i++)
        if(joc[a[i].x][a[i].y]==2)
            nr++;
}
int main()
{
    citire();
    if(t==1)
        prelucrare1();
    if(t==2)
        prelucrare2();
    out<<nr;
    in.close();
    out.close();
    return 0;
}
