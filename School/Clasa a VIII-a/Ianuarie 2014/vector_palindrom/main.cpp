#include <iostream>
#include <fstream>
using namespace std;
ifstream in("vector_palindrom.in");
ofstream out("vector_palindrom.out");
int n,aux,v[101],nr,uc,inv,i;
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
       in>>v[i];
    }
    for (i=1;i<=n;i++)
    {
        aux=v[i];
        inv=0;
        while (aux>0)
        {
            uc=aux%10;
            inv=inv*10+uc;
            aux=aux/10;
        }
        if (v[i]==inv)
        {
            out<<v[i];
        }
    }
    return 0;
}
