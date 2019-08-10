#include <iostream>
#include <fstream>
using namespace std;
ifstream in("desert.in");
ofstream out("desert.out");
long n;
long double k,p;
long double dist(int n)
{
    if(n<=2)
        return n*k/p*100;
    return (k/((2*n-3)*p))*100+dist(n-1);

}
int main()
{
    in>>n>>k>>p;
    out.precision(3);
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out<<dist(n);
    return 0;
}
