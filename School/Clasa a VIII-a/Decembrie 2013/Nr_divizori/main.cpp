#include <iostream>

using namespace std;

int main()
{
    //Se introduce un numar de la tastatura. Sa se afiseze numarul de divizori proprii ai acestuia.
    int n,d,S;
    cout<<"Introduceti valoarea numarului: ";
    cin>>n;
    cout<<endl;
    S=0;
    d=2;
    while (d<=n/2)
    {
        if (n%d==0)
        S=S+1;
        d=d+1;
    }
    cout<<"Numarul are "<<S<<" divizori proprii!"<<endl;
    return 0;
}
