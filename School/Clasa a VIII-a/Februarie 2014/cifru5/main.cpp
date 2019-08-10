#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cifru5.in");
ofstream out("cifru5.out");
int v[100005],n,i,mx,mut,nrmin,nregal,cif,sus,jos,acif;
int main()
{
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>v[i];
    }
    mx=-1;
    for (i=1;i<=n;i++)
    {
        if (v[i]>mx)
        {
            mx=v[i];
        }
    }
    out<<mx<<" ";
    nrmin=9*n+1;
    acif=11;
    for (cif=0;cif<=9;cif++)
    {
        mut=0;
        for (i=1;i<=n;i++)
        {
            //mutare in sus
            if (v[i]>cif)
            {
                sus=10-v[i]+cif;
            }
            else
            {
                sus=cif-v[i];
            }
            //mutare in jos
            if (cif>v[i])
            {
                jos=v[i]+10-cif;
            }
            else
            {
                jos=v[i]-cif;
            }
            if (sus>jos)
            {
                mut=mut+jos;
            }
            else
            {
                mut=mut+sus;
            }
        }
        if (nrmin>mut)
        {
            nrmin=mut;
            nregal=1;
            if (cif<acif)
            {
                acif=cif;
            }
        }
        if (nrmin==mut)
        {
            nregal=nregal+1;
        }
    }
    out<<nrmin<<" ";
    out<<acif<<" ";
    out<<nregal<<" ";
    return 0;
}
