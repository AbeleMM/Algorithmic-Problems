#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,k,v[1005],mat[1005][101];
char fin[101];
bool ant[101],cur[101];
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
        in>>v[i], v[i]=v[i]%k;
    ant[v[1]]=true, ant[k-v[1]]=true;
    mat[1][v[1]]=+1, mat[1][k-v[1]]=-1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<k;++j){
            if(ant[j]==true){
                cur[(j+v[i])%k]=true, mat[i][(j+v[i])%k]=+j;
                if(j-v[i]<0)
                    cur[k+(j-v[i])]=true, mat[i][k+(j-v[i])]=-j;
                else
                    cur[j-v[i]]=true, mat[i][j-v[i]]=-j;
            }
        }
        for(int j=0;j<k;++j)
            ant[j]=cur[j];
        for(int j=0;j<k;++j)
            cur[j]=false;
    }
    /*for(int i=0;i<k;++i)
        out<<ant[i]<<"  ";*/
    /*for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j)
            out<<mat[i][j]<<" ";
        out<<"\n";
    }*/
    if(ant[0]==false)
        out<<"IMPOSIBIL";
    else{
        int nr=0,i=n,j=0;
        while(nr<n){
            ++nr;
            if(mat[i][j]>=0){
                fin[nr]='+';
                j=mat[i][j];
            }
            else{
                fin[nr]='-';
                j=-mat[i][j];
            }
            --i;
        }
        for(int i=n;i>=1;--i)
            out<<fin[i]<<" ";
    }
    return 0;
}
