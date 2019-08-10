#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sortaret.in");
ofstream out("sortaret.out");
int n,m,x,y;
struct nod{
    int vecin;
    struct nod *urm;
}*l[50001],*actual;
bool viz[50001];
int sol[50001],nr;
void df(int k){
    struct nod *actual;
    viz[k]=true;
    actual=l[k];
    while(actual!=NULL){
        if(viz[actual->vecin]==false)
            df(actual->vecin);
        actual=actual->urm;
    }
    //dupa ce vizitam toti vecinii nodului k
    //adaugam unei stive
    ++nr;
    sol[nr]=k;
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
    }

    for(int i=1;i<=n;++i)
        if(viz[i]==false)
            df(i);

    for(int i=nr;i>=1;--i)
        out<<sol[i]<<" ";

    //verificare

    /*for(int i=1;i<=n;++i){
        actual=l[i];
        out<<i<<": ";
        while(actual!=NULL){
            out<<actual->vecin<<" ";
            actual=actual->urm;
        }
        out<<"\n";
    }*/
    return 0;
}
