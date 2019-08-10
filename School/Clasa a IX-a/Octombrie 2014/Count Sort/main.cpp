#include <iostream>
#include <fstream>
using namespace std;
    int C[8];
    int U[8];
int main()
{
    int i,k,n;
    int V[8]={1,4,2,1,2,7,6,0};
    k=7;
    n=7;
    for (i=0;i<=n-1;i++)
    {
        C[V[i]]=C[V[i]]+1;
    }
    for (i=1;i<=k;i++)
    {
        C[i]=C[i]+C[i-1];
    }
    for (i=1;i<=n;i++)
    {
        U[C[V[i]]-1]=V[i];
        C[V[i]]=C[V[i]]-1;
    }
    for (i=1;i<=n;i++)
    {
        cout<<U[i]<<" ";
    }
    return 0;
}
