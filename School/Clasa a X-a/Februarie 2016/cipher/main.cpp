#include <iostream>
#include <cstring>
using namespace std;
int n,v[202],k,len;
char s[204],salt[204],t;
int main()
{
    salt[0]=' ';
    do{
        cin>>n;
        if(n!=0){
            for(int i=1;i<=n;++i)
                cin>>v[i];
            do{
                cin.get();
                cin>>k;
                if(k!=0){
                    cin.get(s,204);
                    len=strlen(s);
                    int i;
                    for(i=len;i<=n;++i)
                        s[i]=' ';
                    s[i+1]='\0';
                    for(int j=1;j<=k;++j){
                        for(int l=1;l<=n;++l){
                            salt[v[l]]=s[l];
                        }
                        salt[i+1]='\0';
                        strcpy(s,salt);
                    }
                    cout<<s+1<<"\n";
                }
            }while(k!=0);
        }
    }while(n!=0);
    return 0;
}
