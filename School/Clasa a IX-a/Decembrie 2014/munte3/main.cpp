#include <iostream>
#include <fstream>
using namespace std;
ifstream in("munte3.in");
ofstream out("munte3.out");
int n,nrt,aux;
long v[104];
void citire()
{
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>v[i];
    }
}
void muntificare()
{
    int i,j;
    for(i=2;i<=n-1;i++)
    {
        if(v[i-1]<v[i] && v[i]>v[i+1])
        {
            nrt++;
            for(j=i;j<=n;j++)
            {

                v[j]=v[j+1];
            }
            n--;
        }
    }
}
void afisare()
{
    out<<nrt<<"\n"<<n<<"\n";
}
int main()
{
    citire();
    muntificare();
    out<<nrt<<"\n";
    do
    {
        aux=nrt;
        muntificare();
    }
    while(aux<nrt);
    afisare();
    return 0;
}
