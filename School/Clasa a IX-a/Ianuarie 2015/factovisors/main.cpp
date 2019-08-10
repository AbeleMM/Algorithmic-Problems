#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,ok,p,prod,nr,malt;
int v[65536];
void ciur()
{
    int i,j;
    for(i=3;i<=65536;i+=2)
    {
        if (v[i]==0)
        {
            for(j=3;j<=65536*65536/i;j+=2)
            {
                v[j*i]=1;
            }
        }
    }
}
void prelucrare()
{
    int i;
    ok=1;
    while(m%2==0)
    {
        ++p;
        m=m/2;
    }
    if(p>0)
    {
        nr=0;
        prod=2;
        while(prod<=n)
        {
            nr=nr+n/prod;
            prod=prod*2;
        }
        if(p>nr)
            ok=0;
    }
    for(i=3;i<=65536;i+=2)
    {
        while (m>1 && ok==1)
        {
            if(v[i]==0)
            {
                while(m%i==0)
                {
                    ++p;
                    m=m/i;
                }
                if(p>0)
                {
                    nr=0;
                    prod=i;
                    while(prod<=n)
                    {
                        nr=nr+n/prod;
                        prod=prod*i;
                    }
                    if(p>nr)
                        ok=0;
                }
            }
        }
    }
}
void afisare()
{

    if(ok==1)
        printf("%d divides %d! \n",malt,n);
    if(ok==0)
        printf("%d does not divide %d! \n",malt,n);
}
int main()
{
    ciur();
    while(scanf("%d %d \n",&n,&m)==2)
    {
        malt=m;
        if(n>0 && m>0 && n<m)
        {
            prelucrare();
            afisare();
        }
        if(n>0 && malt>0 && n>malt)
            printf("%d divides %d! \n",malt,n);
        if(n==0 && malt==1)
            printf("%d divides %d! \n",malt,n);
        if(malt==0)
            printf("%d does not divide %d! \n",malt,n);
        if(n==0 && malt>1)
            printf("%d does not divide %d! \n",malt,n);
    }
    return 0;
}
