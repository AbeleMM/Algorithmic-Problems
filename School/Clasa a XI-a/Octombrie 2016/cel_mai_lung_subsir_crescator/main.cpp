#include <iostream>
#include <fstream>
using namespace std;
ifstream in("scmax.in");
ofstream out("scmax.out");
int n,v[100004],i;
int e[100004]/*elemente*/,p[100004]/*pozitii*/,nr;
int sol[100004];

int caut_bin(int st, int dr){
    //cautam cel mai mic numar din e[] mai mare decat v[i]
    int mj=st+(dr-st)/2;
    if(dr<st)
        return -1;
    if(e[mj]>v[i]){
        if(e[mj-1]<v[i])
            return mj;
        else
            return caut_bin(st,mj-1);
    }
    else
        return caut_bin(mj+1,dr);
}

int main()
{
    in>>n;
    for(i=1;i<=n;++i)
        in>>v[i];
    nr=1;
    e[1]=v[1];
    p[1]=1;
    for(i=2;i<=n;++i){
        if(v[i]<e[1]){
            e[1]=v[i];
            p[i]=1;
        }
        else if(v[i]>e[nr]){
            ++nr;
            e[nr]=v[i];
            p[i]=nr;
        }
        else{
            int poz=caut_bin(1,nr);
            if(poz!=-1){
                e[poz]=v[i];
                p[i]=poz;
            }
        }
    }
    out<<nr<<"\n";

    int aux=nr;
    for(i=n;i>=1;--i)
        if(p[i]==aux){
            sol[aux]=v[i];
            --aux;
        }
    for(i=1;i<=nr;++i)
        out<<sol[i]<<" ";
    return 0;
}
