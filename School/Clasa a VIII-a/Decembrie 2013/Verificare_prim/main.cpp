#include <iostream>

using namespace std;

int main()
{
    //Se citeste un numar natural de la tastarura. Sa se stabileasca daca acesta este prim.
    int n,d,S;
    cout<<"Introduceti valoarea numarului: ";
    cin>>n;
    cout<<endl;
    S=0;
    d=2;
    while (d<=n/2)
    {
        if (n%d==0)
        S++;
        d++;
    }
    if (S==0)
    {
        cout<<"Numarul este prim!";
    }
    else
    {
        cout<<"Numarul nu este prim!";
    }
    return 0;
}
