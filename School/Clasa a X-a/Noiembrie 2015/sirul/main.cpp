#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("sirul.in");
ofstream out("sirul.out");
char s1[7000],s2[7000],alt[7000];
int n;
int main()
{
    in>>n;
    s1[0]='a';s2[0]='b';
    for(int i=3;i<=n;++i){
        strcpy(alt,s2);
        strcat(s2,s1);
        strcpy(s1,alt);
    }
    if(n>1)
        out<<s2;
    else
        out<<"a";
    return 0;
}
