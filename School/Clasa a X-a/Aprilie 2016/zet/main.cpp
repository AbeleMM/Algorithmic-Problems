#include <iostream>
#include <fstream>
using namespace std;
ifstream in("zet.in");
ofstream out("zet.out");
int p,n,k;
unsigned long long v[15],t;
int nr=0,pasc[]={3,4,6,5,10,6,15,20,7,21,35,8,28,56,70,9,36,84,126,10,45,120,210,252,11,55,165,330,462,12,66,220,495,792,924,13,78,286,715,1287,1716};
int main()
{
    in>>p>>k>>n;
    t=k;
    v[0]=1;
    v[1]=t;
    t*=k;
    v[2]=t-2;
    if(p==1)
        out<<v[2]<<"\n";
    else{
        for(int i=3;i<=n;++i){
            t*=k;
            v[i]=t;
            for(int j=i-2;j>=0;j-=2){
                v[i]-=pasc[nr]*v[j];
                ++nr;
            }
        }
        out<<v[n]<<"\n";
    }
    return 0;
}
