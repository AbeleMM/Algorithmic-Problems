#include <iostream>
#include <fstream>
using namespace std;
ifstream in("dfs.in");
ofstream out("dfs.out");
short int n,m,x;//nr. de noduri, muchii, vf. din care incepe parcurgerea
bool v[102][102],viz[102];//matrice de adiacenta + noduri vizitate
void df(int k){
    out<<k<<" ";
    viz[k]=true;
    for(short int i=1;i<=n;++i)
        if(v[k][i]==true && viz[i]==false)
            df(i);
}
int main()
{
    in>>n>>m>>x;
    for(short int i=1;i<=m;++i){
        short int val1,val2;
        in>>val1>>val2;
        v[val1][val2]=true;
        v[val2][val1]=true;
    }
    df(x);
    return 0;
}
