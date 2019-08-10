#include <iostream>
#include <fstream>
using namespace std;
ifstream in("rascoala.in");
ofstream out("rascoala.out");
int p,n,m,k;
struct harta{
    int s;
    int x;
    int y;
} h[250052],aux;
int f,nr,mx;
void rezolvare_1(){
    for(int i=0;i<f;++i)
        for(int j=i+1;j<=f;++j){
            if(h[i].s>h[j].s){
                aux=h[i];
                h[i]=h[j];
                h[j]=aux;
            }
            else if(h[i].s==h[j].s){
                if(h[i].x>h[j].x){
                    aux=h[i];
                    h[i]=h[j];
                    h[j]=aux;
                }
                else if(h[i].x==h[j].x){
                    if(h[i].y>h[j].y){
                        aux=h[i];
                        h[i]=h[j];
                        h[j]=aux;
                    }
                }
            }
        }


    out<<"s x y \n";
    for(int i=1;i<=f;++i)
        out<<h[i].s<<" "<<h[i].x<<" "<<h[i].y<<"\n";
    out<<" \n \n \n \n";


    //qsort();
    int i=1;
    while(k>0){
        ++i;
        ++h[i].s;
        --k;
        if(h[i].s<=h[i+1].s)
            i=0;
        else
            if(mx<i)
                mx=i;
    }
    out<<mx<<"\n";
    if(h[mx].s>h[mx+1].s)
        out<<h[mx+1].s;
    else
        out<<h[mx].s;
}
/*void qsort(){
    int i,st=1,dr=1,j,alt;
    int x=(j-i)/2;
    while(i<=j)

}*/
bool mic(int st, int dr){
    if(h[st].s<h[dr].s)
        return 1;
    else if(h[st].s==h[dr].s){
        if(h[st].x<h[dr].x)
            return 1;
        else if(h[st].x==h[dr].x){
            if(h[st].y<h[dr].y)
                return 1;
        }
    }
    return 0;
}
bool mare(int st, int dr){
    if(h[st].s>h[dr].s)
        return 1;
    else if(h[st].s==h[dr].s){
        if(h[st].x>h[dr].x)
            return 1;
        else if(h[st].x==h[dr].x){
            if(h[st].y>h[dr].y)
                return 1;
        }
    }
    return 0;
}
int main()
{
    in>>p>>n>>m>>k;
    f=n*m;
    for(int i=1;i<=f;++i){
        in>>h[i].s;
        h[i].x=i/n+(i%n!=0);
        if(i%m==0)
            h[i].y=m;
        else
            h[i].y=i%m;
    }
    if(p==1)
        rezolvare_1();
    return 0;
}
