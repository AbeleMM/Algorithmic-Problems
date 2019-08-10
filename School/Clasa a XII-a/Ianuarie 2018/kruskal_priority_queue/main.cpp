// kruskal w/ priority_queue (coada de prioritati)
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("apm.in");
ofstream out("apm.out");

int n, m, s, nr; // s - cost APM, nr - numar muchii APM
struct muchie {
    int x, y, c; // nodX, nodY, cost;
}v[400001];

int p[200001]/*p[i] - multimea lui i*/, rang[200001], sol[200001];
int radX, radY;

inline bool crit(struct muchie a, struct muchie b) {
    return a.c < b.c;
}

inline void make_set(int x) {
    p[x]=x;
    rang[x]=0;
}
inline int find_set(int x) {
    if(p[x]!=x)
        p[x] = find_set(p[x]);
    return p[x];
}
inline void unite_set(int radX, int radY) {
    if(rang[radX] < rang[radY])
        p[radX] = radY;
    else if(rang[radX] > rang[radY])
        p[radY] = radX;
    else {
        p[radY] = radX;
        rang[radX]++;
    }
}

void kruskal(){
    int i;
    for(i=1; i<=n; i++) // initial fiecare nod apartine propriei multimi
        make_set(i);

    for(i=1; i<=m &&  nr<n-1; i++) {
        radX = find_set(v[i].x);
        radY = find_set(v[i].y);
        if(radX != radY) {
            unite_set(radX, radY);

            ++nr;
            sol[nr] = i;
            s += v[i].c;
        }
    }
}

int main()
{
    int i;
    in>>n>>m;
    for(i=1; i<=m; i++)
        in>>v[i].x>>v[i].y>>v[i].c;
    sort(v+1, v+m+1, crit);

    kruskal();

    out<<s<<"\n"<<nr<<"\n";
    for(i=1; i<=nr; i++)
        out<<v[sol[i]].y<<" "<<v[sol[i]].x<<"\n";
    return 0;
}
