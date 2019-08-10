#include <iostream>

using namespace std;

int main()
{
    int x;
    cout<<"Introduceti numarul: ";
    cin>>x;
    if (x<0)
        x=-x;
    cout<<"Modulul numarului este: "<<x<<";";
    return 0;
}
