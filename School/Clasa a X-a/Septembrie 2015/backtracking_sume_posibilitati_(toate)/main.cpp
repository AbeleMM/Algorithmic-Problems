#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int sol[100],n,s;
int m;
void init(int k)
{
    sol[k]=0;
}
int succesor(int k)
{
    if(s+sol[k]<n)
    {
        sol[k]=sol[k]+1;
        return 1;
    }
    else
    {
        s=s-sol[k-1];
        return 0;
    }
}
int valid(int k)
{
    for(int i=1;i<k;i++)
        if(sol[i]==sol[k])
            return 0;
    s=s+sol[k];
    return 1;
}
int solutie(int k)
{
    if(s==n && k==m)
        return 1;
    else
        return 0;
}
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        out<<sol[i]<<" ";
    out<<"\n";
    s=s-sol[k];
}
void bk(int k)
{
    init(k);
    while(succesor(k))
        if(valid(k))
        {
            if (solutie(k))
                afisare(k);
            else
                bk(k+1);
        }
}
int main()
{
    in>>n;
    in>>m;
    bk(1);
    return 0;
}
