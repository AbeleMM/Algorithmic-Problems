#include <iostream>
#include <fstream>
using namespace std;
ifstream in("taxe2.in");
ofstream out("taxe2.out");
int n, s, cost[102][102], suma[102][102];
bool ok = true;
int main()
{
    int i, j;
    in>>s>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            in>>cost[i][j];

    for(i=0; i<=n+1; i++)
        for(j=0; j<=n+1; j++)
            suma[i][j] = -1;
    suma[1][1] = s - cost[1][1];

    while(ok == true) {
        ok = false;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++) {
                if(suma[i-1][j] - cost[i][j] > suma[i][j]) {
                    suma[i][j] = suma[i-1][j] - cost[i][j];
                    ok = true;
                }

                if(suma[i][j-1] - cost[i][j] > suma[i][j]) {
                    suma[i][j] = suma[i][j-1] - cost[i][j];
                    ok = true;
                }

                if(suma[i][j+1] - cost[i][j] > suma[i][j]) {
                    suma[i][j] = suma[i][j+1] - cost[i][j];
                    ok = true;
                }

                if(suma[i+1][j] - cost[i][j] > suma[i][j]) {
                    suma[i][j] = suma[i+1][j] - cost[i][j];
                    ok = true;
                }
            }
    }

    if(suma[n][n]>=0)
        out<<suma[n][n];
    else
        out<<"-1";
    return 0;
}
