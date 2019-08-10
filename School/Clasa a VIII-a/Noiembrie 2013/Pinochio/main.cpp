#include <iostream>

using namespace std;

int main()
{
    int n,i,k,p;
    cout<<"Introduceti lungimea initiala: ";
    cin>>n;
    cout<<endl;
    cout<<"Introdceti nmarul de cm: ";
    cin>>p;
    cout<<endl;
    cout<<"Introuceti numarul de zile: ";
    cin>>k;
    cout<<endl;
    i=1;
    while (i<=k)
    {
        if (i%7==0 || i%7==6)
            n=n-1;
        else
            n=n+p;
    i=i+1;
    }

    cout<<"Lungimea nasului este de: "<<n<<"cm;"<<endl;

    return 0;
}
