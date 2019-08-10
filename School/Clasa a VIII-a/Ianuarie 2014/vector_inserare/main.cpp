#include <iostream>
#include <fstream>
using namespace std;
ifstream in("vector_inserare.in");
ofstream out("vector_inserare.out");
int n,i,v[101],x,m;
int main()
{
    in>>n;
    in>>m;
    in>>x;
    for (i=1;i<=n;i++)
    {
        in>>v[i];
    }
    n=n+1;
    for (i=n;i>=m;i--)
    {
        v[i]=v[i-1];
    }
    v[m]=x;
    for (i=1;i<=n;i++)
    {
        out<<v[i]<<"; ";
    }
    return 0;
}
