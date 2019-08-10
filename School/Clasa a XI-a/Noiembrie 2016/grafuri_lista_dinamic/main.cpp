#include <iostream>
#include <fstream>
#define mx 100001
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,x,y;
struct nod{
    int vecin;
    struct nod *urm;
}*l[mx],*actual;

bool viz[mx];
void df(int k){
    struct nod *actual;
    out<<k<<" ";
    viz[k]=true;
    actual=l[k];
    while(actual!=NULL){
        if(viz[actual->vecin]==false)
            df(actual->vecin);
        actual=actual->urm;
    }
}

int c[mx],inc=1,sf=1;
void bf(int k){

}
int main()
{
    in>>n>>m;
    //daca NU declarat golbal
    /*for(int i=1;i<=n;++i)
        l[i]->urm=NULL;*/
    for(int i=1;i<=m;++i){
        in>>x>>y;//citim capetele muchiei
        //adaugam y la lista x
        actual=new nod;
        actual->vecin=y;
        actual->urm=l[x];
        l[x]=actual;
        //adaugam x la lista y
        actual=new nod;
        actual->vecin=x;
        actual->urm=l[y];
        l[y]=actual;
    }
    //afisare
    for(int i=1;i<=n;++i){
        out<<i<<": ";
        actual=l[i];
        while(actual!=NULL){
            out<<actual->vecin<<" ";
            actual=actual->urm;
        }
        out<<"\n";
    }
    out<<"\n";

    df(1);
    out<<"\n\n";

    for(int i=1;i<=mx;++i)
        viz[i]=false;

    bf(1);
    return 0;
}
