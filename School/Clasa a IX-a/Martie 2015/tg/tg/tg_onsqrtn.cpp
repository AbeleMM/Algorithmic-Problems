//nr triplete 1<=p<q<r<=n aflate in progresie geometrica
#include<fstream>
#include<cmath>
using namespace std;
 ifstream fin("tg.in");
ofstream fout("tg.out");

int main()
{
    long long n,s,a,x,k1,k2,t,d,c;
    fin>>n;
    s=0;
    for (a=1;a<=n-2;a++)
    {
        x=1;
        t=a;
        d=2;
        while(d*d<=t)
        {
            c=0;
            while(t%d==0)
            {
                c++;
                t=t/d;
            }
            if(c%2==1)x=x*d;
            d++;
        }
        if(t>1)x=x*t;
        k1=sqrt(a/x);
        k2=sqrt(n/x);
        s=s+k2-k1;
    }
    fout<<s<<endl;
    fout.close();
	fin.close();
    return 0;
}