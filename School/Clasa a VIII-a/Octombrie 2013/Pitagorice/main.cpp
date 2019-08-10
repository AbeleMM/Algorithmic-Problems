#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cout<<"Introduceti primul numar: ";
    cin>>a;
    cout<<"Introduceti al doilea numar: ";
    cin>>b;
    cout<<"Introduceti al treilea numar: ";
    cin>>c;
    if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
    {
        cout<<"Numerele sunt pitagorice!";
    }
    else
    {
        cout<<"Numerele nu sunt pitagorice!";
    }
    return 0;
}
