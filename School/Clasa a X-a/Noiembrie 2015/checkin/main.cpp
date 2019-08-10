#include <iostream>
#include <fstream>
using namespace std;
ifstream in("checkin.in");
ofstream out("checkin.out");
int n,k,p,mn,alt;
struct ghiseu{
    int a;
    int b;
}v[1010];
void quicksort(int st, int dr, int t)
{
    int i=st,j=dr,aux;
    int x=i+(j-i)/2;
    while(i<=j){
        while(i<dr && t*v[i].a+v[i].b<t*v[x].a+v[x].b)
            i++;
        while(j>st && t*v[j].a+v[j].b>t*v[x].a+v[x].b)
            j--;
        if(i<=j){
            aux=v[i].a;
            v[i].a=v[j].a;
            v[j].a=aux;
            aux=v[i].b;
            v[i].b=v[j].b;
            v[j].b=aux;
            i++;
            j--;
        }
    }
    if(st<j)
        quicksort(st,j,t);
    if(i<dr)
        quicksort(i,dr,t);
}
/*int cautare_bin( ){

}*/
int main()
{
    in>>n;
    in>>v[1].a>>v[1].b;
    mn=v[1].a+v[1].b;
    alt=v[1].b;
    for(int i=2;i<=n;++i){
        in>>v[i].a>>v[i].b;
        if(v[i].a+v[i].b<mn)
            mn=v[i].a+v[i].b;
        if(v[i].b<alt)
            alt=v[i].b;

    }
    in>>k>>p;
    if(p==0)
        out<<alt;
    if(p==1)
        out<<mn;
    if(p>1){
        quicksort(1,n,mn);
        for(int i=1;i<=n;i++)
            out<<v[i].a<<" "<<v[i].b<<endl;
        //out<<cautare_bin( );
    }
    return 0;
}
