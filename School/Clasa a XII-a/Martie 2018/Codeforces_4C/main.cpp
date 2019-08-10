#include <iostream>
#include <map>
#include <string>
using namespace std;
int n;
map <string, int> db;
string s;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>s;
        if(db.find(s) != db.end()){
            db[s]++;
            cout<<s<<db[s]<<"\n";
        }
        else{
            db.insert(make_pair(s, 0));
            cout<<"OK\n";
        }
    }
    return 0;
}
