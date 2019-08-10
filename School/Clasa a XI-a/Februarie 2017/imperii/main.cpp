#include <iostream>
#include <fstream>
#define inf 1002001
using namespace std;
ifstream in("imperii.in");
ofstream out("imperii.out");
int n,m;
char t;
struct harta{
    int val;
    char imp;
}h[1002][1002];
int inc,sf;
struct labirint{
    int x;
    int y;
}v[inf];

void lee(int xo,int yo,char c){
    inc=sf=0;
    v[sf].x=xo,v[sf].y=yo;
    while(inc<=sf)
        if(h[v[inc].x][v[inc].y].val!=-1){
            xo=v[inc].x,yo=v[inc].y;
            if(h[xo+1][yo].val>=h[xo][yo].val+1 && h[xo+1][yo].val!=-1 && xo+1<=n){
                if(h[xo+1][yo].val==h[xo][yo].val+1 && h[xo+1][yo].imp!=h[xo][yo].imp)
                    h[xo+1][yo].imp='-';
                else{
                    h[xo+1][yo].val=h[xo][yo].val+1,h[xo+1][yo].imp=c;
                    ++sf,v[sf].x=xo+1,v[sf].y=yo;
                }
            }

            if(h[xo-1][yo].val>=h[xo][yo].val+1 && h[xo-1][yo].val!=-1 && xo+1>0){
                if(h[xo-1][yo].val==h[xo][yo].val+1 && h[xo-1][yo].imp!=h[xo][yo].imp)
                    h[xo-1][yo].imp='-';
                else{
                    h[xo-1][yo].val=h[xo][yo].val+1,h[xo-1][yo].imp=c;
                    ++sf,v[sf].x=xo-1,v[sf].y=yo;
                }
            }

            if(h[xo][yo+1].val>=h[xo][yo].val+1 && h[xo][yo+1].val!=-1 && yo+1<=m){
                if(h[xo][yo+1].val==h[xo][yo].val+1 && h[xo][yo+1].imp!=h[xo][yo].imp)
                    h[xo][yo+1].imp='-';
                else{
                    h[xo][yo+1].val=h[xo][yo].val+1,h[xo][yo+1].imp=c;
                    ++sf,v[sf].x=xo,v[sf].y=yo+1;
                }
            }

            if(h[xo][yo-1].val>=h[xo][yo].val+1 && h[xo][yo-1].val!=-1 && yo-1>0){
                if(h[xo][yo-1].val==h[xo][yo].val+1 && h[xo][yo-1].imp!=h[xo][yo].imp)
                    h[xo][yo-1].imp='-';
                else{
                    h[xo][yo-1].val=h[xo][yo].val+1,h[xo][yo-1].imp=c;
                    ++sf,v[sf].x=xo,v[sf].y=yo-1;
                }
            }

            ++inc;
        }
}

int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            in>>t;
            h[i][j].imp=t;
            if(t=='-')
                h[i][j].val=inf;
            if(t=='#')
                h[i][j].val=-1;
        }

    lee(1,1,h[1][1].imp);
    lee(1,m,h[1][m].imp);
    lee(n,1,h[n][1].imp);
    lee(n,m,h[n][m].imp);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            out<<h[i][j].imp;
        out<<"\n";
    }
    return 0;
}
