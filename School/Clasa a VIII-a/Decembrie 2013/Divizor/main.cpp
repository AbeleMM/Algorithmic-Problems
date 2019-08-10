#include <iostream>

using namespace std;

int main()
{
    //Se introduce un numar de la tastatura. Aflati divizorii acestuia (*divizorii proprii).
    int n,d;
    cout<<"Introduceti numarul: ";
    cin>>n;
    cout<<endl;
    d=2;
    while (d<=n/2)
    {
        if (n%d==0)
        cout<<d<<"; ";
        d=d+1;
    }
    return 0;
}
