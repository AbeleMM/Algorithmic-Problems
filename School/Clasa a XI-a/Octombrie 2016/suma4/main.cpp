#include <iostream>
#include <fstream>
#define inf 633650;
using namespace std;
ifstream in("suma4.in");
ofstream out("suma4.out");
int n,pir[59][59][59],alt[59][59][59],s=inf;
int si,sj;
int mn(int a,int b,int c,int d){
    if(a==0)
        a=inf;
    if(b==0)
        b=inf;
    if(c==0)
        c=inf;
    if(d==0)
        d=inf;
    if(a<=b && a<=c && a<=d)
        return a;
    if(b<=a && b<=c && b<=d)
        return b;
    if(c<=a && c<=b && c<=d)
        return c;
    if(d<=a && d<=b && d<=c)
        return d;
}
void recon(int h,int i,int j){
    if(h>=1 && i>=1 && i<=h && j>=1 && j<=h){
        if(pir[h-1][i-1][j-1]==0)
            pir[h-1][i-1][j-1]=inf;
        if(pir[h-1][i-1][j]==0)
            pir[h-1][i-1][j]=inf;
        if(pir[h-1][i][j-1]==0)
            pir[h-1][i][j-1]=inf;
        if(pir[h-1][i][j]==0)
            pir[h-1][i][j]=inf;


        if(pir[h-1][i-1][j-1]<=pir[h-1][i-1][j] && pir[h-1][i-1][j-1]<=pir[h-1][i][j-1] && pir[h-1][i-1][j-1]<=pir[h-1][i][j])
            recon(h-1,i-1,j-1);
        else if(pir[h-1][i-1][j]<=pir[h-1][i-1][j-1] && pir[h-1][i-1][j]<=pir[h-1][i][j-1] && pir[h-1][i-1][j]<=pir[h-1][i][j])
            recon(h-1,i-1,j);
        else if(pir[h-1][i][j-1]<=pir[h-1][i-1][j-1] && pir[h-1][i][j-1]<=pir[h-1][i-1][j] && pir[h-1][i][j-1]<=pir[h-1][i][j])
            recon(h-1,i,j-1);
        else if(pir[h-1][i][j]<=pir[h-1][i-1][j-1] && pir[h-1][i][j]<=pir[h-1][i-1][j] && pir[h-1][i][j]<=pir[h-1][i][j-1])
            recon(h-1,i,j);
        out<<alt[h][i][j]<<" ";
    }
}
int main()
{
    in>>n;
    int h=1,i=1,j=1;
    for(int k=1;k<=n;++k){
        in>>pir[h][i][j];
        alt[h][i][j]=k;
        ++j;
        if(j>h)
            j=1,++i;
        if(i>h)
            i=1,++h;
    }
    --h;
    out<<h<<" ";
    for(int k=2;k<=h;++k)
        for(i=1;i<=k;++i)
            for(j=1;j<=k;++j)
                pir[k][i][j]+=mn(pir[k-1][i][j],//centru
                                pir[k-1][i][j-1],//E
                                pir[k-1][i-1][j-1],//SE
                                pir[k-1][i-1][j]);//S
    for(i=1;i<=h;++i)
            for(int j=1;j<=h;++j)
                if(pir[h][i][j]<s){
                    s=pir[h][i][j];
                    si=i;
                    sj=j;
                }
    out<<s<<"\n";
    recon(h,si,sj);
    return 0;
}
