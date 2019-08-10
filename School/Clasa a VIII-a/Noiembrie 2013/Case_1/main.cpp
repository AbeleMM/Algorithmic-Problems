#include <iostream>

using namespace std;

int main()
{
    int n,nr,i;//numarul de case si numarul lor
    int nrc,nrf,nrb; // numarul de copii, femei si barbati
    int gr1,gr2,gr3; //numarul de rudie de fiecare grad
    nrc=nrf=nrb=gr1=gr2=gr3=0;
    cout<<"Introduceti nuarul de case: ";
    cin>>n;
    cout<<endl;
    for (i=1;i<=n;i++)
    {
        cout<<"Introduceti numarul uneia dintre case: ";
        cin>>nr;
        cout<<endl;
        nrc=nrc+nr%10;
        nrf=nrf+nr/10%10;
        nrb=nrb+nr/100%10;
        nr=nr/1000;
        if (nr==1)
        {
            gr1=gr1+1;
        }
        if (nr==2)
        {
            gr2=gr2+1;
        }
        if (nr==3)
        {
            gr3=gr3+1;
        }
    }
    cout<<"Numarul de rude de gradul 1 este de: "<<gr1<<"."<<endl;
    cout<<"Numarul de rude de gradul 2 este de: "<<gr2<<"."<<endl;
    cout<<"Numarul de rude de gradul 3 este de: "<<gr3<<"."<<endl;
    cout<<"Numarul de barbati este de: "<<nrb<<"."<<endl;
    cout<<"Numarul de femei este de: "<<nrf<<"."<<endl;
    cout<<"Numarul de copii este de: "<<nrc<<"."<<endl;
    return 0;
}
