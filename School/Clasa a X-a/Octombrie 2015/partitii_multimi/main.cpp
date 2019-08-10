#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,v[100],sol[100],k,mx,l;
int init(int k)
{
    sol[k]=0;
}
int succesor(int k)
{
    if(sol[k]<n)
    {
        sol[k]++;
        return 1;
    }
    return 0;
}
int valid(int k)
{
    if((sol[k-1]-sol[k]>1) || (sol[k]-sol[k-1]>1))
        return 0;
    return 1;
}
int solutie(int k)
{
    if(k==n)
    {
        for(int i=1;i<=n;i++)
            if(sol[i]>mx)
                mx=sol[i];
        return 1;
    }
    return 0;
}
int afisare(int k)
{
    for(int i=1;i<=mx;i++)
    {
        out<<"{";
        l=k;
        while(sol[l]!=i)
            l--;
        for(int j=1;j<l;j++)
            if(sol[j]==i)
                out<<v[j]<<", ";
        out<<v[l];
        cout<<v[l]<<" ";
        if(i!=mx)
            out<<"} ∪ ";
        else
            out<<"};";
    }
    out<<"\n";
    /*for(int i=1;i<=n;i++)
        cout<<sol[i]<<" ";
    cout<<endl;*/
    mx=0;
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
    for(int i=1;i<=n;i++)
        in>>v[i];
    sol[1]=1;
    bk(2);
    return 0;
}
