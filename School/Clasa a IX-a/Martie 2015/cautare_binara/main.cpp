#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
int n,v[1003],key,poz;
void citire()
{
    in>>n>>key;
    for(int i=1;i<=n;i++)
        in>>v[i];
}
int cauta(int s,int d)
{
    int mj;
    while(s<=d)
    {
        mj=s+(d-s)/2;
        if(key==v[mj])
        {
            poz=mj;
            return 1;
        }
        if(key<v[mj])
            d=mj-1;
        if(key>v[mj])
            s=mj+1;
    }
    return -1;
}
int main()
{
    citire();
    if(cauta(1,n)==1)
        cout<<"DA: "<<poz<<";";
    else
        cout<<"NU";
    return 0;
}
