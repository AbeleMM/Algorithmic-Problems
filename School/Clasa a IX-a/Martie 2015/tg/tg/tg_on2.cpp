//nr triplete 1<=p<q<r<=n aflate in progresie geometrica
#include<fstream>
#include<cmath>
using namespace std;
 ifstream fin("tg.in");
ofstream fout("tg.out");

int main()
{
    int a,c,s,n,ua,uc,uac;
	long long bb;
	double r;
	fin>>n;
	s=0;
	for(a=1;a<=n-2;a++)
	{
		ua=a%10;
		for (c=a+2;c<=n;c++)
		{
			uc=c%10;
			uac=(ua*uc)%10;
			if(uac==0 || uac==1 || uac==4 || uac==5 || uac==6 || uac==9)
			{
				bb=a;
				bb=bb*c;
				r=sqrt(bb);
				if(r==(int)r)
				{
					s++;
				}
			}
		}
	}
	fout<<s;
    fout.close();
	fin.close();
    return 0;
}
