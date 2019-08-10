#include <iostream>
#include <fstream>

using namespace std;

ifstream f("pinochio.in");

ofstream g("pinochio.out");

int n,p,k,i;

int main()
{
    f>>n>>p>>k;
    i=1;//incepen cu ziua 1;
    while (i<=k)//pana in ziua k;
    {
        if (i%7==6 || i%7==0)// daca e sfarsit de saptamana, lungimea nasului va scadea cu 1 cm;
        n=n-1;
        else
        n=n+p;// daca nu, nasul va creste cu p cm;
        i++;
    }
    g<<n;
    return 0;
}
