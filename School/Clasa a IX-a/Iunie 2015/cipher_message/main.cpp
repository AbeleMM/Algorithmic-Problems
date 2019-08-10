#include <iostream>
#include <string.h>
using namespace std;
char c[200003],s[200003];
int i,n,sf;
int main()
{
    cin>>c;
    n=strlen(c);
    for(i=0;i<n;i++)
    {
        s[sf]=c[i];
        if(s[sf]==s[sf-1])
            sf--;
        else
            sf++;
    }
    for(i=0;i<sf;i++)
        cout<<s[i];
    return 0;
}
