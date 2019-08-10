#include <iostream>

using namespace std;

int main()
{
    int S,uc,n;
    cout<<"Introduceti numarul: ";
    cin>>n;
    cout<<endl;
    S=0;
    while (n>0)
    {
        uc=n%10;
        n=n/10;
        if (uc%2==0)
        S=S+uc;
    }
    cout<<"Suma cifrelor pare este: "<<S<<"."<<endl;
    return 0;
}
