#include <iostream>

using namespace std;

int main()
{
    int n,S,i,nr;
    S=0;
    cout<<"Introduceti numarul de valori de citit: ";
    cin>>n;
    cout<<endl;
    for (i=1;i<=n;i++)
    {
        cout<<"Introduceti o valoare: ";
        cin>>nr;
        cout<<endl;

        if (S%2==0)
        {
            S=S+nr;
        }
    }
    cout<<"Suma este: "<<S<<endl;
    return 0;
}
