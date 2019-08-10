#include <iostream>

using namespace std;

int main()
{
    int n,uc,nr;
    cout<<"Introduceti valoarea initiala: ";
    cin>>n;
    cout<<endl;
    nr=0;
    while (n>0)
    {
        uc=uc%10;
        n=n/10;
        nr=nr+1;
    }
    cout<<"Numarul are "<<nr<<" cifre.";
    return 0;
}
