#include <iostream>
#include <fstream>
using namespace std;
ifstream in("post.in");
ofstream out("post.out");
int p,n,m,v[100001],stiva[100001],vf;
struct nod{
    int vecin;
    struct nod *urm;
}*l[100001],*q,*lalt[100001];
bool viz[100001];
long long s=0,mn,c=1,nr;
void df(int k){
    struct nod *q;
    viz[k]=true;
    q=l[k];
    while(q!=NULL){
        if(viz[q->vecin]==false)
            df(q->vecin);
        q=q->urm;
    }
    ++vf;
    stiva[vf]=k;
}
void dfalt(int k){
    if(v[k]<mn){
        mn=v[k];
        nr=1;
    }
    else if(v[k]==mn)
        ++nr;
    struct nod *q;
    viz[k]=true;
    q=lalt[k];
    while(q!=NULL){
        if(viz[q->vecin]==false)
            dfalt(q->vecin);
        q=q->urm;
    }
}
int main()
{
    in>>p>>n;
    for(int i=1;i<=n;++i)
        in>>v[i];
    in>>m;
    int a,b;
    for(int i=1;i<=m;++i){
        in>>a>>b;
        q=new nod;
        q->vecin=b;
        q->urm=l[a];
        l[a]=q;

        q=new nod;
        q->vecin=a;
        q->urm=lalt[b];
        lalt[b]=q;
    }
    for(int i=1;i<=n;++i)
        if(viz[i]==false)
            df(i);

    for(int i=1;i<=n;++i)
        viz[i]=false;

    while(vf>0){
        if(viz[stiva[vf]]==false){
            mn=1000000001,nr=1;
            dfalt(stiva[vf]);
            s+=mn;
            c=(c*nr)%1000000007;
        }
        --vf;
    }
    if(p==1)
        out<<s;
    else
        out<<c;
    return 0;
}
