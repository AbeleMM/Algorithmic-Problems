#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Introduceti valoarea numarului: ";
    cin>>n;
    cout<<endl;
    while (n>9)
    {
        n=n/10;
    }
    cout<<"Prima cifra este: "<<n<<";";
    return 0;
}
