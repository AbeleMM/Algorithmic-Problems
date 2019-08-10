#include <iostream>
#include <fstream>
using namespace std;
ifstream in("zid.in");
ofstream out("zid.out");
int p,n,m,v[100000],k;
int main()
{
    in>>p>>n>>m;
    for(int i=1;i<=m;++i){
        in>>k;
        ++v[k];
    }
    if(p==1){
        int nrp,nra;
        int i=1;
        while(i<=n){
            int ok=0;
            while(v[i]>0 || v[i+1]>0){
                ok++;
                i++;
            }
            if(ok>0)
                ++nrp;
            ++i;
        }
        i=1;
        while(i<=n){
            int ok=0;
            while(v[i]>0){
                ok++;
                i++;
            }
            if(ok>1)
                ++nra;
            ++i;
        }
        out<<nrp<<"\n"<<nra;
    }
    if(p==2){
        int r=0,x=0;
        for(int i=1;i<=n;++i){
            if(v[i]==0)
                ++x;
            if(v[i]>1)
                r+=v[i]-1;
        }
        if(x>r)
            out<<r<<"\n";
        else
            out<<x<<"\n";
        x=0;
        for(int i=1;i<=n && x>0;++i)
        {
            if(v[i-1]>0 && v[i+1]>0 && v[i]==0)
                x+=2,r--;
            else{
                if((v[i-1]>0 || v[i+1]>0) && v[i]==0)
                    ++x,r--;
            }
        }
        out<<r+1;
    }
    return 0;
}
