#include <iostream>

using namespace std;
int n,cm,sol;
bool cat[100001],viz[100001];
struct nod{
    int vecin;
    struct nod *urm;
}*l[100001],*cur;

void df(int k,int c_ant){
    struct nod *cur;
    int cc;
    viz[k]=true;
    cur=l[k];
    bool frunza=true;
    if(cat[k]==0)
        cc=0;
    else
        cc=c_ant+1;
    if(cc<=cm){
        while(cur!=NULL){
        if(viz[cur->vecin]==false){
            df(cur->vecin,cc);
            frunza=false;
        }
        cur=cur->urm;
        }
        if(frunza==true)
            ++sol;
    }
}

int main()
{
    cin>>n>>cm;
    for(int i=1;i<=n;++i)
        cin>>cat[i];
    int a,b;
    for(int i=1;i<n;++i){
        cin>>a>>b;

        cur=new nod;
        cur->vecin=b;
        cur->urm=l[a];
        l[a]=cur;

        cur=new nod;
        cur->vecin=a;
        cur->urm=l[b];
        l[b]=cur;
    }
    df(1,0);
    cout<<sol;
    return 0;
}
