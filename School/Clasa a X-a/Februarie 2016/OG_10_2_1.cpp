#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("adn.in");
ofstream out("adn.out");
char s[100005],salt[100005];
int n;
int main()
{
    in>>n;
    in.get();
    in>>s;
    strcpy(salt,s);
    int i=n-2;
    bool ok=false;
    while(i>0 && ok==false){
        if(s[i]<s[i+1]){
            ok=true;
            int poz;
            char t='T';
            char aux;
            for(int j=i+1;j<n;++j)
                if(s[j]>=s[i-1] && s[j]<=t){
                    poz=j;
                    t=s[j];
                }
            aux=s[i];
            s[i]=s[poz];
            s[poz]=aux;
            while(ok==true){
                ok=false;
                for(int j=i+1;j<n-1;++j)
                    if(s[j]>s[j+1]){
                        aux=s[j];
                        s[j]=s[j+1];
                        s[j+1]=aux;
                        ok=true;
                    }
            }
            ok=true;
        }
        --i;
    }

    i=n-2;
    ok=false;
    while(i>0 && ok==false){
        if(salt[i]>salt[i+1]){
            ok=true;
            int poz;
            char t='A';
            char aux;
            for(int j=i+1;j<n;++j){
                if(salt[j]<salt[i] && salt[j]>=t){
                    poz=j;
                    t=salt[j];
                }
            }
            aux=salt[i];
            salt[i]=salt[poz];
            salt[poz]=aux;
            while(ok==true){
                ok=false;
                for(int j=i+1;j<n-1;++j)
                    if(salt[j]<salt[j+1]){
                        aux=salt[j];
                        salt[j]=salt[j+1];
                        salt[j+1]=aux;
                        ok=true;
                    }
            }
            ok=true;
        }
        --i;
    }
    out<<s<<"\n"<<salt;
    return 0;
}
