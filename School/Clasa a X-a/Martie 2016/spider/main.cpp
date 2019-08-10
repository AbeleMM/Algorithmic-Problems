#include <iostream>
#include <fstream>
using namespace std;
ifstream in("spider.in");
ofstream out("spider.out");
int n,m,a[1002][1002];
int t,e,f,p,s1,s2,s3,s4;
unsigned long long nrmx,nrc;
void sm(int x, int  y, bool ok){
    if(ok==true)
        out<<x<<" "<<y<<"\n";
    if(p==3 || a[x][y]-a[x-1][y]<0 || x-1<=0)
        s1=-1;
    else
        s1=a[x][y]-a[x-1][y];
    if(p==4 || a[x][y]-a[x][y+1]<0 || y+1>m)
        s2=-1;
    else
        s2=a[x][y]-a[x][y+1];
    if(p==1 || a[x][y]-a[x+1][y]<0 || x+1>n)
        s3=-1;
    else
        s3=a[x][y]-a[x+1][y];
    if(p==2 || a[x][y]-a[x][y-1]<0 || y-1<=0)
        s4=-1;
    else
        s4=a[x][y]-a[x][y-1];
    if(s1!=-1 && (s1<s2 || s2==-1) && (s1<s3 || s3==-1) && (s1<s4 || s4==-1))
        p=1,++nrc,sm(x-1,y,ok);
    else if(s2!=-1 && (s2<s1 || s1==-1) && (s2<s3 || s3==-1) && (s2<s4 || s4==-1))
        p=2,++nrc,sm(x,y+1,ok);

    else if(s3!=-1 && (s3<s1 || s1==-1) && (s3<s2 || s2==-1) && (s3<s4 || s4==-1))
        p=3,++nrc,sm(x+1,y,ok);

    else if(s4!=-1 && (s4<s1 || s1==-1) && (s4<s2 || s2==-1) && (s4<s3 || s3==-1))
        p=4,++nrc,sm(x,y-1,ok);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            nrc=p=0;
            sm(i,j,false);
            if(nrc>nrmx)
                nrmx=nrc,e=i,f=j;
        }
    nrc=0;
    out<<nrmx<<"\n";
    sm(e,f,true);
    return 0;
}
