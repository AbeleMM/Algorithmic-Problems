//Malan Abele, Clasa a VIII-a, Liceul Teoretic Onisifor Ghibu Oradea;
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ucif.in");
ofstream out("ucif.out");
int S,i,p,n,j;
int main()
{
    in>>n;//citim din fisier;
    S=0;
    for (i=1;i<=n;i++)
    {
        p=1;//initializam produsul cu 1;
        for (j=1;j<=i;j++)
        {
            p=(p*i)%10;//calculam u.c. a produsului.
        }
    S=(S+p)%10;
    }
    out<<S;
    return 0;
}
