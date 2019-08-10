//kruskal
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("apm.in");
ofstream out("apm.out");
int n,m,s,nr;
struct muchie{
    int x;
    int y;
    int c;
}v[400001];

struct mte{
    int val;
    struct mte *urm;
}*l[200001],*cur;

int mt[200001], sol[200001];
//
inline bool crit(struct muchie a,struct muchie b){
    return a.c<b.c;
}
void kruskal(){
    for(int i=1;i<=n;i++)
        mt[i]=i;//initializez toate nodurile cu prorpria lor multime

    for(int i=1;i<=n;++i){
        cur=new mte;
        cur->val=i;
        cur->urm=l[i];
        l[i]=cur;
    }
    for(int i=1;i<=m && nr<n-1;++i)
        if(mt[v[i].x]!=mt[v[i].y]){
            int mn,mx;
            if(mt[v[i].x]<mt[v[i].y])
                mn=mt[v[i].x],mx=mt[v[i].y];
            else
                mn=mt[v[i].y],mx=mt[v[i].x];
            for(cur=l[mx];cur->urm!=NULL;cur=cur->urm)
                mt[cur->val]=mn;
            mt[cur->val]=mn;
            cur->urm=l[mn];
            l[mn]=l[mx];
            l[mx]=NULL;
            ++nr;
            s+=v[i].c;
            sol[nr]=i;
        }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
        in>>v[i].x>>v[i].y>>v[i].c;
    sort(v+1,v+m+1,crit);//sortare
    kruskal();
    out<<s<<"\n"<<nr<<"\n";
    for(int i=1;i<=nr;++i)
        out<<v[sol[i]].y<<" "<<v[sol[i]].x<<"\n";
    return 0;
}
