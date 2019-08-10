#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("emm.in");
ofstream out("emm.out");
char e[100005];
int len,vfs,s[100005];
struct coada{
    long long inf;
    struct coada *ant;
    struct coada *urm;
}*p,*prim,*ultim,*q;
int main()
{
    in>>e;
    len=strlen(e);
    prim= new coada;
    prim->urm=NULL;
    prim->ant=NULL;
    ultim=prim;
    int i;
    for(i=0;i<len;++i){
        if(e[i]>='0' && e[i]<='9'){
            long long nr=e[i]-'0';
            while(e[i+1]>='0' && e[i+1]<='9'){
                ++i;
                nr=nr*10+e[i]-'0';
            }
            p=new coada;
            if(p!=NULL){
                p->inf=nr;
                p->urm=NULL;
                p->ant=ultim;
                ultim->urm=p;
                ultim=p;
            }
        }
        else if(e[i]=='m'){
            while(s[vfs]!=-3 && vfs>0){
                p=new coada;
                if(p!=NULL){
                    p->inf=s[vfs];
                    p->urm=NULL;
                    p->ant=ultim;
                    ultim->urm=p;
                    ultim=p;
                }
                --vfs;
            }
            ++vfs;
            s[vfs]=-1;
        }
        else if(e[i]=='M'){
            while(s[vfs]!=-3 && vfs>0){
                p=new coada;
                if(p!=NULL){
                    p->inf=s[vfs];
                    p->urm=NULL;
                    p->ant=ultim;
                    ultim->urm=p;
                    ultim=p;
                }
                --vfs;
            }
            ++vfs;
            s[vfs]=-2;
        }
        else if(e[i]=='('){
            ++vfs;
            s[vfs]=-3;
        }
        else if(e[i]==')'){
            while(s[vfs]!=-3 && vfs>0){
                p=new coada;
                if(p!=NULL){
                    p->inf=s[vfs];
                    p->urm=NULL;
                    p->ant=ultim;
                    ultim->urm=p;
                    ultim=p;
                }
                --vfs;
            }
            --vfs;
        }
    }
    while(vfs>0){
        p=new coada;
        if(p!=NULL){
            p->inf=s[vfs];
            p->urm=NULL;
            p->ant=ultim;
            ultim->urm=p;
            ultim=p;
        }
        --vfs;
    }
    p=prim->urm;
    while(p!=NULL){
        if(p->inf==-1){
            q=p->ant->ant->ant;
            if(p->ant->inf<q->urm->inf)
                p->inf=p->ant->inf;
            else
                p->inf=q->urm->inf;
            //delete p->ant;
            //delete q->urm;
            q->urm=p;
            p->ant=q;
        }
        else if(p->inf==-2){
            q=p->ant->ant->ant;
            if(p->ant->inf>q->urm->inf)
                p->inf=p->ant->inf;
            else
                p->inf=q->urm->inf;
            //delete p->ant;
            //delete q->urm;
            q->urm=p;
            p->ant=q;
        }
        p=p->urm;
    }
    out<<ultim->inf<<"\n";
    return 0;
}
