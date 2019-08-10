#include <iostream>

using namespace std;

int main()
{
    int n,uc;
    cout<<"Introduceti numarul: ";
    cin>>n;
    cout<<endl;
    while (n>0)//cat timp numarul are cifre
    {
        uc=n%10;//calcule: ultima cifra
        cout<<"Una dintre cifre este: "<<uc<<"."<<endl;// prelucrez ultima cifra
        n=n/10;//elimin ultima cifra
    }
    return 0;
}
