#include <iostream>
#include <stdio.h>
using namespace std;
FILE * in=fopen("panda.in","r");
FILE * out=fopen("panda.out","w");
int p,n,m,T,L,C,K,S,v[505][505];
int x,Smin,nt;
int sf,inc;
struct food
{
    int x;
    int y;
}b[250025];
struct labirint
{
    int x;
    int y;
}r[250025];
int vid(){
    if(inc>sf)
        return 1;
    else
        return 0;
}
void punct_1(){
    fscanf(in,"%i %i %i %i %i %i %i",&n,&m,&T,&L,&C,&K,&S);
    for(int i=1;i<=T;++i)
        fscanf(in,"%i %i",&b[i].x,&b[i].y);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            fscanf(in,"%i",&v[i][j]);
            if(((K&((1<<S)-1))^(v[i][j]&((1<<S)-1)))==((1<<S)-1))
                ++x;
    }
    if(((K&((1<<S)-1))^(v[L][C]&((1<<S)-1)))==((1<<S)-1))
            fprintf(out,"%i",x-1);
        else
            fprintf(out,"%i",x);
}
void punct_2(){
    fscanf(in,"%i %i %i %i %i %i %i",&n,&m,&T,&L,&C,&K,&S);
    for(int i=1;i<=T;++i)
        fscanf(in,"%i %i",&b[i].x,&b[i].y);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            fscanf(in,"%i",&v[i][j]);
            if(((K&((1<<S)-1))^(v[i][j]&((1<<S)-1)))==((1<<S)-1))
                v[i][j]=255025;
            else
                v[i][j]=-1;
    }
    for(int i=0;i<=n+1;i++)
        v[i][0]=-1,v[i][m+1]=-1;
    for(int i=0;i<=m+1;i++)
        v[0][i]=-1,v[n+1][i]=-1;
    v[L][C]=0;
    r[inc].x=L;
    r[inc].y=C;
    while(!vid())
        if(v[r[inc].x][r[inc].y]!=-1){
            L=r[inc].x;
            C=r[inc].y;
            ++inc;
            if(v[L+1][C]>v[L][C]+1 && v[L+1][C]!=-1)
                v[L+1][C]=v[L][C]+1,++sf,r[sf].x=L+1,r[sf].y=C;
            if(v[L-1][C]>v[L][C]+1 && v[L-1][C]!=-1)
                v[L-1][C]=v[L][C]+1,++sf,r[sf].x=L-1,r[sf].y=C;
            if(v[L][C+1]>v[L][C]+1 && v[L][C+1]!=-1)
                v[L][C+1]=v[L][C]+1,++sf,r[sf].x=L,r[sf].y=C+1;
            if(v[L][C-1]>v[L][C]+1 && v[L][C-1]!=-1)
                v[L][C-1]=v[L][C]+1,++sf,r[sf].x=L,r[sf].y=C-1;
        }
    Smin=255025;
    for(int i=1;i<=T;i++){
        if(v[b[i].x][b[i].y]<Smin && v[b[i].x][b[i].y]>-1)
            Smin=v[b[i].x][b[i].y],nt=0;
        if(v[b[i].x][b[i].y]==Smin)
            ++nt;
    }
    fprintf(out,"%i %i",Smin,nt);
}
int main()
{
    fscanf(in,"%i",&p);
    if(p==1)
        punct_1();
    if(p==2)
        punct_2();
    return 0;
}
