#include <iostream>

using namespace std;

int main()
{
    int n,uc,S;
    cout<<"Introduceti valoarea: ";
    cin>>n;
    cout<<endl;
    S=0;
    while (n>0)
    {
        uc=n%10;
        n=n/10;
        S=S+uc;
    }
    cout<<"Suma cifrelor este: "<<S<<endl;
    return 0;
}
