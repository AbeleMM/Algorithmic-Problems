#include <iostream>
#include <fstream>
using namespace std;
ifstream in("DOMINO.IN");
ofstream out("DOMINO.OUT");
int n,mx;
struct piese{
    int x;
    int y;
}v[100001];
int ant[10][10],cur[10][10];
inline int maxx(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
inline void ca(){
    for(int i=0;i<=9;++i)
        for(int j=0;j<=9;++j)
            cur[i][j]=ant[i][j];
}
inline void ac(){
    for(int i=0;i<=9;++i)
        for(int j=0;j<=9;++j)
            ant[i][j]=cur[i][j];
}

void afis(int a){
    out<<v[a].x<<" "<<v[a].y<<":\n";
    for(int i=0;i<=9;++i){
        for(int j=0;j<=9;++j)
            out<<cur[i][j]<<" ";
        out<<"\n";
    }
    out<<"\n";
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>v[i].x>>v[i].y;
    ant[v[1].x][v[1].y]=1;
    for(int i=2;i<=n;++i){
        ca();
        for(int j=0;j<=9;++j)
            for(int k=0;k<=9;++k){
                if(ant[j][k]!=0){
                    if(v[i].x==j)
                        cur[v[i].y][k]=maxx(ant[j][k]+1,cur[v[i].y][k]);

                    else if(v[i].y==j)
                        cur[v[i].x][k]=maxx(ant[j][k]+1,cur[v[i].x][k]);


                    if(v[i].x==k)
                        cur[j][v[i].y]=maxx(ant[j][k]+1,cur[j][v[i].y]);

                    else if(v[i].y==k)
                        cur[j][v[i].x]=maxx(ant[j][k]+1,cur[j][v[i].x]);
                }
            }

        ac();
    }
    for(int i=0;i<=9;++i)
        for(int j=0;j<=9;++j)
            if(ant[i][j]>mx)
                mx=ant[i][j];
    out<<mx;
    return 0;
}
