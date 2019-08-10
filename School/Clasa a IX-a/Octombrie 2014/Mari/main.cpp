#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
fstream in("numere.in");
ofstream out("numere.out");
char s1[1000], s2[1000];
int a[1000],b[1000], c[2002];
void citire()
{
    in>>s1;
    in>>s2;
}
void transforma(char s[], int v[])
{
    int i;
    v[0]=strlen(s);
    for(i=0;i<strlen(s);i++)
    {
        v[v[0]-i]=s[i]-'0';
    }
}
void afisare(int v[])
{
    int i;
    for (i=v[0];i>=1;i--)
    {
        cout<<v[i];
    }
    cout<<"\n";
}
void adunare(int a[], int b[], int c[])
{
    int i,t;
    t=0;
    for(i=1;i<=a[0]||i<=b[0];i++)
    {
        c[i]=a[i]+b[i]+t;
        t=c[i]/10;
        c[i]=c[i]%10;
    }
    if(a[0]>b[0])
        {
            c[0]=a[0];
        }
    else
        {
            c[0]=b[0];
        }
    if (c[c[0]]>9)
    {
        c[c[0]]=c[c[0]]%10;
        c[0]++;
        c[c[0]]=1;
    }
}
void inmultire_mic(int a[], int nr, int c[])
{
    int i,t=0;
    for(i=1;i<=a[0];i++)
    {
        c[i]=a[i]*nr+t;
        t=c[i]/10;
        c[i]=c[i]%10;
    }
    c[0]=a[0];
    if (t>0)
    {
        c[0]++;
        c[c[0]]=t;
    }
}
int main()
{
    citire();
    transforma(s1,a);
    transforma(s2,b);
    afisare(a);
    afisare(b);
    cout<<"\n";
    adunare(a,b,c);
    afisare(c);
    cout<<"\n";
    inmultire_mic(a,7,c);
    afisare(c);
    return 0;
}
