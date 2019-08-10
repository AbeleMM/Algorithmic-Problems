#include <iostream>

using namespace std;

int main()
{
    int x;
    cout<<"Introduceti valoarea puterii: ";
    cin>>x;
    cout<<endl;
    if (x==0)
    {
        cout<<"Valoarea ultimei cifre este 1!";
    }
    else
    if (x%4==1)
    {
        cout<<"Valoarea utlimei cifre este 2!";
    }
    else
    if (x%4==2)
    {
        cout<<"Valoarea ultimei cifre este 4!";
    }
    else
    if (x%4==3)
    {
        cout<<"Valoarea ultimei cifre este 8!";
    }
    else
    if (x%4==0)
    {
        cout<<"Valoarea ultimei cifre este 6!";
    }
    return 0;
}
