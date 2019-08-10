#include <iostream>
#define alf 25
using namespace std;
int n;
bool graf[alf+1][alf+1];
char ant[102],cur[102];
bool viz[26];
inline int mn(unsigned int a, unsigned int b){
    if(a<b)
        return a;
    else
        return b;
}
void df_ciclu(int k){
    viz[k]=true;
    for(int i=0;i<=alf;++i)
}
int main()
{
    cin>>n;
    cin>>ant;
    for(int i=2;i<=n;++i){
        cin>>cur;
        int len=mn(strlen(ant),strlen(cur));
        int j=0;
        while(j<=len && ant[j]!=cur[j])
            mat[ant[j]-'a'][cur[j]-'a']=true;
        cur=strcpy(ant);
    }
    for(int i=0;i<=alf;++i)
        if(v[i]<2)
            df_ciclu(i);
    return 0;
}
