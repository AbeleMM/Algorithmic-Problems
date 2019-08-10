#include <iostream>
#include <fstream>
using namespace std;
ifstream in("volei.in");
ofstream out("volei.out");
int n,m,b[2005];
struct volei{
    int h;
    bool f;
    struct volei *urm;
}*prim,*ultim,*p,*poz,*q;
void qs(int st, int dr){
    int i=st,j=dr,t;
    int x=b[i+(j-i)/2];
    while(i<=j){
        while(i<dr && b[i]<x)
            i++;
        while(j>st && b[j]>x)
            j--;
        if(i<=j)
        {
            t=b[i];
            b[i]=b[j];
            b[j]=t;
            i++;
            j--;
        }
    }
    if(st<j)
        qs(st,j);
    if(i<dr)
        qs(i,dr);
}
int main()
{
    in>>n;
    prim=new volei;
    prim->urm=NULL;
    in>>prim->h;
    prim->f=true;
    ultim=prim;
    for(int i=2;i<=n;++i)
    {
        p=new volei;
        in>>p->h;
        p->urm=NULL;
        p->f=true;
        ultim->urm=p;
        ultim=p;
    }
    /*p=prim;
    while(p!=NULL)
    {
        out<<p->h<<" ";
        p=p->urm;
    }*/
    in>>m;
    for(int i=1;i<=m;++i)
        in>>b[i];
    qs(1,m);
    /*for(int i=1;i<=m;++i)
        out<<b[i]<<" ";*/
    int i=m;
    bool ok=true;
    int nr=0;
    while(i>=1 && ok==true && nr<n)
    {
        int s=0;
        ok=false;
        if(ultim->h<b[i] && prim->h<b[i]){
            ok=true;
            s=ultim->h+prim->h;
            q=ultim;
        }
        p=prim;
        while(p->urm!=NULL)
        {
            if(p->h+p->urm->h>s && p->h<b[i] && p->urm->h<b[i]){
                ok=true;
                s=p->h+p->urm->h;
                q=p;
            }
            p=p->urm;
        }
        if(ok==true){
            ++nr;
            p=new volei;
            p->h=b[i];
            p->f=false;
            p->urm=q->urm;
            q->urm=p;
        }
        --i;
    }
    out<<nr<<"\n";
    p=prim;
    while(p!=NULL)
    {
        if(p->f==false)
            out<<"("<<p->h<<") ";
        else
            out<<p->h<<" ";
        p=p->urm;
    }
    return 0;
}
