#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,a[15][15],b[15][15];
struct drum{
    int x;
    int y;
}v[225];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(b[i-1][j]>b[i][j-1])
                b[i][j]=b[i-1][j]+a[i][j];
            else
                b[i][j]=b[i][j-1]+a[i][j];
        }
    out<<"Valoarea maxima este: "<<b[n][m]<<"\n \n";
    int nr=0;
    v[nr].x=n,v[nr].y=m;
    while(v[nr].x!=1 || v[nr].y!=1){
        if(b[v[nr].x-1][v[nr].y]>b[v[nr].x][v[nr].y-1]){
            v[nr+1].x=v[nr].x-1;
            v[nr+1].y=v[nr].y;
            ++nr;
        }
        else{
            v[nr+1].x=v[nr].x;
            v[nr+1].y=v[nr].y-1;
            ++nr;
        }
    }
    for(int i=nr;i>=0;--i){
        out<<"("<<v[i].x<<";"<<v[i].y<<") ";
    }
    out<<"\n";
    return 0;
}
