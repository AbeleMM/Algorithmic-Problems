#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream in("text.in");
ofstream out("text.out");
char s[200];

int main()
{
    in.get(s,200);
    cout<<s<<"\n";
    cout<<strlen(s);
    return 0;
}
