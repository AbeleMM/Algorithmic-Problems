#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lacusta.in");
ofstream out("lacusta.out");
short int n,m,v[255][255];
short int i,j;
int sol[3][255];
int main()
{
    in>>n>>m;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            in>>v[i][j];

    /*mn=v[1][1];
    i=1,j=1;
    while(i!=n-1){
        smin=256;
        for(k=1;k<j;++k)
            if(v[i][k]+v[i+1][k]<smin)
                smin=v[i][k]+v[i+1][k],jj=k;
         for(k=j+1;k<=m;++k)
            if(v[i][k]+v[i+1][k]<smin)
                smin=v[i][k]+v[i+1][k],jj=k;
        mn+=smin,++i,j=jj;
    }

    smin=256;
    for(k=1;k<j;++k)
        if(v[i][k]+v[i+1][k]<smin)
            smin=v[i][k]+v[i+1][k],jj=k;
    for(k=j+1;k<m;++k)
        if(v[i][k]+v[i+1][k]<smin)
            smin=v[i][k]+v[i+1][k],jj=k;
    mn+=smin,++i,j=jj;

    mn+=v[n][m];*/

    for(j=1;j<=m;++j)
            sol[1][j]=v[1][j];
    short int l=1,cl;
    int val;
    for(i=2;i<n;++i){
        val=127501;
        for(j=1;j<l;++j){
            sol[2][j]=sol[1][l]+v[i-1][j]+v[i][j];
            if(sol[2][j]<val)
                val=sol[2][j],cl=j;
        }
        for(j=l+1;j<=m;++j){
            sol[2][j]=sol[1][l]+v[i-1][j]+v[i][j];
            if(sol[2][j]<val)
                val=sol[2][j],cl=j;
        }
        for(j=1;j<=m;++j)
            sol[1][j]=sol[2][j];
        l=cl;
    }

    i=n;
    val=127501;
    for(j=1;j<l;++j){
        sol[2][j]=sol[1][l]+v[i-1][j]+v[i][j];
        if(sol[2][j]<val)
            val=sol[2][j],cl=j;
    }
    for(j=l+1;j<m;++j){
        sol[2][j]=sol[1][l]+v[i-1][j]+v[i][j];
        if(sol[2][j]<val)
            val=sol[2][j],cl=j;
    }

    out<<sol[2][l]+v[n][m];
    return 0;
}
