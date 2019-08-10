#include <fstream>
#include <map>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
map <string, pair<int,int>> m;//pair first = suma note, pair second = nr. note;
map <string, pair<int,int>>::const_iterator it;
int n,t;
string s;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i){
        in>>s>>t;
        if(m.find(s)!=m.end()){
            m[s].first+=t;
            m[s].second++;
        }
        else{
            //m.insert(make_pair(s,make_pair(t,1)));
            /* alternativa */
            m.insert({s,{t,1}});
        }
    }
    for(it=m.begin();it!=m.end();it++){
        out<<it->first<<" ";
        out<<float(it->second.first)/it->second.second<<"\n";
    }
    return 0;
}
