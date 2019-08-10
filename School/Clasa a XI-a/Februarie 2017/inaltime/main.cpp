#include <iostream>
#include <fstream>
using namespace std;
ifstream in("inaltime.in");
ofstream out("inaltime.out");
int n,p[101],nr,nmx;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>p[i];
    for(int i=1;i<=n;++i){
        int tmp=i;
        while(tmp!=0){
            tmp=p[tmp];
            ++nr;
        }
        if(nr>nmx)
            nmx=nr;
        nr=0;
    }
    out<<nmx;
    return 0;
}
