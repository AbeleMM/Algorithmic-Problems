#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("compresie.in");
ofstream out(compresie.out);
char s[1000005],m[1005][1005];
long nr;
int n;
int main()
{
    in>>s;
    long alt=strlen(s);
    for(long i=0;i<alt;++i)
        if(s[i]=='*')
            nr++;
    out<<nr;
    return 0;
}
