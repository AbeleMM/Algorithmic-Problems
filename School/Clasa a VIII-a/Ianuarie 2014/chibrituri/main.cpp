#include <iostream>
#include <fstream>
using namespace std;
ifstream in("chibrituri.in");
ofstream out("chibrituri.out");
int  h,minz,hmax,mmax,hmin,mmin,n,m,nr,cv,co;
int main()
{
    nr=0;
    cv=0,
    co=0;
    in>>n>>m;
        for (minz=0;minz<=59;minz++)
        {
            if (minz%10==0)
                {
                    cv=cv+4;
                    co=co+2;
                }
            if (minz%10==1)
                {
                    cv=cv+2;
                    co=co+0;
                }
            if (minz%10==2)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (minz%10==3)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (minz%10==4)
                {
                    cv=cv+3;
                    co=co+1;
                }
            if (minz%10==5)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (minz%10==6)
                {
                    cv=cv+3;
                    co=co+3;
                }
            if (minz%10==7)
                {
                    cv=cv+2;
                    co=co+1;
                }
            if (minz%10==8)
                {
                    cv=cv+4;
                    co=co+3;
                }
            if (minz%10==9)
                {
                    cv=cv+3;
                    co=co+3;
                }
            if (minz/10==0)
                {
                    cv=cv+4;
                    co=co+2;
                }
            if (minz/10==1)
                {
                    cv=cv+2;
                    co=co+0;
                }
            if (minz/10==2)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (minz/10==3)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (minz/10==4)
                {
                    cv=cv+3;
                    co=co+1;
                }
            if (minz/10==5)
                {
                    cv=cv+2;
                    co=co+3;
                }
        }
        for (h=0;h<=23;h++)
        {
            if (h%10==0)
                {
                    cv=cv+4;
                    co=co+2;
                }
            if (h%10==1)
                {
                    cv=cv+2;
                    co=co+0;
                }
            if (h%10==2)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (h%10==3)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (h%10==4)
                {
                    cv=cv+3;
                    co=co+1;
                }
            if (h%10==5)
                {
                    cv=cv+2;
                    co=co+3;
                }
            if (h%10==6)
                {
                    cv=cv+3;
                    co=co+3;
                }
            if (h%10==7)
                {
                    cv=cv+2;
                    co=co+1;
                }
            if (h%10==8)
                {
                    cv=cv+4;
                    co=co+3;
                }
            if (h%10==9)
                {
                    cv=cv+3;
                    co=co+3;
                }
            if (h/10==0)
                {
                    cv=cv+4;
                    co=co+2;
                }
            if (h/10==1)
                {
                    cv=cv+2;
                    co=co+0;
                }
            if (h/10==2)
                {
                    cv=cv+2;
                    co=co+3;
                }
        }
    if(cv==n && co==m)
        {
        nr=nr+1;
        hmax=h;
        mmax=minz;
        if(nr==1)
            {
                hmin=h;
                mmin=minz;
            }
        }
    out<<nr<<"\n";
    if(hmin/10==0 && mmin/10==0)
    {
        out<<"0"<<hmin<<":"<<"0"<<mmin<<"\n";
    }
    if(hmin/10==0 && mmin/10!=0)
    {
        out<<"0"<<hmin<<":"<<mmin<<"\n";
    }
    if(hmin/10!=0 && mmin/10==0)
    {
        out<<hmin<<":"<<"0"<<mmin<<"\n";
    }
    if(hmin/10!=0 && mmin/10!=0)
    {
        out<<hmin<<":"<<mmin<<"\n";
    }

    if(hmax/10==0 && mmax/10==0)
    {
        out<<"0"<<hmax<<":"<<"0"<<mmax<<"\n";
    }
    if(hmax/10==0 && mmax/10!=0)
    {
        out<<"0"<<hmax<<":"<<mmax<<"\n";
    }
    if(hmax/10!=0 && mmax/10==0)
    {
        out<<hmax<<":"<<"0"<<mmax<<"\n";
    }
    if(hmax/10!=0 && mmax/10!=0)
    {
    out<<hmax<<":"<<mmax<<"\n";
    }
}
