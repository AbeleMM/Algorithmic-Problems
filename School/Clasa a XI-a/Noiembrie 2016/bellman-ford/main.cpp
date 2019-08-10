#include <iostream>
#include <fstream>
#include <queue>
#define inf 65536
using namespace std;
ifstream in("bellmanford.in");
ofstream out("bellmanford.out");
int n,m;
int elem, d[50001], viz[50001]; // elem - pt. primul element din coada + distante(sol) + vector vizitat
queue <int> coada;
struct nod{
    int vecin;
    int val;
    struct nod *urm;
}*l[50001],*actual;
bool bellmanford(int k){

    for(int i=1; i<=n; ++i)
        d[i]=inf; // initializez distantele cu +inf
    d[k]=0;
    coada.push(k); // pun in coada elementul sursa
    ++viz[k];

    while( !coada.empty() ){ //cat timp exista elemente in coada
        elem = coada.front();

        for(actual = l[elem]; actual != NULL; actual = actual->urm) // parcurgem vecinii nodului din inceputul cozii
            if(actual->val + d[elem] < d[actual->vecin]){ // daca drumul prin elem din inceputul cozii este mai scurt
                // atribuim noul minim
                d[actual->vecin] = actual->val + d[elem];
                // adaugam in coada
                coada.push(actual->vecin);
                // crestem nr de vizite
                ++viz[actual->vecin];
                // daca am vizitat de n-1 ori rezulta ciclu infinit
                if(viz[actual->vecin] == n-1)
                    return false;
            }
        coada.pop();
    }
    return true; // nu exista ciclu
}
int main()
{
    in>>n>>m;
    int x, y, valt;
    for(int i=1; i<=m; ++i){
        in>>x>>y>>valt;
        actual = new nod;
        actual->vecin=y;
        actual->urm=l[x];
        actual->val=valt;
        l[x]=actual;
    }
    bool ok = bellmanford(1);
    if(ok==false)
        out<<"Ciclu negativ!";
    else
        for(int i=2;i<=n;i++)
            out<<d[i]<<" ";
    return 0;
}
