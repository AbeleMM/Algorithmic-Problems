#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
FILE * in=fopen("zimeria.in","r");
FILE * out=fopen("zimeria.out","w");
int p,n;
char s[14],aux[7];
int v[248835],t,pz,nr,mx,mn=250000;
void cerinta_1(){
    for(int i=1;i<=n;++i){
        fscanf(in,"%s",aux);
        t=0,pz=20736;
        for(int j=0;j<5;j++){
            t+=(strchr(s,aux[j])-s)*pz;
            pz=pz/12;
        }
        if(v[t]==0)
            ++v[t],++nr;
    }
    fprintf(out,"%i",nr);
}
void cerinta_2(){
    for(int i=1;i<=n;++i){
        fscanf(in,"%s",aux);
        t=0,pz=20736;
        for(int j=0;j<5;++j){
            t+=(strchr(s,aux[j])-s)*pz;
            pz=pz/12;
        }
        ++v[t];
        if(t>mx)
            mx=t;
        if(t<mn)
            mn=t;
    }
    for(int i=mn;i<=mx;++i)
        if(v[i]>0){
            int nr=i;
            for(int j=0;j<5;++j){
                t=nr%12;
                aux[4-j]=s[t];
                nr=(nr-t)/12;
            }
            aux[5]='\0';
            for(int j=1;j<=v[i];++j)
            fprintf(out,"%s \n",aux);
        }
}
int main()
{
    fscanf(in,"%i %i",&p,&n);
    fscanf(in,"%s",s);
    if(p==1)
        cerinta_1();
    if(p==2)
        cerinta_2();
    return 0;
}
