#include <iostream>
#include <fstream>
using namespace std;
ifstream in("BFS.in");
ofstream out("BFS.out");
short int n,m,x;//nr. de noduri, muchii,vf. din care incepe parcurgerea
bool v[102][102],viz[102];//matrice de adiacenta + noduri vizitate
short int c[102],inc=1,sf=1;//coada
int main()
{
    in>>n>>m>>x;
    for(short int i=1;i<=m;++i){
        int val1,val2;
        in>>val1>>val2;
        v[val1][val2]=true;
        v[val2][val1]=true;
    }
    c[sf]=x;
    viz[x]=true;
    while(inc<=sf){
        for(short int i=1;i<=n;++i)
            if(v[c[inc]][i]==true && viz[i]==false){
                ++sf;
                c[sf]=i;
                viz[i]=true;
            }
        ++inc;
    }
    for(short int i=1;i<=sf;++i)
        out<<c[i]<<" ";
    return 0;
}
