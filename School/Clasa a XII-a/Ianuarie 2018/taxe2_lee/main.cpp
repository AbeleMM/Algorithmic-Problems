//lee
#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
using namespace std;
ifstream f("taxe2.in");
ofstream g("taxe2.out");
queue< pair< int,int > >coada;
int a[105][105];
int sol[105][105];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int s,n;
int main()
{
    int i,j;
    f>>s>>n;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            f>>a[i][j];

    for(i=0; i<=n+1; i++)
        sol[i][0] = sol[i][n+1] = sol[0][i] = sol[n+1][i] = -1;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            sol[i][j] = INT_MAX;

    sol[1][1]=a[1][1];
    coada.push(make_pair(1,1));
    int x,y;

    while(coada.empty()==false)
    {
        x=coada.front().first;
        y=coada.front().second;
        for(int i=0; i<4;i++)
        {
            if(sol[x][y] + a[x+dx[i]][y+dy[i]] < sol[x+dx[i]][y+dy[i]])
                {
                    sol[x+dx[i]][y+dy[i]] = sol[x][y] + a[x+dx[i]][y+dy[i]];
                    coada.push(make_pair(x+dx[i], y + dy[i]));
                }
        }
        coada.pop();
    }

    if(s < sol[n][n])
        g<<"-1";
    else
        g<<s-sol[n][n];

    return 0;
}
