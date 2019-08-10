#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,x,k;
char t;
struct nod{
    int val;
     struct nod *st,*dr;
}*r,*p,*q;
void inserare(int x){
    if(r==NULL){
        p=new nod;
        p->val=x;
        p->st=NULL;
        p->dr=NULL;
        r=p;
    }
    else{
        p=r;
        while(p!=NULL){
            q=p;
            if(x<p->val)
                p=p->st;
            else if(x>p->val)
                p=p->dr;

        }
        p=new nod;
        p->val=x;
        p->st=NULL;
        p->dr=NULL;
        if(x<q->val)
            q->st=p;
        else
            q->dr=p;
    }
}
void stergere(int x){
    //cauta x in BST
    p=r;
    while(p->val!=x && p!=NULL){
        q=p;
        if(x<p->val)
            p=p->st;
        else
            p=p->dr;
    }

    if(p==NULL){}//daca nu exista x in BST - stop
    else if(p->st==NULL && p->dr==NULL){//daca x e frunza
        if(q->st==p)
            q->st=NULL;
        else
            q->dr=NULL;
        delete p;
    }
    else if(p->st!=NULL && p->dr==NULL){//daca are doar fiu stang
        if(q->st==p)
            q->st=p->st;
        else
            q->dr=p->st;
        delete p;
    }
    else if(p->st==NULL && p->dr!=NULL){//daca are doar fiu drept
        if(q->st==p)
            q->st=p->dr;
        else
            q->dr=p->dr;
        delete p;
    }
    else{//daca are ambii fii
        q=p;
        struct nod*f=p->st;
        while(f->dr!=NULL){
            q=f;
            f=f->dr;
        }
        p->val=f->val;
        if(p==q)
            q->st=NULL;
        else
            q->dr=f->st;
        delete f;
    }
}
void parcurgere(struct nod *r){
    if(r!=NULL){
        out<<r->val<<" ";
        parcurgere(r->st);
        parcurgere(r->dr);
    }
}
int main()
{
    in>>t;
    while(t!='0'){
        if(t=='i'){
            in>>x;
            inserare(x);
        }
        else if(t=='s'){
            in>>x;
            stergere(x);
        }
        else if(t=='p'){
            parcurgere(r);
            out<<"\n";
        }
        in.get();
        in>>t;
    }
    return 0;
}
