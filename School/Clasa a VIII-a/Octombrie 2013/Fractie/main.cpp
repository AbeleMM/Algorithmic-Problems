#include <iostream>

using namespace std;

int main()
{
    int a,b,k;
    cout<<"Introduceti numaratorul: ";
    cin>>a;
    cout<<endl;
    cout<<"Introduceti numitorul: ";
    cin>>b;
    cout<<endl;
    cout<<"Introduceti variabila: ";
    cin>>k;
    cout<<endl;
    if (a%k==0 && b%k==0)
    {
        cout<<"Fractia se poate simplifica."<<endl;
        cout<< a/k<<"/"<<b/k<<endl;
    }
    else
    {
        cout<<"Fractia nu se poate simplifica!";
    }
    cout<<endl;
    return 0;
}
