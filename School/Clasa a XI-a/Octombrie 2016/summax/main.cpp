#include <iostream>
#include <fstream>
using namespace std;
ifstream in("summax.in");
ofstream out("summax.out");
int n,st,dr,v[2002][2002],p;
bool trec[2002][2002];
int s=0,smax=0;
int parc1(int i,int j,int nr){
    if(i>=1 && i<=n && j>=1 && j<=i){
        if(v[i-1][j-1]>v[i-1][j]/* && trec[i-1][j-1]==false*/){
            //trec[i-1][j-1]=true;
            return parc1(i-1,j-1,nr);
        }
        if(v[i-1][j]>v[i-1][j-1]/* && trec[i-1][j]==false*/){
            //trec[i-1][j]=true;
            return parc1(i-1,j,nr);
        }
        if(v[i-1][j-1]==v[i-1][j]){
            /*trec[i-1][j-1]=true;
            trec[i-1][j]=true;*/
            return parc1(i-1,j-1,nr)+parc1(i-1,j,nr);
        }
    }
    return nr;
}
void p0(){
    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j)
            if(v[i-1][j-1]>v[i-1][j])
                v[i][j]+=v[i-1][j-1];
            else
                v[i][j]+=v[i-1][j];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    for(int j=1;j<=n;++j)
        if(v[n][j]>smax)
            smax=v[n][j];
}
void p1(){
    for(int j=1;j<=n;++j)
        if(v[n][j]==smax){
            int sc=1;
            parc1(n,j,sc);
            if(s+sc<=2000000000)
                s+=sc;
            else
                s=2000000001;
        }
    out<<s;
}
void p2(){

}
int main()
{
    in>>p>>n>>st>>dr;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            in>>v[i][j];
    if(p==1){
        p0();
        p1();
    }
    else if(p==2){
        p0();
        p2();
    }
    return 0;
}
