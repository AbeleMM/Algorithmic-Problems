#include <iostream>
#include <fstream>
#include <algorithm>
//
#include <cstdlib>
#include <ctime>
using namespace std;
ofstream out("date.out");
int n;
struct chestie{
    int a;
    int b;
}v[101];
inline bool conditie(chestie x, chestie y){
    return x.a+x.b<y.a+y.b;
}
int main()
{
    srand (time(NULL));
    n=rand()%10+1;
    for(int i=1;i<=n;++i){
        v[i].a=rand()%100+1;
        v[i].b=rand()%100+1;
    }
    sort(v+1,v+n+1,conditie);
    for(int i=1;i<=n;++i)
        out<<v[i].a<<" ";
    out<<"\n";
    for(int i=1;i<=n;++i)
        out<<v[i].b<<" ";
    return 0;
}
