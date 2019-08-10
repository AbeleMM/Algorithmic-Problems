#include <iostream>
using namespace std;
int t;
unsigned long long v[3],aux,sol;
int main() {
	cin>>t;
	for(int i=1;i<=t;++i){
	    cin>>v[0]>>v[1]>>v[2];
	    v[0]=v[0]%1000000007;
	    v[1]=v[1]%1000000007;
	    v[2]=v[2]%1000000007;
	    bool ok;
	    do{
            ok=false;
            for(int j=0;j<2;++j)
                if(v[j]>v[j+1]){
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                    ok=true;
                }
	    }while(ok==true);
	    sol=v[0];
	    sol*=v[1]-1;
	    sol%=1000000007;
	    sol*=v[2]-2;
	    sol%=1000000007;
	    cout<<sol;
	    if(i<t)
            cout<<"\n";
	}
	return 0;
}
