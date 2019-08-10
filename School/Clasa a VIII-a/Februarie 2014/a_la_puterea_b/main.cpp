#include <iostream>
#include <fstream>

using namespace std;

ifstream in("date.in");
ofstream out("date.out");
int a,b,i,p,x;

int main()
{
    in>>a>>b;
    x=2014;
    p=1;
    for(i=1;i<=b;i++)
    {
        p=((p%x)*(a%x))%x;
    }
    out<<p;
    return 0;
}
