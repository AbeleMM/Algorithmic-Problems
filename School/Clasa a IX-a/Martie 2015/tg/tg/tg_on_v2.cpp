//nr triplete 1<=p<q<r<=n aflate in progresie geometrica
#include<fstream>
#include<cmath>
using namespace std;
 ifstream fin("tg.in");
ofstream fout("tg.out");

int v[4000010];

int main()
{
    long long n,s,a,x,k1,k2,t,d,c,b,i,k,s1,p,r;
	fin>>n;
    s=0;
    t=0;
    for (a=1;a<=n-2;a++)
    {
        if(v[a]==0)//i are toti factorii primi cu exponenti impari
        {
            b=(n-2)/a;
            for(i=1;i*i<=b;i++)
            {
                v[a*i*i]=a;
            }
        }

        x=v[a];
        k1=sqrt(a/x);
        k2=sqrt(n/x);
        s=s+k2-k1;
    }
    fout<<s<<endl;
    fout.close();
	fin.close();
    return 0;
}