#include <iostream>
#include <fstream>
using namespace std;
ifstream in("arme.in");
ofstream out("arme.out");
int n,m,i,j,s;
int v[2010];
int aux;
int main()
{
    in>>n>>m;
    for(i=1;i<=n+m;i++)
    {
        in>>v[i];
    }
    for(i=1;i<=n+m-1;i++)
    {
        for(j=i+1;j<=n+m;j++)
        {
            if(v[i]<v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        s=s+v[i];
    }
    out<<s;
    return 0;
}
