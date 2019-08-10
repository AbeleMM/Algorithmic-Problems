#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
long long n, l, pretMin=numeric_limits<long long>::max();
struct bottle{
    long long c/*ost*/;
    long long s/*ize*/;
}v[31];
long long pw=1, cantitCur=0, pretCur=0, dif;
double vx,vy;
inline bool conditie(bottle x, bottle y){
    vx = double(x.s)/x.c;
    vy = double(y.s)/y.c;
    return vx>vy;
}
int main()
{
    int i;

    cin>>n>>l;

    for(i = 1; i<=n; i++){
        cin>>v[i].c;
        v[i].s = pw;
        pw*=2;
    }

    sort(v+1, v+n+1, conditie);

    for(i = 1; i<=n && cantitCur<l; i++){
        dif = l-cantitCur;
        pretCur+= v[i].c * (dif / v[i].s);
        cantitCur+= v[i].s * (dif / v[i].s);

        if(dif % v[i].s != 0) {
            pretCur+= v[i].c;
            cantitCur+= v[i].s;
        }

        if(pretCur < pretMin)
            pretMin = pretCur;
        cantitCur-= v[i].s;
        pretCur-= v[i].c;
    }
    cout<<pretMin;
    return 0;
}
