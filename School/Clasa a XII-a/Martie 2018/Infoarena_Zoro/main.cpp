#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream in("zoro.in");
ofstream out("zoro.out");
int n, m, st, sf;
struct coord_elem{
    int x, y;
}v[10000001];
int linie[1001], coloana[1001];// valoarea maxima din a i-a linie sau coloana
int main()
{
    int i, j, e;

    // e - elem curent
    in>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++){
            in>>e;
            if(i == 1 and j == 1)
                st = e;
            v[e].x = i, v[e].y = j;
        }
    sf = e;

    // e - valoarea maxima intre linie si coloana
    for(i=st; i>=sf; i--){
        if(!(v[i].x == 0 and v[i].y ==0)){
            //stabilim maximul
            if(linie[v[i].x] > coloana[v[i].y])
                e = linie[v[i].x];
            else
                e = coloana[v[i].y];
            e +=1;

            if(e >= linie[v[i].x])
                linie[v[i].x] = e;
            if(e >= coloana[v[i].y])
                coloana[v[i].y] = e;
        }
    }
    out<<e;
    return 0;
}
