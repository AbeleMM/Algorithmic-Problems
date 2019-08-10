#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,i,j,nr, cand;
int a[11];
void citire()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>a[i];
    }
}
int majoritar()
{
    cand=-1;
    nr=0;
    for (i=1;i<=n;i++)
    {
        if (nr==0)
        {
            cand=a[i];
            nr++;
        }
        else
        {
            if (cand==a[i])
            {
                nr=nr+1;
            }
            else
            {
                nr=nr-1;
            }
        }
    }
    nr=0;
    for (i=1;i<=n;i++)
    {
        if (cand==a[i])
        {
            nr++;
        }
    }
    if (nr>n/2)
    {
        return cand;
    }
    else
    {
        return 0;
    }
}
int main()
{
    citire();
    if (majoritar())
    {
        out<<majoritar();
    }
    else
    {
        out<<"Nu e majoritar.";
    }
    return 0;
}
