//nr triplete 1<=p<q<r<=n aflate in progresie geometrica
#include<fstream>
#include<cmath>
using namespace std;
 ifstream fin("tg.in");
ofstream fout("tg.out");
int v[1000010];
int main()
{
    long long n,a,i,k,s,p,n4,n4a;
    fin>>n;
    n4=n/4;
    s=0;
    for(a=1;a<=n4;a++)
    {
        if (v[a]==0)
        {
            n4a=n4/a;
            for(i=1;i*i<=n4a;i++)
            {
                v[a*i*i]=a;
            }
            k=(int)sqrt(n/a);
            if(k%2==0)p=k/2*(k-1);
            else p=(k-1)/2*k;
            s=s+p;
        }
    }
    fout<<s<<endl;
    fout.close();
	fin.close();
    return 0;
}

