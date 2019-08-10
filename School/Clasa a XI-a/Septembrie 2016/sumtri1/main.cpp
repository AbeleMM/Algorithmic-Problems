#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sumtri1.in");
ofstream out("sumtri1.out");
int v[102][102],n,mn,alt[102][102],jalt=1;
void fct(int i,int j){
    if(i!=1 || j!=1){
        if(j==1)
            fct(i-1,j);
        else if(j==i)
            fct(i-1,j-1);
        else if(v[i-1][j-1]<v[i-1][j])
            fct(i-1,j-1);
        else
            fct(i-1,j);
    }
    out<<alt[i][j]<<" ";
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            in>>alt[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            v[i][j]=alt[i][j];

    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j){
            if(j==1)
                v[i][j]+=v[i-1][j];
            else if(j==i)
                v[i][j]+=v[i-1][j-1];
            else if(v[i-1][j-1]<v[i-1][j])
                v[i][j]+=v[i-1][j-1];
            else
                v[i][j]+=v[i-1][j];
        }
    mn=v[n][1];
    for(int i=2;i<=n;++i)
        if(v[n][i]<mn)
            mn=v[n][i],jalt=i;
    out<<mn<<"\n";
    fct(n,jalt);
    return 0;
}
