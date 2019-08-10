#include <iostream>

using namespace std;
int d,n,m[13][99];
int nmx,kmx;
struct intrare{
    int n;
    int k;
}v[11];
void inv(int n,int k){
    m[1][0]=1;
    for(int i=2;i<=n;++i){
        m[i][0]=1;
        m[i][1]=i-1;
    }
    for(int i=3;i<=n;++i)
        for(int j=2;j<=k;++j)
            for(int l=j;l>+j-i;--l)
                m[i][j]+=m[i-1][l];
}
int main()
{
    cin>>d;
    for(int i=1;i<=d;++i){
        cin>>v[i].n>>v[i].k;
        if(v[i].n>nmx)
            nmx=v[i].n;
        if(v[i].k>kmx)
            kmx=v[i].k;
    }
    inv(nmx,kmx);
    /*for(int i=1;i<=nmx;++i){
        for(int j=0;j<=kmx;++j)
            cout<<m[i][j]<<" ";
        cout<<"\n";
    }*/
    for(int i=1;i<=d;++i)
        cout<<m[v[i].n][v[i].k]<<"\n";
    return 0;
}
