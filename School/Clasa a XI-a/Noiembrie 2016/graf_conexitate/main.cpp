#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,nrcc;//nrcc - nr componente conexe
bool v[102][102],viz[102];
void df(int k){
    //++nr;
    viz[k]=true;
    for(int i=1;i<=n;++i)
        if(v[k][i]==true && viz[i]==false)
            df(i);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i){
        int val1,val2;
        in>>val1>>val2;
        v[val1][val2]=true;
        v[val2][val1]=true;
    }

    for(int i=1;i<=n;++i)
        if(viz[i]==false){
            ++nrcc;
            df(i);
        }

    if(nrcc==1)
        out<<"CONEX \n";
    else{
        out<<"NU CONEX \n"<<nrcc<<"\n";
    }
    return 0;
}
