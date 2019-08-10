#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ctc.in");
ofstream out("ctc.out");
int n,m,x,y,nr;
struct nod{
    int vecin;
    struct nod *urm;
}*l[200001],*actual,*lt[200001];
bool viz[100001];
int stiva[100001],vf;

void df1(int k){
    struct nod *actual;
    viz[k]=true;
    actual=l[k];
    while(actual!=NULL){
        if(viz[actual->vecin]==false)
            df1(actual->vecin);
        actual=actual->urm;
    }
    ++vf,stiva[vf]=k;
}
void df2(int k,bool ok){
    struct nod *actual;
    if(ok==true)
        out<<k<<" ";
    viz[k]=true;
    actual=lt[k];
    while(actual!=NULL){
        if(viz[actual->vecin]==false)
            df2(actual->vecin,ok);
        actual=actual->urm;
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i){
        in>>x>>y;
        actual=new nod;
        actual->vecin=y;
        actual->urm=l[x];
        l[x]=actual;

        actual=new nod;
        actual->vecin=x;
        actual->urm=lt[y];
        lt[y]=actual;
    }
    for(int i=1;i<=n;++i)
        if(viz[i]==false)
            df1(i);

    for(int i=1;i<=n;++i)
        viz[i]=false;
    /*for(int i=1;i<=vf;++i)
        out<<stiva[i]<<" ";*/
    for(int i=vf;i>=1;--i)
        if(viz[stiva[i]]==false)
            ++nr,df2(stiva[i],false);
    out<<nr<<"\n";
    for(int i=1;i<=n;++i)
        viz[i]=false;
    for(int i=vf;i>=1;--i)
        if(viz[stiva[i]]==false)
            df2(stiva[i],true),out<<"\n";
    return 0;
}
