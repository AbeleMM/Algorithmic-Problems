#include <iostream>
#include <fstream>
using namespace std;
//ifstream = fisier de intrare;
ifstream f("Date.in");// f = denumire logica;
//fisier de iesire;
ofstream g("Date.out");
int a,b,S;

int main()
{
    f>>a;//citire din fisier;
    f>>b;//citire din fisier;
    S=a+b;
    g<<S;//afisare in fisier;
    return 0;
}
