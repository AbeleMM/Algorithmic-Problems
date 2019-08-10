#include <iostream>

using namespace std;

int main()
{
    int n,uc,P;
    cout<<"Introduceti numarul: ";
    cin>>n;
    cout<<endl;
    P=1;
    while (n>0)
    {
        uc=n%10;
        n=n/10;
        if (uc!=0)
            P=P*uc;
    }
    cout<<"Produsul este: "<<P<<"."<<endl;
    return 0;
}
