#include <iostream>
#include <fstream>
using namespace std;
int v,n,k;
struct puncte{
    int xa,ya,xb,yb,xc,yc;
    int xmn,xmx,ymn,ymx;
}cd[101];
inline int minim(int a, int b){
    if(a<=b)
        return a;
    else
        return b;
}
inline int maxim(int a, int b){
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    in>>v>>n>>k;
    for(int i=1;i<=n;++i){
        in>>cd[i].xa>>cd[i].ya>>cd[i].xb>>cd[i].yb>>cd[i].xc>>cd[i].yc;
        //
        /*if(cd[i].xa<=cd[i].xb && cd[i].xa<=cd[i].xc)
            cd[i].xmn=cd[i].xa;
        else if(cd[i].xb<=cd[i].xa && cd[i].xb<=cd[i].xc)
            cd[i].xmn=cd[i].xb;
        else
            cd[i].xmn=cd[i].xc;

        if(cd[i].xa>=cd[i].xb && cd[i].xa>=cd[i].xc)
            cd[i].xmx=cd[i].xa;
        else if(cd[i].xb>=cd[i].xa && cd[i].xb>=cd[i].xc)
            cd[i].xmx=cd[i].xb;
        else
            cd[i].xmx=cd[i].xc;
        //
        if(cd[i].ya<=cd[i].yb && cd[i].ya<=cd[i].yc)
            cd[i].ymn=cd[i].ya;
        else if(cd[i].yb<=cd[i].ya && cd[i].yb<=cd[i].yc)
            cd[i].ymn=cd[i].yb;
        else
            cd[i].ymn=cd[i].yc;

        if(cd[i].ya>=cd[i].yb && cd[i].ya>=cd[i].yc)
            cd[i].ymx=cd[i].ya;
        else if(cd[i].yb>=cd[i].ya && cd[i].yb>=cd[i].yc)
            cd[i].ymx=cd[i].yb;
        else
            cd[i].ymx=cd[i].yc;*/
    }

    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j){
            if(minim(cd[j].xa,cd[j].xb)<=cd[i].xa && cd[i].xa<=maxim(cd[j].xa,cd[j].xb))
                calc(cd[j].xa,cd[j].ya,cd[j].xb,cd[j].yb,cd[i].xa,false);
            if(minim(cd[j].xb,cd[j].xc)<=cd[i].xa && cd[i].xa<=maxim(cd[j].xb,cd[j].xc))
                calc(cd[j].xb,cd[j].yb,cd[j].xc,cd[j].yc,cd[i].xa,false);
            if(minim(cd[j].xa,cd[j].xc)<=cd[i].xa && cd[i].xa<=maxim(cd[j].xa,cd[j].xc))
                calc(cd[j].xa,cd[j].ya,cd[j].xc,cd[j].yc,cd[i].xa,false);
            //
            if(minim(cd[j].xa,cd[j].xb)<=cd[i].xb && cd[i].xb<=maxim(cd[j].xa,cd[j].xb))
                calc(cd[j].xa,cd[j].ya,cd[j].xb,cd[j].yb,cd[i].xb,false);
            if(minim(cd[j].xb,cd[j].xc)<=cd[i].xb && cd[i].xb<=maxim(cd[j].xb,cd[j].xc))
                calc(cd[j].xb,cd[j].yb,cd[j].xc,cd[j].yc,cd[i].xb,false);
            if(minim(cd[j].xa,cd[j].xc)<=cd[i].xb && cd[i].xb<=maxim(cd[j].xa,cd[j].xc))
                calc(cd[j].xa,cd[j].ya,cd[j].xc,cd[j].yc,cd[i].xb,false);
            //
            if(minim(cd[j].xa,cd[j].xb)<=cd[i].xc && cd[i].xc<=maxim(cd[j].xa,cd[j].xb))
                calc(cd[j].xa,cd[j].ya,cd[j].xb,cd[j].yb,cd[i].xc,false);
            if(minim(cd[j].xb,cd[j].xc)<=cd[i].xc && cd[i].xc<=maxim(cd[j].xb,cd[j].xc))
                calc(cd[j].xb,cd[j].yb,cd[j].xc,cd[j].yc,cd[i].xc,false);
            if(minim(cd[j].xa,cd[j].xc)<=cd[i].xc && cd[i].xc<=maxim(cd[j].xa,cd[j].xc))
                calc(cd[j].xa,cd[j].ya,cd[j].xc,cd[j].yc,cd[i].xc,false);
            /*

            */
            if(minim(cd[j].ya,cd[j].yb)<=cd[i].ya && cd[i].ya<=maxim(cd[j].ya,cd[j].yb))
                calc(cd[j].ya,cd[j].xa,cd[j].yb,cd[j].xb,cd[i].ya,true);
            if(minim(cd[j].yb,cd[j].yc)<=cd[i].ya && cd[i].ya<=maxim(cd[j].yb,cd[j].yc))
                calc(cd[j].yb,cd[j].xb,cd[j].yc,cd[j].xc,cd[i].ya,true);
            if(minim(cd[j].ya,cd[j].yc)<=cd[i].ya && cd[i].ya<=maxim(cd[j].ya,cd[j].yc))
                calc(cd[j].ya,cd[j].xa,cd[j].yc,cd[j].xc,cd[i].ya,true);
            //
            if(minim(cd[j].ya,cd[j].yb)<=cd[i].yb && cd[i].yb<=maxim(cd[j].ya,cd[j].yb))
                calc(cd[j].ya,cd[j].xa,cd[j].yb,cd[j].xb,cd[i].yb,true);
            if(minim(cd[j].yb,cd[j].yc)<=cd[i].yb && cd[i].yb<=maxim(cd[j].yb,cd[j].yc))
                calc(cd[j].yb,cd[j].xb,cd[j].yc,cd[j].xc,cd[i].yb,true);
            if(minim(cd[j].ya,cd[j].yc)<=cd[i].yb && cd[i].yb<=maxim(cd[j].ya,cd[j].yc))
                calc(cd[j].ya,cd[j].xa,cd[j].yc,cd[j].xc,cd[i].yb,true);
            //
            if(minim(cd[j].ya,cd[j].yb)<=cd[i].yc && cd[i].yc<=maxim(cd[j].ya,cd[j].yb))
                calc(cd[j].ya,cd[j].xa,cd[j].yb,cd[j].xb,cd[i].yc,true);
            if(minim(cd[j].yb,cd[j].yc)<=cd[i].yc && cd[i].yc<=maxim(cd[j].yb,cd[j].yc))
                calc(cd[j].yb,cd[j].xb,cd[j].yc,cd[j].xc,cd[i].yc,true);
            if(minim(cd[j].ya,cd[j].yc)<=cd[i].yc && cd[i].yc<=maxim(cd[j].ya,cd[j].yc))
                calc(cd[j].ya,cd[j].xa,cd[j].yc,cd[j].xc,cd[i].yc,true);
        }
    return 0;
}
