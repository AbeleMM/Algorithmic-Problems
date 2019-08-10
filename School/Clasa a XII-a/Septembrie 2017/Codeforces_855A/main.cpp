#include <iostream>
#include <set>
using namespace std;
int n;
string c;
set <string> s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c;
        if(s.find(c)!=s.end())
            cout<<"YES\n";
        else{
            s.insert(c);
            cout<<"NO\n";
        }
    }
    return 0;
}
