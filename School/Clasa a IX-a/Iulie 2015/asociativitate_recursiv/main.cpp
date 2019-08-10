#include <iostream>

using namespace std;
int n;
int posib(int n)
{
    int s=0;
    if(n<=2)
        return 1;
    else
        for(int k=1;k<n;k++)
            s+=posib(k)*posib(n-k);
    return s;
}
int main()
{
    cin>>n;
    cout<<posib(n);
    return 0;
}
