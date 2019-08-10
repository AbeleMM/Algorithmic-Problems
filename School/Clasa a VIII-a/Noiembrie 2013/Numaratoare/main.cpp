#include <iostream>

using namespace std;

int main()
{
    int nr,S;
    S=0;//initial valoarea sumei e 0
    do//repeta
    {
        cout<<"Introduceti valoarea: ";
        cin>>nr;
        cout<<endl;//citim numarul
        S=S+nr;//la vechea suma am adaugat numarul

    }
    while (nr!=0);//pana cand am introdus0
    cout<<"Suma este: "<<S<<"."<<endl;
    return 0;
}
