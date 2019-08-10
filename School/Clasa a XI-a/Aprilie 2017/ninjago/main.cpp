#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("ninjago.in");
ofstream out("ninjago.out");
int p,n,m;
char sir[6];
//p 1
int a,b,ne;
struct nod{
    int vecin;
    struct nod *urm;
}*l[31201],*cur;
bool viz[31201];
//p 2&3
int fct,s,te,nr;
long long salt;
struct muchie{
    int x,y,c,e;
}v[31201];
struct mte{
    int val;
    struct mte *urm;
}*l2[31201],*cur2;
int mt[31201];
//
void df(int x,int &ne){
    viz[x]=true;
    ++ne;
    for(struct nod *cur=l[x];cur!=NULL;cur=cur->urm)
        if(viz[cur->vecin]==false)
            df(cur->vecin,ne);
}
//
inline bool crit(struct muchie a,struct muchie b){
    if(a.e!=b.e)
        return a.e<b.e;
    else
        return a.c<b.c;
}
void kruskal(){
    for(int i=1;i<=n;++i){
        mt[i]=i;
        cur2=new mte;
        cur2->val=i;
        cur2->urm=l2[i];
        l2[i]=cur2;
    }
    int mn,mx;
    for(int i=1;i<=m && nr<n-1;++i)
        if(mt[v[i].x]!=mt[v[i].y]){
            if(mt[v[i].x]<mt[v[i].y])
                mn=mt[v[i].x],mx=mt[v[i].y];
            else
                mn=mt[v[i].y],mx=mt[v[i].x];

            for(cur2=l2[mx];cur2->urm!=NULL;cur2=cur2->urm)
                mt[cur2->val]=mn;
            mt[cur2->val]=mn;
            cur2->urm=l2[mn];
            l2[mn]=l2[mx];
            l2[mx]=NULL;
            ++nr,s+=v[i].e,salt+=v[i].c;
            if(v[i].e>0)
                ++te;
        }
}
int main()
{
    in>>p>>n>>m;
    if(p==1){
        for(int i=1;i<=m;++i){
            in>>a>>b>>sir;
            ne=0;
            for(int i=0;i<=3;++i)
                if(sir[i]=='E')
                    ++ne;
            if(ne==0){
                cur=new nod;
                cur->vecin=b;
                cur->urm=l[a];
                l[a]=cur;

                cur=new nod;
                cur->vecin=a;
                cur->urm=l[b];
                l[b]=cur;
            }
        }
        ne=0;
        df(1,ne);
        out<<ne;
    }
    else{
        for(int i=1;i<=m;++i){
            in>>v[i].x>>v[i].y>>sir;
            fct=1;
            for(int j=0;j<=3;++j){
                if(sir[j]=='E')
                    ++v[i].e;
                else
                    v[i].c+=(sir[j]-'A'+1)*fct;
                fct*=5;
            }
        }
        sort(v+1,v+m+1,crit);
        kruskal();
        if(p==2)
            out<<te<<"\n"<<s;
        else
            out<<salt;
    }
    return 0;
}
