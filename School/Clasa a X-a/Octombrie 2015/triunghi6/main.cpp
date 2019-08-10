#include <iostream>
#include <fstream>
using namespace std;
ifstream in("triunghi6.in");
ofstream out("triunghi6.out");
int v,n,k;
void v1()
{
    int c,mn,aux;
    in>>c;
    mn=c;
    for(int i=2;i<=n;i++)
    {
        in>>c;
        if(c<mn)
            mn=c;
    }
    aux=2*mn;
    out<<mn<<" "<<mn<<" "<<aux<<" ";
    for(int i=4;i<=k;i++)
    {
        c=mn;
        mn=aux;
        aux=c+aux;
        out<<aux<<" ";
    }
}
void v2()
{
    /*int a[50],mx=0,aux=0,c;
    for(int i=1;i<=n;i++)
    {
        in>>a[i];
        if(a[i]>mx)
            mx=a[i];
        out<<a[i]<<" ";
    }
    for(int i=1;i<=n;i++)
        if(a[i]>aux && a[i]<mx)
            aux=a[i];
    c=mx+aux;
    out<<c<<" ";
    for(int i=n+2;i<=k;i++)
    {
        aux=mx;
        mx=c;
        c=aux+mx;
        out<<c<<" ";
    }*/

}
int main()
{
    in>>v>>n>>k;
    if(v==1)
        v1();
    else
        v2();
    return 0;
}
