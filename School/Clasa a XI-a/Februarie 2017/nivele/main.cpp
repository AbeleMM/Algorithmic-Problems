#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nivele.in");
ofstream out("nivele.out");
int n,k,p[101],nr;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>p[i];
    in>>k;
    int tmp;
    for(int i=1;i<=k;++i){
        nr=0;
        in>>tmp;
        while(tmp!=0){
            ++nr;
            tmp=p[tmp];
        }
        out<<nr<<"\n";
    }
    return 0;
}
