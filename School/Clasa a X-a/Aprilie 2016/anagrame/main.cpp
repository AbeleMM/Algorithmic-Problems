#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("anagrame.in");
ofstream out("anagrame.out");
int p,nr,ls,lc;
char s[100003],c[25003];
int vs[28];
int vc[28];
int main()
{
    in>>p;
    in>>s>>c;
    strlwr(s);
    strlwr(c);
    ls=strlen(s);
    lc=strlen(c);
    if(p==1)
    {
        for(int i=0;i<lc;i++)
            vc[c[i]-'a']++;
        int st=0;
        int d=lc-1;
        int ok=0;
        while(d<ls && ok==0)
        {
            int id=1;
            for(int i=st;i<=d;i++)
                vs[s[i]-'a']++;
            for(int j=1;j<=28;j++)
            {
                if(vs[j]!=vc[j])
                    id=0;
            }
            if(id==1)
            {
                for(int j=st;j<st+lc;j++)
                    out<<s[j];
                ok=1;
            }
            st++;d++;
        }
    }
    if(p==2)
    {
        for(int i=0;i<lc;i++)
            vc[c[i]-'a']++;
        int st=0;
        int d=lc-1;
        while(d<ls)
        {
            int id=1;
            for(int i=st;i<=d;i++)
                vs[s[i]-'a']++;
            for(int j=1;j<=28;j++)
            {
                if(vs[j]!=vc[j])
                    id=0;
            }
            if(id==1)
                nr++;
            st++,d++;
        }
        out<<nr;
    }
    return 0;
}
