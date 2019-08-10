#include <iostream>

using namespace std;

int main()
{

    int n,s,i;
    cout<<"Introduceti n:";
    cin>>n;
    cout<<endl;
    s=0;
    i=1;
    while (i<=n)
    {
        s=s+i;
        i=i+1;
    }
    cout<<"Solutia este: "<<s<<";"<<endl;

    return 0;
}
