#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("comp.in");
ofstream out("comp.out");
char s[260];
int n,nr,c,pz;
long t1,t2;
bool ok,v[1005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i){
        in>>s;
        if(strchr(s,'<')!=NULL)
            pz=strchr(s,'<')-s,nr++,ok=false;
        else
            pz=strchr(s,'>')-s,ok=true;
        int l=strlen(s);
        t1=0,t2=0;
        for(int j=0;j<pz;++j){
            c=0;
            while(s[j]>='0' && s[j]<='9')
                c=c*10+(s[j]-'0'),++j;
            if(s[j]=='u')
                t1+=c;
            if(s[j]=='z')
                t1+=10*c;
            if(s[j]=='s')
                t1+=100*c;
            if(s[j]=='m')
                t1+=1000*c;
        }
        for(int j=pz+1;j<l;j++){
            c=0;
            while(s[j]>='0' && s[j]<='9')
                c=c*10+(s[j]-'0'),++j;
            if(s[j]=='u')
                t2+=c;
            if(s[j]=='z')
                t2+=10*c;
            if(s[j]=='s')
                t2+=100*c;
            if(s[j]=='m')
                t2+=1000*c;
        }
        if(ok==false){
            if(t1>t2)
                v[i]=false;
            if(t1<t2)
                v[i]=true;
        }
        else{
            if(t1>t2)
                v[i]=true;
            if(t1<t2)
                v[i]=false;
        }
    }
    out<<nr<<"\n";
    for(int i=1;i<=n;++i){
        if(v[i]==false)
            out<<"0\n";
        else
            out<<"1\n";
    }
    return 0;
}
