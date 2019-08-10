#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n;
int m=5;
int fact(int n)
{
    int s=0,p=5;
    while(p<=n)
    {
        s+=n/p;
        p=p*5;
    }
    return s;
}
int main()
{
    cin>>n;
    if(n!=0)
    {
        while(fact(m)<n)
            m++;
        if(fact(m)==n)
            cout<<m;
        else
            cout<<"-1";
    }
    else
        cout<<"1";
    return 0;
}
