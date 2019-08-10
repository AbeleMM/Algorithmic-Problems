#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lenes.in");
ofstream out("lenes.out");
int p,m,n,k1,k2,d[502][502],s,c,q;
struct total
{
    int sp;
    int st;
}v[502];
void Nord_Sud()
{
    int aux,ok;
    for(int j=1;j<=n;j++)
        do{
            ok=0;
            for(int i=1;i<m;i++)
                if(d[i][j]>d[i+1][j])
                {
                    aux=d[i][j];
                    d[i][j]=d[i+1][j];
                    d[i+1][j]=aux;
                    ok=1;
                }
        }while(ok==1);
    for(int j=1;j<=n;j++)
        for(int i=1;i<=m;i++)
        {
            v[j].st+=d[i][j];
            if(i==k1)
                v[j].sp=v[j].st;
        }
    s=v[1].st+v[2].sp;
    for(int i=2;i<n;i++)
    {
        if(v[i].st+v[i-1].sp<s)
            s=v[i].st+v[i-1].sp;
        if(v[i].st+v[i+1].sp<s)
            s=v[i].st+v[i+1].sp;
    }
    if(v[n].st+v[n-1].sp<s)
            s=v[n].st+v[n-1].sp;
}
void Sud_Nord()
{

}
int main()
{
    in>>p;
    in>>m>>n>>k1>>k2;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            in>>d[i][j];
    if(p==1)
        Nord_Sud();
    if(p==2)
        Nord_Sud();
        Sud_Nord();
    out<<s;
    return 0;
}
