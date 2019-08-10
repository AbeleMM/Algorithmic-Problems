#include <iostream>
#include <fstream>
using namespace std;
ifstream in("heapuri.in");
ofstream out("heapuri.out");
int n,r,x;
int h[200010],nr;
int v[200010];
void adaug(int i){
    int poz=i;
    while(poz>1 && h[poz/2]>h[poz]){
        int t=h[poz/2];
        h[poz/2]=h[poz];
        h[poz]=t;

        t=v[poz/2];
        v[poz/2]=v[poz];
        v[poz]=t;

        poz/=2;
    }
}
void elimx(int &nr,int x){
    h[x]=h[nr];

    int t=v[x];
    v[x]=v[nr];
    v[nr]=t;
    nr--;

    int poz=x;
    while(2*poz<=nr){
        int fiu=2*poz;
        if(fiu+1<=nr && h[fiu+1]<h[fiu])
            fiu++;
        if(h[fiu]<h[poz]){
            t=h[poz];
            h[poz]=h[fiu];
            h[fiu]=t;

            t=v[poz];
            v[poz]=v[fiu];
            v[fiu]=t;

            poz=fiu;
        }
        else
            poz=nr+1;
    }
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i){
        in>>r;
        if(r==1){
            in>>x;
            ++nr;//crestem nr de elemente
            h[nr]=x;//punem elementul pe ultima pozitie a arborelui
            v[x]=nr;//elem de pe poz x este al nr-lea intrat
            adaug(nr);
        }
        else if(r==2){
            in>>x;
            int alt;
            bool ok=true;
            for(int j=1;j<=nr && ok==true;++j)//parcurg toate pozitiile
                if(v[j]==x)
                    alt=j,ok=false;
            elimx(nr,alt);
        }
        else{
            out<<h[1]<<"\n";
        }
    }
    return 0;
}
