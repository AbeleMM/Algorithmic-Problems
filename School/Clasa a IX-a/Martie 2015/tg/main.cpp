#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("tg.in");
ofstream out("tg.out");
int n,nr,c[2002],x[2002];
double a,b,c,x,k;
void ciur()
{
    for(int i=3;i*i<=2000;i+=2)
        if(c[i]==0)
            for(int j=3;j<=2000/i;j++)
                c[i*j]=1;
}
void generare()
{
    x[2]=2;
    for(int i=3;i<=2000;i+=2)
}
int main()
{
    in>>n;
    ciur();
    generare();
    /* for(a=1;a<=n-2;a++)
        for(c=a+2;c<=n;c++)
            if(sqrt(a*c)==int(sqrt(a*c)) && a<sqrt(a*c) && sqrt(a*c)<c)
                nr++; */
    out<<nr;
    return 0;
}
