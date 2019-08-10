//Sortare prin selectie
#include <iostream>
//Sortare prin selectie
#include <fstream>
using namespace std;
ifstream in("sortare.in");
ofstream out("sortare.out");
int n,v[1000],i,j,aux;
int main()
{
    aux=0;
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>v[i];
    }
    for (i=1;i<=n;i++)
    {

        for (i=1;i<n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                if (v[i]>v[j])
                {
                    aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        out<<v[i]<<"; ";
    }
    return 0;
}
