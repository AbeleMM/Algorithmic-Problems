#include <iostream>
#include <fstream>
using namespace std;
ifstream in("balcon.in");
ofstream out("balcon.out");
int n;
int v[2525];
int m[55][55];
int B[2525],C[2525];
int i,j,k,nr;
void citire()
{
    int i;
    in>>n;
    for (i=1;i<=n*n;i++)
    {
        in>>v[i];
    }
}
void sortare()
{
    k=0;
    for(i=1;i<=n*n;i++)
    {
        if(k<v[i])
        {
            k=v[i];
        }
    }
    for (i=1;i<=n*n;i++)
    {
        B[v[i]]=B[v[i]]+1;
    }
    for (i=1;i<=k;i++)
    {
        B[i]=B[i]+B[i-1];
    }
    for (i=1;i<=n*n;i++)
    {
        C[B[v[i]]]=v[i];
        B[v[i]]=B[v[i]]-1;
    }
}
void matrice_spirala()
{
    int k,p,nr;
    nr=1;
    if(n%2==0)
    {
        p=n/2;
    }
    else
    {
        p=n/2+1;
    }
    for(k=1;k<=p;k++)
    {
        for(i=k;i<=n-k+1;i++)
        {
            m[k][i]=C[nr];
            nr++;
        }
        for(i=k+1;i<=n-k+1)
        {
            m[i][n-k+1]=C[nr];
            nr++;

        }
        for (i=n+k;i=>k;i--)
        {
            a[n-k+1][i]=C[nr];
            nr++;
        }
        for (i=n-k;i=>k+1;i--)
        {
            a[i][k]= C[nr];
            nr++;
        }
    }
}
void afisare()
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            out<<m[i][j]<<" ";
        }
        out<<"\n";
    }
}
int main()
{
    citire();
    sortare();
    matrice_spirala();
    afisare();
    return 0;
}
