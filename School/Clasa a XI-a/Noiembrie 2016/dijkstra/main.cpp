#include <iostream>
#include <fstream>
#define inf 1002001
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int n,p,c[102][102],val1,val2,val3;
int d[102],mn,x;
bool viz[102],ok=true;
void dijkstra(int p){
    for(int i=1;i<=n;++i)
        d[i]=c[p][i]; // copiem a k-a linie din matrice in vect de dist.
    viz[p]=true;
    while(ok==true){ // pana cand nu mai exista un nou minim
        mn=inf; // initializam dist minima a unui element nevizitat din vectorul dist;
        ok=false;
        for(int j=1;j<=n;++j)
            if(viz[j]==false && mn>d[j]){
                x=j; // actualizam nodul la care dist din k este minima
                mn=d[j];
                ok=true; // exista minim
            }
        viz[x]=true;
        for(int j=1;j<=n;++j)
            if(viz[j]==false && d[j]>d[x]+c[x][j]) // daca distanta prin x este mai mica
                d[j]=d[x]+c[x][j];
    }
}
int main()
{
    in>>n>>p; // nr noduri & nodul de la care calculam distantele
    // initializam graful cu +infinit
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
                if(i!=j)
                    c[i][j]=inf;
    while(!in.eof()){
        in>>val1>>val2>>val3;
        c[val1][val2]=val3;
    }
    dijkstra(p);
    for(int i=1;i<=n;++i)
    {
        if(d[i]!=inf)
            out<<d[i]<<" ";
        else
            out<<"-1 ";
    }
    return 0;
}
