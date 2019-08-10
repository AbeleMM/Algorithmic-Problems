#include <iostream>

using namespace std;
int a,b;
int cmmdc(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    cin>>a>>b;
    cout<<cmmdc(a,b);
    return 0;
}
