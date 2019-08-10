#include <iostream>
#define mod 1000000007
using namespace std;
int n;
char v[5001];
unsigned long long mat[5001][5001], sol;
int main()
{
    int i, j;
    cin>>n;
    for(i=1; i<=n; i++) {
        cin>>v[i];
    }
    mat[1][1] = 1;
    for(i=2; i<=n; i++) {
        if(v[i-1] == 'f') {
            for(j=0; j<=i; j++)
                mat[i][j+1] = mat[i-1][j];
        }
        else {
            for(j=i; j>=1; j--)
                    mat[i][j] = (mat[i][j+1] + mat[i-1][j]) % mod;
        }
    }
    for(i=1; i<=n; i++)
        sol =  (sol + mat[n][i]) % mod;
    cout<<sol;
    return 0;
}
