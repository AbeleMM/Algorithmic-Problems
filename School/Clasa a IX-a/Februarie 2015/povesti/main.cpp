#include <iostream>
#include <fstream>
using namespace std;
ifstream in("povesti.in");
ofstream out("povesti.out");
long long N,P,C;
void citire()
{
    in>>N;
}
void prelucrare()
{

}
void afisare()
{
    out<<P<<"\n"<<C;
}
int main()
{
    citire();
    prelucrare();
    afisare();
    return 0;
}
