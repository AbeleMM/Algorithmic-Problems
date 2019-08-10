#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,s,lt,rt;
int a[106][106],v[106];
int maxs,smax;
void citire()
{
   in>>n;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           in>>a[i][j];
       }
   }
}
void prelucrare()
{
    int i;
    for(lt=1;lt<=n;lt++)
    {
        maxs=-130;
        for(lt=1;lt<=n;lt++)
        {
            for(int i=1;i<=n;i++)
            {
                v[i]=0;
            }
        }
        for(rt=lt;rt<=n;rt++)
        {
            for(i=1;i<=n;i++)
            {
                v[i]=v[i]+a[i][rt];
            }
            s=0;smax=-130;
            for(i=1;i<=n;i++)
            {
                s=s+v[i];
                if(s<0)
                {
                    s=0;
                }
                else
                {
                    if(smax<s)
                    {
                        smax=s;
                    }
                }
            }
            if (maxs<smax)
            {
                maxs=smax;
            }
        }
    }
}
void afisare()
{
    out<<maxs;
}
int main()
{
    citire();
    prelucrare();
    afisare();
    return 0;
}
