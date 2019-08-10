#include <iostream>
#include <fstream>
using namespace std;
ifstream in("windows.in");
ofstream out("windows.out");
int n,t;
struct fereastra{
    int x1;
    int y1;
    int x2;
    int y2;
    bool s;
}
v[102];
int overlap(int a, int b)
{
    if(v[a].x1<=v[b].x1 && v[a].x2>=v[b].x1 && v[a].y1<=v[b].y2 && v[a].y2>=v[b].y2)
        return 1;
    return 0;
}
void inchide(int nr)
{
    for(int i=n-1;i>=nr+1;i--)
        if(!v[i].s && overlap(i,nr))
            inchide(i);
    v[nr].s=true;
    t++;
}
int main()
{
    in>>n;
    for(int i=0;i<n;i++)
        in>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
    for(int i=0;i<n;i++)
        v[i].s=false;
    inchide (0);
    out<<t;
    return 0;
}
