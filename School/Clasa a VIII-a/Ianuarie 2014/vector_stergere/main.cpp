#include <iostream>
#include <fstream>
using namespace std;
ifstream in("vector_stergere.in");
ofstream out ("vector_stergere.out");
int n,v[101],m,i;
int main()
{
    in>>n;
    in>>m;
    for (i=1;i<=n;i++)
    {
        in>>v[i];
    }
    n=n-1;
    for (i=m;i<=n;i++)
    {
        v[i]=v[i+1];
    }
    for (i=1;i<=n;i++)
    {
        out<<v[i]<<"; ";
    }
    return 0;
}
