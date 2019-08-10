#include <iostream>
#include <fstream>
using namespace std;
ifstream in("vector_prim.in");
ofstream out ("vector_prim.out");
int n,nr,i,v[101],d;
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>v[i];
    }
    for (i=1;i<=n;i++)
    {
        d=2;
        nr=0;
        while (d*d<=v[i] && nr==0)
        {
            if (v[i]%d==0)
            {
                nr=nr+1;
            }
        d=d+1;
        }
        if (nr==0)
        {
            out<<v[i]<<"; ";
        }
    }

    return 0;
}
