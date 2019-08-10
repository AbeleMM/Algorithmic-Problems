#include <iostream>

using namespace std;
int n;
struct nod{
    int val;
    struct nod *st;
    struct nod *dr;
}*r;
void creeaza(struct nod *&r){
    cout<<"val: ";
    cin>>n;
    if(n!=0){
        r=new nod;
        r->val=n;
        creeaza(r->st);
        creeaza(r->dr);
    }
    else r=NULL;
}
void rsd(struct nod *r){
    if(r!=NULL){
        cout<<r->val<<" ";
        rsd(r->st);
        rsd(r->dr);
    }
}
void srd(struct nod *r){
    if(r!=NULL){
        srd(r->st);
        cout<<r->val<<" ";
        srd(r->dr);
    }
}
void sdr(struct nod *r){
    if(r!=NULL){
        sdr(r->st);
        sdr(r->dr);
        cout<<r->val<<" ";
    }
}
int main()
{
    creeaza(r);
    cout<<"\n";
    //cout<<r->val<<"\n\n";
    rsd(r);
    cout<<"\n\n";
    /*srd(r);
    cout<<"\n\n";
    sdr(r);
    cout<<"\n";*/
    return 0;
}
