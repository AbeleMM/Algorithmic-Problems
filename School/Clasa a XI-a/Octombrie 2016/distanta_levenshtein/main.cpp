#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char s1[103],s2[103],sf[206];
int len1,len2,v[102][102],len3;//linii -> s1 & coloane->s2
int mn(int a,int b,int c){
    if(a<=b && a<=c)
        return a;
    if(b<=a && b<=c)
        return b;
    if(c<=a && c<=b)
        return c;
}
int main()
{
    cin.get(s1+1,103);
    cin.get();
    cin.get(s2+1,103);
    len1=strlen(s1+1);
    len2=strlen(s2+1);
    for(int i=1;i<=len1;++i){
        if(s1[i]==s2[1])
            v[i][1]=v[i-1][1];
        else
            v[i][1]=v[i-1][1]+1;
    }
    for(int i=2;i<=len2;++i){
        if(s1[1]==s2[i])
            v[1][i]=v[1][i-1];
        else
            v[1][i]=v[1][i-1]+1;
    }
    for(int i=2;i<=len1;++i)
        for(int j=2;j<=len2;++j){
            if(s1[i]==s2[j])
                v[i][j]=mn(v[i-1][j]+1,v[i][j-1]+1,v[i-1][j-1]);
            else
                v[i][j]=mn(v[i-1][j]+1,v[i][j-1]+1,v[i-1][j-1]+1);
        }
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n\n";
    cout<<v[len1][len2]<<"\n \n";
    int i=1,j=1;
    strcpy(sf+1,s1+1);
    len3=len1;
    if(v[1][1]==1)
        sf[1]=s2[1];
    while(i<=len1 && j<=len2){
        if((v[i][j+1]>v[i][j] || j+1>len2) && (v[i+1][j+1]>v[i][j] || (i+1>len1 || j+1>len2)) && (v[i+1][j]>v[i][j] || i+1>len1))
            cout<<sf+1<<"\n";
        if(v[i+1][j+1]<=v[i][j+1] && v[i+1][j+1]<=v[i+1][j]){
            sf[j+1]=s2[j+1];
            ++i,++j;
        }
        else if(v[i][j+1]<=v[i+1][j+1] && v[i][j+1]<=v[i+1][j]){
            ++len3;
            //sf[len3+1]='\0';
            for(int k=len3;k>i+1;--k)
                sf[k]=sf[k-1];
            sf[i+1]=s2[j+1];
            ++j;
        }
        else if(v[i+1][j]<=v[i][j+1] && v[i+1][j]<=v[i+1][j+1]){
            for(int k=i+1;k<=len3;++k)
                sf[k]=sf[k+1];
            --len3;
            ++i;
        }
    }
    cout<<sf+1<<"\n";
    return 0;
}
