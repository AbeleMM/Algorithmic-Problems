#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cub.in");
ofstream out("cub.out");
int n,x,y,z,v,nr,p;
void prelucrare()
{
    z=v/(n*n)+(v%(n*n)!=0);
}
void prelucrare2()
{

}
void afisare2()
{

}
int main()
{
    in>>p>>n>>v;
    if(p==1)
    {
        prelucrare();
        out<<x<<" "<<y<<" "<<z;
    }
    if(p==2)
    {
        prelucrare2();
        afisare2();
    }
    return 0;
}
