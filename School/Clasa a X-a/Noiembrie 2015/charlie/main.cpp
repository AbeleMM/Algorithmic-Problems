#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("charlie.in");
ofstream out("charlie.out");
int p,l,nr;
char s[100010];
void cerinta_1(){
    l=strlen(s);
    /*int c=1,nr=0,i=0;
    while(i<l-2){
        while(s[i]>s[i+1] && s[i+1]<s[i+2] && i<l-2)
            ++c,i+=2;
        c+=2;
        if(c>nr)
            nr=c;
        c=1,i++;
    }*/
    nr=1;
    for(int i=1;i<l;i++)
    {
        int j=i;
        while(j<l && s[j-1]>s[j] && s[j]<s[j+1])
            j++;
        if(j==l-1)
            j++;
        if(j-i>nr)
            nr=j-i;
    }
    out<<nr;
}
void cerinta_2(){

}
int main()
{
    in>>p;
    in.get();
    in.get(s,100010);
    if(p==1)
        cerinta_1();
    if(p==2)
        cerinta_2();
    return 0;
}
