#include <iostream>
#include <fstream>
using namespace std;
ifstream in("suma.in");
ofstream out("suma.out");
long S,salt,n,r;
int main()
{
    in>>S;
    n=1;
    while(salt!=S)
    {
        salt=n*(n+1)/2;
        if(salt==S)
            out<<n;
        if(salt>S && (salt-S)%2==0)
        {
            r=(salt-S)/2;
            if(r<=n)
                out<<n<<"\n"<<r;
            else
            {
                int i=0;
                while(r>n-i)
                {
                    r=r-(n-i);
                    ++i;
                }
                out<<n<<"\n"<<r<<"\n";
                for(int j=i;j>=1;--j)
                    out<<n-j+1<<"\n";
            }
            salt=S;
        }
        ++n;
    }
    return 0;
}
