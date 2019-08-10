#include <iostream>

using namespace std;

int main()
{
    //Se citeste un numar de la tastatura. Sa se stabileasca daca acesta este perfect sau nu.
    int n,d,S;
    cout<<"Introduceti valoarea numarului: ";
    cin>>n;
    cout<<endl;
    S=0;
    d=1;
    while (d<=n/2)
    {
        if (n%d==0)
        S=S+d;
        d=d+1;
    }
    if (S==n)
    cout<<"Numarul este perfect.";
    else
    cout<<"Numarul nu este perfect!";
    return 0;
}
