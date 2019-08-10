#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("expresie.in");
ofstream out("expresie.out");
char e[1005];
int len;
struct coada{
    long long inf;
    struct coada *ant;
    struct coada *urm;
}*p,*prim,*ultim,*q;
int s[1005];
int vfs;
bool ok=true;
void eval(){
    if(e[0]=='*' || e[0]==')')
        ok=false;
    for(int i=0;i<len-1 && ok==true;++i){
        if(((e[i]=='+' || e[i]=='*') && (e[i+1]=='+' || e[i+1]=='*')) || (e[i]>='0' && e[i]<='9' && e[i+1]>='0' && e[i+1]<='9'))
            ok=false;
        if(e[i]=='(')
            ++vfs;
        if(e[i]==')')
            --vfs;
        if(vfs<0)
            ok=false;
    }
    if(e[len-1]=='*' || e[len-1]=='(' || e[len-1]=='+')
        ok=false;
    if(e[len-1]==')')
        --vfs;
    if(vfs!=0)
        ok=false;
}
void exp_pfix(){
    vfs=0;
    prim=new coada;
    prim->urm=NULL;
    prim->ant=NULL;
    ultim=prim;
    for(int i=0;i<len;++i){
        if(e[i]>='0' && e[i]<='9'){
            p=new coada;
            if(p!=NULL){
                p->inf=e[i]-'0';
                p->urm=NULL;
                p->ant=ultim;
                ultim->urm=p;
                ultim=p;
            }
        }
        else if(e[i]=='+'){
            while((s[vfs]==-5 || s[vfs]==-6) && vfs>0){
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
            s[vfs]=e[i]-'0';
        }
        else if(e[i]=='*'){
            while(s[vfs]==-6 && vfs>0){
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
            s[vfs]=e[i]-'0';
        }
        else if(e[i]=='('){
            ++vfs;
            s[vfs]=e[i]-'0';
        }
        else if(e[i]==')'){
            while(s[vfs]!=-8 && vfs>0){
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
        if(p->inf==-5){
            q=p->ant->ant->ant;
            p->inf=p->ant->inf+q->urm->inf;
            delete p->ant;
            delete q->urm;
            q->urm=p;
            p->ant=q;
        }
        else if(p->inf==-6){
            q=p->ant->ant->ant;
            p->inf=p->ant->inf*q->urm->inf;
            delete p->ant;
            delete q->urm;
            q->urm=p;
            p->ant=q;
        }
        p=p->urm;
    }
    out<<ultim->inf<<"\n";
}
int main()
{
    in>>e;
    len=strlen(e);
    eval();
    if(ok==true)
        exp_pfix();
    else
        out<<"-1";
    return 0;
}
