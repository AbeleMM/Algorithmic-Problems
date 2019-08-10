#include <iostream>
#include <fstream>
using namespace std;
ifstream in("dfs.in");
ofstream out("dfs.out");
int n,m,x,y,nr;
struct nod{
    int vecin;
    struct nod *urm;
}*l[100001],*actual;
bool viz[100001];
void df(int k){
    struct nod *actual; //declaram un pointer local
    viz[k]=true;
    actual=l[k];
    while(actual!=NULL){
        if(viz[actual->vecin]==false)
            df(actual->vecin);
        actual=actual->urm;
    }
}
int main()
{
    in>>n>>m;
    //adaugam elementele in lista
    for(int i=1;i<=m;++i){
        in>>x>>y;
        actual=new nod;
        actual->vecin=y;
        actual->urm=l[x];
        l[x]=actual;

        actual=new nod;
        actual->vecin=x;
        actual->urm=l[y];
        l[y]=actual;
    }
    //determinam nr de componente conexe
    for(int i=1;i<=n;++i)
        if(viz[i]==false){
            df(i);
            ++nr;
        }
    out<<nr;
    return 0;
}
