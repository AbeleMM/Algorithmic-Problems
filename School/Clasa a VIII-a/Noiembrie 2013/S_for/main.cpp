#include <iostream>

using namespace std;

int main()
{
    int n;//numarul de valori care se citesc
    int S;//suma numerelor
    int i;//variablia contor
    int nr;//numarul citit
    S=0;
    cout<<"Introduceti numarul de valori ce se vor citi: ";
    cin>>n;//citim numarul de valori care se introduc
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"Introduceti o valoare: ";
        cin>>nr;//citim o valoare
        cout<<endl;
        S=S+nr;
    }
    cout<<"Suma este: "<<S<<"."<<endl;
    return 0;
}
