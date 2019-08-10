#include <iostream>

using namespace std;
int n;
unsigned long long t = 1, s;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        t *= 2;
        s += t;
    }
    cout<<s;
    return 0;
}
