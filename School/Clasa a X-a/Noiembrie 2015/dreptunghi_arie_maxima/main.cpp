#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
struct coord{
int x;
int y;
}v[100];
int nr,n,m,amax;
void citire(){
    int x;
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;j++){
            in>>x;
            if(x==0)
                nr++,v[nr].x=i,v[nr].y=j;
        }
}
int exista(int x1,int y1,int x2,int y2){
    bool gasit=false;
    int i=1;
    while(i<=nr && gasit==false){
        if(x1<=v[i].x && v[i].x<=x2 && y1<=v[i].y && v[i].y<=y2)
            gasit=true;
        else
            ++i;
    }
    if(gasit==false)
        i=0;
    return i;
}
void impart(int x1,int y1,int x2,int y2){
    int a;
    int i=exista(x1,y1,x2,y2);
    if(i==0){
        a=(x2-x1+1)*(y2-y1+1);
        cout<<a<<" ";
        if(a>amax)
            amax=a;
    }
    else{
        impart(x1,y1,x2,v[i].y-1);
        impart(x1,y1,v[i].x-1,y2);
        impart(x1,v[i].y+1,x2,y2);
        impart(v[i].x+1,y1,x2,y2);
    }
}
int main()
{
    citire();
    impart(1,1,n,m);
    out<<amax;
    return 0;
}
