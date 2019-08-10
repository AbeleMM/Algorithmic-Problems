#include <iostream>

using namespace std;

int main()
{
    int n,c,i;
    cout<<"Introduceti numarul de zile: ";
    cin>>n;
    cout<<"."<<endl;
    c=6-1;
    i=1;
    while (i<=n-1)
    {
        c=c+6-1;
        i=i+1;
    }
    cout<<"Numarul de capete este: "<<c<<";"<<endl;

    return 0;
}
