#include <iostream>

using namespace std;

int main()
{
    int x,y,S1,S2;
    cout<<"Introduceti primul numar de trei cifre: ";
    cin>>x;
    cout<<endl;
    cout<<"Introduceti cel de al doilea numar de trei cifre: ";
    cin>>y;
    cout<<endl;
    S1=x%10+x/10%10+x/100;
    S2=y%10+y/10%10+x/100;
    if (S1>S2)
        cout<<"Suma cifrelor primului numar este mai mare, avand valoarea:"<<S1<<endl;
    else
        cout<<"Suma cifrelor celui de al doilea numar este mai mare, avand valoarea:"<<S2<<endl;
    return 0;
}
