#include <iostream>

using namespace std;

int main()
{
    int n,uc,inv,m;
    cout<<"Introduceti numarul: ";
    cin>>n;
    cout<<endl;
    n=m;
    inv=0;
    while(n>0)
    {
        uc=n%10;
        inv=inv*10+uc;
        n=n/10;
    }
    if (m==inv)
    {
        cout<<"Numarul este palindrom!";
    }
    else
    {
        cout<<"Numarul nu este palindrom!";
    }
    return 0;
}
