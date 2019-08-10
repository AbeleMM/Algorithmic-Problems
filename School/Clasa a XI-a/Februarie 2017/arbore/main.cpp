#include <iostream>
#include <fstream>
using namespace std;
ifstream in("arbore.in");
ofstream out("arbore.out");
int n,k,p[101];
bool mat[101][101],viz[101];
void bf(int k,int t){
    viz[k]=true;
    p[k]=t;
    for(int i=1;i<=n;++i)
        if(mat[k][i]==true && viz[i]==false)
            bf(i,k);
}
int main()
{
    in>>n>>k;
    int a,b;
    for(int i=1;i<n;++i){
        in>>a>>b;
        mat[a][b]=true;
        mat[b][a]=true;
    }
    bf(k,0);
    for(int i=1;i<=n;++i)
        out<<p[i]<<" ";
    return 0;
}
