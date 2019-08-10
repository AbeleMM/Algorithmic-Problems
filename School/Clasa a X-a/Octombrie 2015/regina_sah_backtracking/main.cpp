#include <iostream>
using namespace std;
int n,k,sol[12];
bool ok;
void init(int k)
{
    sol[k]=0;
}
int succesor(int k)
{
    if(sol[k]<n)
    {
        sol[k]=sol[k]+1;
        return 1;
    }
    return 0;
}
int valid(int k)
{
    for(int i=1;i<k;i++)
    {
        if(sol[i]==sol[k])
            return 0;
        if((k-i==sol[k]-sol[i]) || (k-i==sol[i]-sol[k]))
            return 0;
    }
    return 1;
}
int solutie(int k)
{
    if(k==n)
        return 1;
    else
        return 0;
}
void afisare(int k)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(j==sol[i])
                cout<<'*';
            else
                cout<<'-';
        cout<<"\n";
    }
}
void bk(int k)
{
    init(k);
    while(succesor(k) && !ok)
        if(valid(k))
        {
            if(solutie(k))
            {
                afisare(k);
                ok=true;
            }
            else
                bk(k+1);
        }
}
int main()
{
    cin>>n;
    bk(1);
    return 0;
}
