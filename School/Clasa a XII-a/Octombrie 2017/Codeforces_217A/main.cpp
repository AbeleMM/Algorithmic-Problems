#include <iostream>

using namespace std;
struct coord{
    unsigned int x;
    unsigned int y;
}v[101];
bool graf[101][101],viz[101];
int n,nrcc;
void df(int k){
    viz[k]=true;
    for(int i=1;i<=n;++i)
        if(graf[k][i]==true && viz[i]==false)
            df(i);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i].x>>v[i].y;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j){
            if(v[i].x==v[j].x or v[i].y==v[j].y)
                graf[i][j]=graf[j][i]=true;
        }
    for(int i=1;i<=n;++i)
        if(viz[i]==false){
            ++nrcc;
            df(i);
        }
    cout<<nrcc-1;
    return 0;
}
