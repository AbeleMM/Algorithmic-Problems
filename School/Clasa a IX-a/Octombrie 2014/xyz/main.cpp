#include <iostream>
#include <fstream>
using namespace std;
ifstream in("xyz.in");
ofstream out("xyz.out");
int x,y,z,nr,i;
int main()
{
    in>>x>>y>>z;
    nr=1;
    for(i=1;i<=x-1;i++)
    {
        nr=nr*10;
    }
    nr=y*nr;
    for(i=1;i<=x-1;i++)
    {
        nr=nr+z;
        z=z*10;
    }
    out<<nr;
    return 0;
}
