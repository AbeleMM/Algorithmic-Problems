#include <iostream>

using namespace std;

int main()
{
    float a,b;
    int c;
    cout<<"Introduceti prima variabila: ";
    cin>>a;
    cout<<endl;
    cout<<"Introduceti cea de-a doua variabila: ";
    cin>>b;
    cout<<endl;
    c=a;
    while (c<=b)
    {
        if (c%2==0)
        cout<<c<<" ";
        c=c+1;
    }
    return 0;
}
