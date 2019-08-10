#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
char s1[101],s2[101];
int mat[102][102];
int main()
{
    in.get(s1,101);
    in.get();
    in.get(s2,101);
    int len1=strlen(s1),len2=strlen(s2);
    if(s1[0]==s2[0]){
        for(int i=0;i<len1;++i)
            mat[i][0]=1;
        for(int j=0;j<len2;++j)
            mat[0][j]=1;
    }
    for(int i=1;i<len1;++i)
        for(int j=1;j<len2;++j){
            if(s1[i]==s2[j]){
                mat[i][j]=1+mat[i-1][j-1];
            }
            else{
                if(mat[i][j-1]>mat[i-1][j])
                    mat[i][j]=mat[i][j-1];
                else
                    mat[i][j]=mat[i-1][j];
            }
        }
    for(int i=0;i<len1;++i){
        for(int j=0;j<len2;++j)
            out<<mat[i][j]<<" ";
        out<<"\n";
    }


    out<<mat[len1-1][len2-1]<<"\n";

    int nr=1;
    for(int i=0;i<len1;++i)
        for(int j=0;j<len2;++j)
            if(mat[i][j]==nr){
                out<<s1[i];
                ++nr;
            }
    return 0;
}
