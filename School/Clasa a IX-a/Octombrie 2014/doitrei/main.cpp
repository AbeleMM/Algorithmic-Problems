#include <iostream>
#include <fstream>
using namespace std;
ifstream in("doitrei.in");
ofstream out("doitrei.out");
int N,i;
int p[207];
void citire()
{
     in>>N;
}
void prelucrare()
{
    p[1]=5;
    p[2*N-1]=9;
    p[N]=2;
    for(i=2;i<=N-1;i++)
    {
        p[i]=4;
    }
    for(i=N+1;i<=2*N-2;i++)
    {
        p[i]=8;
    }
}
void afisare()
{
    for(i=1;i<=2*N-1;i++)
    {
        out<<p[i];
    }
}
int main()
{
    citire();
    prelucrare();
    afisare();
    return 0;
}
