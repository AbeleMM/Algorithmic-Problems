#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n,m,elem;
map <int,int> v;
struct film{
    int a;
    int nra;
    int c;
    int nrc;
};
vector <film> f(200001);
int ans,mxa,mxc;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>elem;
        if(v.find(elem)!=v.end()){
            v[elem]++;
        }
        else{
            v.insert({elem,1});
        }
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>f[i].a;
        if(v.find(f[i].a)!=v.end()){
            f[i].nra=v[f[i].a];
        }
    }
    for(int i=1;i<=m;++i){
        cin>>f[i].c;
        if(v.find(f[i].c)!=v.end()){
            f[i].nrc=v[f[i].c];
        }
    }
    ans=1,mxa=f[1].nra,mxc=f[1].nrc;
    for(int i=2;i<=m;++i){
        if(f[i].nra>mxa){
            ans=i;
            mxa=f[i].nra;
            mxc=f[i].nrc;
        }
        else if(f[i].nra==mxa && f[i].nrc>mxc){
            ans=i;
            mxc=f[i].nrc;
        }
    }
    cout<<ans;
    return 0;
}
