#include <iostream>

using namespace std;

int main()
{
    //Se introduce un numar de la tastatura. Sa se afiseze suma divizorilor sai.
    int n,d,S;
    cout<<"Introduceti valoarea numarului: ";
    cin>>n;
    cout<<endl;
    d=1;
    S=0;
    while (d<=n)
    {
        if (n%d==0)
        S=S+d;
        d++;
    }
    cout<<"Suma divizorilor este egala cu: "<<S<<".";
    return 0;
}
