#include <iostream>
#include <fstream>

using namespace std;

ifstream in("porumb1.in");
ofstream out("porumb1.out");
int nr,n,nra,x,ult,nt;


int main()
{
    in>>n>>x;
    nr=n;
    nra=0;
    ult=1;
    nt=1;

    if(n%2==0)
        out<<n/2<<"\n";
    else
        out<<n/2+1<<"\n";

    while(nr>0)
    {
        nr=nr/2;
        nra=nra+1;
    }
    out<<nra<<"\n";

    while(x%2==0)
    {
        x=x/2;
        nt=nt+1;
    }
    out<<nt<<"\n";

    while(2*ult<n)
    {
        ult=ult*2;
    }
    out<<ult;
    return 0;
}
