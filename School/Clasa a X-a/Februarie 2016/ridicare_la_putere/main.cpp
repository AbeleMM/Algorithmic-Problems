#include <iostream>
//#include <time.h>
//#include <cstdio>
using namespace std;
int n,p;
unsigned long long pw(int n, int p){
    unsigned long long nr;
    if(p==0)
        return 1;
    else if(p%2==0){
        nr=pw(n,p/2);
        return nr*nr;
    }
    else{
        nr=pw(n,p/2);
        return n*nr*nr;
    }
}
int main()
{
    cin>>n>>p;
    //clock_t tStart = clock();
    cout<<pw(n,p)<<"\n";
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
