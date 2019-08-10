#include <iostream>

using namespace std;
int n;
int s_cif(int n){
    if(n<10)
        return n;
    else
        return n%10+ s_cif(n/10);
}
int main()
{
    cin>>n;
    cout<<s_cif(n);
    return 0;
}
