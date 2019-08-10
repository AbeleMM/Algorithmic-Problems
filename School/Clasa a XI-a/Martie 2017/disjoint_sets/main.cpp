#include <iostream>
#include <fstream>
using namespace std;
ifstream in("disjoint.in");
ofstream out("disjoint.out");
int n,m,tata[100001],rang[100001];
int t,a,b;
void make_set(int x){
    tata[x]=x;
    rang[x]=1;
}
int find_set(int x){
    int rad/*acina*/,alt;
    for(rad=x;tata[rad]!=rad;rad=tata[rad]){
    }

    while(tata[x]!=x){
        alt=tata[x];
        tata[x]=rad;
        x=alt;
    }
    return rad;
}
void unite(int x,int y){
    if(rang[x]<rang[y])
        tata[x]=y;
    else
        tata[y]=x;
    if(rang[x]==rang[y])
        ++rang[x];
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        make_set(i);
    for(int i=1;i<=m;++i){
        in>>t>>a>>b;
        if(t==2){
            if(find_set(a)==find_set(b))
                out<<"DA\n";
            else
                out<<"NU\n";
        }
        else if(t==1)
            unite(find_set(a),find_set(b));
    }
    return 0;
}
