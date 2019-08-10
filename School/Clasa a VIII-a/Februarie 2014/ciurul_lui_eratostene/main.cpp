#include <iostream>
using namespace std;
unsigned int n,i,j,nr,p[105];
int main()
{
    cout<<"Introduceti valoarea: ";
    cin>>n;
    cout<<"\n";
    nr=1;
    for (i=3;i<=n;i+=2)
    {
        if (p[i]==0)
        {
            nr++;
        }
        for (j=i*i;j<=n;j+=2*i)
        {
            p[j]=1;
        }
    }
    cout<<"Numarul de numere prime este: "<<nr<<".";
    cout<<"\n";
    for (i=3;i<=n;i+=2)
    {
        if (p[i]==0)
        {
            cout<<i<<"; ";
        }
    }
    return 0;
}
