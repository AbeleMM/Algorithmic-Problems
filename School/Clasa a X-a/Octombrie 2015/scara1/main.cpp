#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream in("scara1.in");
ofstream out("scara1.out");
int h,n,m,p,sol[79],s,k,v[79],check[79];
double e;
bool use[79];
void init(int k)
{
    sol[k]=0;
}
int succesor(int k)
{
    if(s+sol[k]<h && sol[k]<=m)
    {
        sol[k]=sol[k]+1;
        return 1;
    }
    else
    {
        s=s-sol[k-1];
        use[sol[k-1]]=0;
        return 0;
    }
}
int valid(int k)
{
    if(use[sol[k]])
        return 0;
    s=s+sol[k];
    use[sol[k]]=1;
    return 1;
}
int solutie(int k)
{
    if(s==h && k==n)
        return 1;
    else
        return 0;
}
/*void selectare(int k)
{
    int l=2;
    int ef1=sol[1]+sol[2];
    double ef2=(float)(sol[1]+sol[2])/l+p;
    double t=0;
    int i=3;
    int ok;
    while(i<n)
    {
        ok=0;
        while(ef2<ef1 && (float)(ef2-p)*t<m && i<n)
        {
            l++;
            ef2=(float)((ef2-p)*(t-1)+sol[i])/t+p;
            ef1=ef1+sol[i];
            i++;
            ok=1;
        }
        if(ok==1)
            t+=ef2;
        else{
            t+=ef1;
            i++;
        }

        t=2;
        ef1=sol[i]+sol[i+1];
        ef2=(float)(sol[i]+sol[i+1])/t+p;
    }
    if(t<e)
    {
        e=t;
        for(int i=1;i<=k;i++)
            v[i]=sol[i];
    }
    s=s-sol[k];
    use[sol[k]]=0;
}*/
/*void afisare(int k)
{
    for(int i=1;i<=k;i++)
        out<<sol[i]<<" ";
    out<<endl;
    s=s-sol[k];
    use[sol[k]]=0;
}*/
void bk(int k)
{
    init(k);
    while(succesor(k))
        if(valid(k))
        {
            if (solutie(k))
                //selectare(k);
                afisare(k);
            else
                bk(k+1);
        }
}
int main()
{
    in>>h>>n>>m>>p;
    e=1049;
    bk(1);
    out<<e<<"\n";
    for(int i=1;i<=n;i++)
        out<<v[i]<<" ";
    return 0;
}
