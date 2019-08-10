#include <iostream>
#include <fstream>
using namespace std;
ifstream in("media.in");
ofstream out("media.out");
float v[35],S,m,mm;
int n,i,nr,nr2;
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
        in>>v[i];
    S=0;
    m=0;
    mm=11;
    for (i=1;i<=n;i++)
        {
        S=S+v[i];
        if (v[i]>m)
            m=v[i];
        if (v[i]<mm)
            mm=v[i];
        }
    nr=0;
    nr2=0;
    for (i=1;i<=n;i++)
        {
        if (m==v[i])
            nr++;
        if (mm==v[i])
            nr2++;
        }
    cout<<"Media clasei este: "<<S/n<<"."<<"\n";
    cout<<"Media maxima este: "<<m<<"."<<"\n";
    cout<<"Media minima este: "<<mm<<"."<<"\n";
    cout<<"Numarul de elevi cu media maxima este: "<<nr<<"."<<"\n";
    cout<<"Numarul de elevi cu media minima este: "<<nr2<<"."<<"\n";
    return 0;
}
