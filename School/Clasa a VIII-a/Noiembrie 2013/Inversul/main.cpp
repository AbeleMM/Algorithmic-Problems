#include <iostream>

using namespace std;

int main()
{
    int n, uc, inv;
    cout<<"n=";
    cin>>n;
    inv=0;
    while(n>0)
    {
        uc=n%10;
        inv=inv*10+uc;
        n=n/10;
    }
    cout<<"Inversul este:"<<inv;
    return 0;
}
