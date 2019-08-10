#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,x,y,niv[1001]/*nivelul unui nod*/,p[1001]/*parintele unui nod*/,nmin[1001]/*nivelul minim pe care revine un descendent cu o muchie de revenire*/;
struct nod{
    int vecin;
    struct nod *urm;
}*l[1001],*q;
bool viz[1001];
inline int minim(int &a, int &b){
    if(a<=b)
        return a;
    else
        return b;
}
void df(int k,int ni){
    struct nod *q;
    viz[k]=true;
    niv[k]=ni;
    nmin[k]=ni;
    q=l[k];
    int cop=0;
    while(q!=NULL){
        int j=q->vecin;
        if(viz[j]==false){
            p[j]=k;
            ++cop;
            df(j,ni+1);
            nmin[k]=minim(nmin[k],nmin[j]);
            if(p[k]==0 && cop>1)
                out<<k<<" ";
            else if(nmin[k]>=niv[k])
                    out<<k<<" ";
        }
        else if(j!=p[k])
            nmin[k]=minim(nmin[k],niv[j]);
        q=q->urm;
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i){
        in>>x>>y;
        q=new nod;
        q->vecin=y;
        q->urm=l[x];
        l[x]=q;
        q=new nod;
        q->vecin=x;
        q->urm=l[y];
        l[y]=q;
    }
    df(1,1);
    return 0;
}
