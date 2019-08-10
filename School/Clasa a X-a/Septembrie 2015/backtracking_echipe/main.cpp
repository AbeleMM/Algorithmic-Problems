#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,sol[100],v[100],k;
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
        if(sol[i]==sol[k])
            return 0;
    if(sol[k-1]>sol[k])
        return 0;
    return 1;
}
int solutie (int k)
{
    if(k==m)
        return 1;
    else
        return 0;
}
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        out<</*v[*/sol[i]/*]*/<<" ";
        out<<"\n";
}
void bk(int k)
{
    init(k);
    while(succesor(k))
        if(valid(k))
        {
            if(solutie(k))
                afisare(k);
            else
                bk(k+1);
        }
}
int main()
{
    in>>n;
    /*for(int i=1;i<=n;i++)
        in>>v[i];*/
    in>>m;
    bk(1);
    return 0;
}
