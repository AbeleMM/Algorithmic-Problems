#include <iostream>

using namespace std;

int main()
{
    float a,b;
    int c;
    cout<<"Introduceti prima variablia: ";
    cin>>a;
    cout<<endl;
    cout<<"Introduceti cea de-a doua variabila: ";
    cin>>b;
    cout<<endl;
    c=a;
    while (c<=b)
    {
        cout<<c<<" ";
        c=c+1;
    }
    return 0;
}
