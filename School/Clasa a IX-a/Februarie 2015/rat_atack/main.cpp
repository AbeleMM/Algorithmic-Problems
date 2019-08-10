#include <iostream>

using namespace std;
int t,d,n,m[1027][1027],v[20002],x,y,xopt,yopt,smx;
void citire()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y;
        m[x][y]=i;
        cin>>v[i];
    }
}
void greedy()
{

}
void afisare()
{
    cout<<xopt<<" "<<yopt<<" "<<smx<<"\n";
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        citire();
        greedy();
        afisare();
    }
    return 0;
}
