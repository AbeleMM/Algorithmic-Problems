#include <iostream>
#include <fstream>
using namespace std;
ifstream in("joc.in");
ofstream out("joc.out");
short int n,m,k;
bool graf[51][51],viz[51];
int nrcc;
void df(int k){
    viz[k]=true;
    for(int i=1;i<=n;++i)
        if(viz[i]==false && graf[k][i]==true)
            df(i);
}
unsigned long long comb(int n,int k){
    unsigned long long s=1;
    if(n-k>k)
        k=n-k;
    for(int i=n;i>k;--i){
        s*=i;
        s/=(n-i)+1;
    }
    return s;
}
int main()
{
    in>>n>>m>>k;
    int a,b;
    for(int i=1;i<=k;++i){
        in>>a>>b;
        graf[a][b]=true;
        graf[b][a]=true;
    }
    for(int i=1;i<=n;++i)
        if(viz[i]==false){
            ++nrcc;
            df(i);
        }
    if(k<nrcc || k>n)
        out<<"0";
    else
        out<<comb(m,k-nrcc);
    return 0;
}
