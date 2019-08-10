#include <iostream>
#include <fstream>
//#include <stdio.h>
using namespace std;
/*FILE * in=fopen("bond.in","r");
FILE * out=fopen("bond.out","w");*/
ifstream in("bond.in");
ofstream out("bond.out");
int n,m;
char s[103][103];
int nri,nrmx,alt,alta,v[10005];
void qs(int st, int dr)
{
    int i=st,j=dr,t;
    int x=v[i+(j-i)/2];
    while(i<=j){
        while(i<dr && v[i]<x)
            i++;
        while(j>st && v[j]>x)
            j--;
        if(i<=j)
        {
            t=v[i];
            v[i]=v[j];
            v[j]=t;
            i++;
            j--;
        }
    }
    if(st<j)
        qs(st,j);
    if(i<dr)
        qs(i,dr);
}
void filo(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m){
        if(s[x][y]=='o'){
            s[x][y]='x';
            filo(x+1,y);
            filo(x,y+1);
            filo(x-1,y);
            filo(x,y-1);
        }
    }
}
void fil(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m){
        if(s[x][y]=='x'){
            ++alt;
            s[x][y]='X';
            fil(x+1,y);
            fil(x,y+1);
            fil(x-1,y);
            fil(x,y-1);
        }
        if(s[x][y]=='o'){
            ++alt;
            ++alta;
            s[x][y]='X';
            filo(x+1,y);
            filo(x,y+1);
            filo(x-1,y);
            filo(x,y-1);
            fil(x+1,y);
            fil(x,y+1);
            fil(x-1,y);
            fil(x,y-1);
        }
    }
}
int main()
{
    /*fscanf(in,"%d %d",&n,&m);*/
    in>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            /*fscanf(in,"%c",&s[i][j]);*/
            in>>s[i][j];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(s[i][j]=='x'){
                alt=0;
                alta=0;
                ++nri;
                fil(i,j);
                /*for(int i=0;i<n;++i){
                    for(int j=0;j<m;++j)
                        out<<s[i][j]<<" ";
                    out<<endl;
                }
                out<<endl<<endl;*/
                if(alt>nrmx)
                    nrmx=alt;
                v[nri]=alta;
            }
        }
    }
    qs(1,nri);
    /*fprintf(out,"%d\n%d\n",nri,nrmx);*/
    out<<nri<<"\n"<<nrmx<<"\n";
    for(int i=1;i<=nri;++i)
        /*fprintf(out,"%d ",v[i]);*/
        out<<v[i]<<" ";
    return 0;
}
