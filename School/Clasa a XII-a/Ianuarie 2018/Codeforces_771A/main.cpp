#include <iostream>

using namespace std;
long long n,m,x,y,nrm,nrn;
struct nod {
    long long inf;
    struct nod *urm;
}*l[150001],*cur;
bool ok = true, viz[150001];

void dfs(int k){
    struct nod *cur;
    viz[k] = true;
    ++nrn;
    for(cur = l[k]; cur !=NULL; cur = cur->urm){
        ++nrm;
        if(viz[cur->inf] == false)
            dfs(cur->inf);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        cur = new nod;
        cur->inf = y;
        cur->urm = l[x];
        l[x] = cur;

        cur = new nod;
        cur->inf = x;
        cur->urm = l[y];
        l[y] = cur;
    }
    for(int i=1; i<=n && ok == true; i++){
        if(viz[i] == false){
            nrm = nrn = 0;
            dfs(i);
            if(nrn*(nrn-1)/2 != nrm/2)
                ok = false;
        }
    }
    if(ok == true)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
