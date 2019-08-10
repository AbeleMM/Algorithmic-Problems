#include <iostream>
#include <math.h>
using namespace std;
unsigned long n,i;
int main()
{

    cin>>n;
    while(n!=0)
    {
        i=sqrt(n);
        if(i*i==n)
        {
            cout<<"yes"<<"\n";
        }
        else
        {
            cout<<"no"<<"\n";
        }
        cin>>n;
    }
    return 0;
}
