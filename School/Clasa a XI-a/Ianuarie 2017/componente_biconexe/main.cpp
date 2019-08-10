#include <iostream>
#include <fstream>
using namespace std;
ifstream in("biconex.in");
ofstream out("biconex.out");
int n,m,vf,nr;
struct nod{
    int vecin;
    struct nod *urm;
}*l[100001],*q;//graf - lista de adiacenta
struct muchii{
    int x;
    int y;
}stiva[200001];// retinem muchiile
int niv[100001],nivmin[100001],p[100001];//nivelul pe care se afla un nod, nivelul minim la care revine un descendent al unui nod, parintele unui nod
bool viz[100001];//marcam nodurile vizitate din graf

inline int minim(int &a, int &b){
    if(a<b)
        return a;
    else
        return b;
}
void df(int k, int ni){
    struct nod *q;
    viz[k]=true;
    niv[k]=ni;
    nivmin[k]=ni;
    q=l[k];
    int cop=0;// nr de copii
    while(q!=NULL){
        int i=q->vecin;
        if(viz[i]==false){
            p[i]=k;
            ++cop;
            ++vf;
            stiva[vf].x=k;
            stiva[vf].y=i;
            df(i,ni+1);
            nivmin[k]=minim(nivmin[k],nivmin[i]);
            //
            if((p[k]==0 && cop>1) || (p[k]!=0 && nivmin[k]>=niv[k])){
                ++nr;
                while(!(stiva[vf].x==k && stiva[vf].y==i) || !(stiva[vf].x==i && stiva[vf].y==k)){
                    out<<"("<<stiva[vf].x<<" ; "<<stiva[vf].y<<") ";
                    vf--;
                }
                out<<"("<<stiva[vf].x<<" ; "<<stiva[vf].y<<") ";
                vf--;
                out<<"\n";
            }
        }
        else if(p[k]!=i)
            nivmin[k]=minim(nivmin[k],niv[i]);
        q=q->urm;
    }
}
int main()
{
    in>>n>>m;
    int a,b;
    for(int i=1;i<=m;++i){
        in>>a>>b;
        q=new nod;
        q->vecin=b;
        q->urm=l[a];
        l[a]=q;
        q=new nod;
        q->vecin=a;
        q->urm=l[b];
        l[b]=q;
    }

    //test formare liste
    /*for(int i=1;i<=n;++i){
        q=l[i];
        out<<i<<": ";
        while(q!=NULL){
            out<<q->vecin<<" ";
            q=q->urm;
        }
        out<<"\n";
    }*/

    for(int i=1;i<=n;++i)
        if(viz[i]==false){
            df(i,1);
            if(vf>0){
                ++nr;
                while(vf>0){
                    out<<"("<<stiva[vf].x<<" ; "<<stiva[vf].y<<") ";
                    vf--;
                }
                out<<"\n";
            }
        }
    out<<nr;
    return 0;
}
