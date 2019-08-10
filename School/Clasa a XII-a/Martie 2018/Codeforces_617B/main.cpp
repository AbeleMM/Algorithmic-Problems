#include <iostream>
using namespace std;
int n, temp;
bool a[101], ok = false;
long long sol = 1;
int main()
{
    int i;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    i=1;
    while(i <= n){
        if(a[i] == 1){
            ok = true;

            temp = 1, i++;
            while(i <= n && a[i] == 0){
                temp++, i++;
            }
            if(a[i] == 1)
                sol *= temp;
        }
        else
            i++;
    }
    cout<<sol * ok;
    return 0;
}
