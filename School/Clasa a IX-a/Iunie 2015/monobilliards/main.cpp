#include <iostream>

using namespace std;
int n,sf,e,v[100002],mx;
int vid()
{
    if(sf==0)
        return 1;
    else
        return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>e;
        while(mx<e)
        {
            sf++;
            mx++;
            v[sf]=mx;
        }

        if(v[sf]==e)
            sf--;
    }
    if(vid()==1)
        cout<<"Not a proof";
    else
        cout<<"Cheater";
    return 0;
}
