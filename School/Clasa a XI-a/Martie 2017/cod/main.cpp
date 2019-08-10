#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cod.in");
ofstream out("cod.out");
int n,k,m,sol[35],nr,s;
inline void init(int e){
    sol[e]=0;
}
bool succesor(int e){
    if(s+sol[e]<n){
        ++sol[e];
        return 1;
    }
    else{
        s-=sol[e-1];
        return 0;
    }

}
bool valid(int e){
    if(sol[e]>m)
        return 0;
    else{
        s+=sol[e];
        return 1;
    }
}
inline bool solutie(int e){
    if(s==n && e==k){
        s-=sol[e];
        return 1;
    }
    else
        return 0;
}
void bk(int e){
    init(e);
    while(succesor(e))
        if(valid(e)){
            if (solutie(e))
                ++nr;
            else
                bk(e+1);
        }
}
int main()
{
    in>>n>>k>>m;
    bk(1);
    out<<nr;
    return 0;
}
