#include <iostream>

using namespace std;
int n, m;
bool graf[501][501], ciclu;
short int viz[501], p[501], x, y, st, fin;
void dfs(int k, bool formParent) {
    int i;
    viz[k] = 1;
    for(i=1; i<=n; i++) {
        if(graf[k][i] == true and viz[i] == 0) {
                p[i] = k;
            dfs(i, formParent);
        }
        else if(graf[k][i] == true and viz[i] == 1) {
            if(formParent == true) {
                st = k;
                fin = i;
            }
            ciclu = true;
        }
    }
    viz[k] = 2;
}
int main()
{
    int i;
    cin>>n>>m;
    for(i=1; i<=m; i++) {
        cin>>x>>y;
        graf[x][y] = true;
    }
    for(i=1; i<=n; i++)
        if(viz[i] == 0)
            dfs(i, true);
    if(ciclu == false)
        cout<<"YES";
    else {
        int stCur = st, finCur = fin;
         do{
            graf[stCur][finCur] = false;

            ciclu = false;
            for(i=1; i<=n; i++)
                viz[i] = 0;
            for(i=1; i<=n; i++)
                if(viz[i] == 0)
                    dfs(i, true);

            graf[stCur][finCur] = true;

            finCur = stCur;
            stCur = p[stCur];
        }while(ciclu == true and stCur != 0 and (stCur != st or finCur != fin));

        if(ciclu == false)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
