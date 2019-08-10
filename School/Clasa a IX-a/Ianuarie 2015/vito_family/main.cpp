#include <iostream>

using namespace std;
int t,v[503],nr,s,mijl;
void citire()
{
    cin>>nr;
    for(int i=1;i<=nr;++i)
    {
        cin>>v[i];
    }
}
void sortare()
{
    int aux;
    for(int i=1;i<=nr-1;++i)
    {
        for(int j=i+1;j<=nr;++j)
        {
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}
void prelucrare()
{
    s=0;
    mijl=nr/2+1;
    for(int i=1;i<mijl;++i)
    {
        s=s+v[mijl]-v[i];
    }
    for(int i=mijl+1;i<=nr;i++)
    {
        s=s+v[i]-v[mijl];
    }
}
void afisare()
{
    cout<<s<<"\n";
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        citire();
        sortare();
        prelucrare();
        afisare();
    }
    return 0;
}
