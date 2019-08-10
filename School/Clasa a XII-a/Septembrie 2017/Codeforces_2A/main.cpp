#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n,nr,t,j,sc;
string s;
struct chestie{
    int v[1001];// suma partiala
    int r[1001];//runda obtinerii fiecarei sume
    int i;//indice
}aux;

map <string,chestie> m;
map <string,chestie>::const_iterator it;


int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s>>nr;
        if(m.find(s)!=m.end()){
            m[s].i++;
            m[s].v[m[s].i]=m[s].v[m[s].i-1]+nr;
            m[s].r[m[s].i]=i;
        }
        else{
            chestie aux;
            aux.i=1;
            aux.v[1]=nr;
            aux.r[1]=i;
            m.insert({s,aux});
        }
    }
    nr=t=0;
    for(it=m.begin();it!=m.end();it++){
        sc=0;
        chestie aux=it->second;
        if(aux.v[aux.i]>nr){
            s=it->first;
            nr=aux.v[aux.i];
            j=1;
            while(aux.v[j]<aux.v[aux.i]){
                j++;
            }
            t=aux.r[j];
        }
        else if(aux.v[aux.i]==nr){
            j=1;
            while(aux.v[j]<aux.v[aux.i]){
                j++;
            }
            if(aux.r[j]<t){
                s=it->first;
                t=aux.r[j];
            }
        }
    }
    cout<<s;
    return 0;
}
