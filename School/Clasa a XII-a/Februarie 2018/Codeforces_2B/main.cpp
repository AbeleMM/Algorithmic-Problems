#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct putere{
    int p2, p5;
}mat[1001][1001];
string s;
int main()
{
    int i, j, val;

    cin>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n ;j++){
            cin>>val;
            if(val == 0){
                mat[i][j].p2 = mat[i][j].p5 = 1;
            }
            while(val%2 == 0)
                mat[i][j].p2++, val /=2;
            while(val%5 == 0)
                mat[i][j].p5++, val /=5;
        }

    for(i=2; i<=n; i++)
        for(j=2; j<=n; j++){
            if(mat[i-1][j].p2 < mat[i][j-1].p2)
                mat[i][j].p2 += mat[i-1][j].p2;
            else
                mat[i][j].p2 += mat[i][j-1].p2;

            if(mat[i-1][j].p5 < mat[i][j-1].p5)
                mat[i][j].p5 += mat[i-1][j].p5;
            else
                mat[i][j].p5 += mat[i][j-1].p5;
        }

    cout<<min(mat[n][n].p2, mat[n][n].p5);
    return 0;
}
