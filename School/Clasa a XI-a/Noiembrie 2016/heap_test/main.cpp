#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
void constr(int n, int v[]){
    for(int i=1;i<=n;++i){
        in>>v[i];
        int poz=i;
        //parcurgem taticii nodului adaugat si interchimbam daca e mai mare ca acestia
        while(poz>1 && v[poz/2]<v[poz]){
            int t;
            t=v[poz/2];
            v[poz/2]=v[poz];
            v[poz]=t;
            poz/=2;
        }
    }
}
void elimvf(int &n,int v[]){
    //prelucram v[1];
    v[1]=v[n];//punem ultimul element pe prima pozitie
    n--;//scadem nr de elem
    int poz=1;
    //parcurgem descendentii sai
    while(2*poz<=n){
        int fiu=2*poz;
        if(fiu+1<=n && v[fiu]<v[fiu+1])// daca fiul drept exista si este mai mare decat cel stang
            fiu++;
        if(v[fiu]>v[poz]){//daca descendentul cel mai mare este mai mare decat tatal interschimbam
            int t;
            t=v[poz];
            v[poz]=v[fiu];
            v[fiu]=t;
            poz=fiu;
        }
        else poz=n+1;
    }
}
int main()
{
    int n,v[101];
    in>>n;
    constr(n,v);
    for(int i=1;i<=n;++i)
        out<<v[i]<<" ";
    out<<"\n\n";
    elimvf(n,v);
    for(int i=1;i<=n;++i)
        out<<v[i]<<" ";
    return 0;
}
