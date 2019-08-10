#include <iostream>
#include <fstream>
using namespace std;
ifstream in("numerus.in");
ofstream out("numerus.out");
int k,n,M,m,i,l;
int main()
{
    in>>k>>n;
    M=5*k;
    m=5*k-4;
    if(k%2==1)
    {
        for(i=m; i<=M;i++)
            out<<i<<" ";
            out<<M<<" ";
    }
    if (k%2==0)
    {
        out<<M<<" ";
        for(i=M;i>=m;i--)
            out<<i<<" ";
    }
    out<<endl;
    if(n%5==0)
    {
        l=n/5;
    }
    else
    {
        l=n/5+1;
    }
    out<<l;
    out<<endl;
    if(n%10==0)
    out<<"A B";
    if(n%5==0 && n%10!=0)
    out<<"E F";
    if(n%10==1)
    out<<"A";
    if(n%10==2)
    out<<"B";
    if(n%10==3 || n%10==9)
    out<<"C";
    if(n%10==4 || n%10==8)
    out<<"D";
    if(n%10==7)
    out<<"E";
    if(n%10==6)
    out<<"F";

    return 0;
}
