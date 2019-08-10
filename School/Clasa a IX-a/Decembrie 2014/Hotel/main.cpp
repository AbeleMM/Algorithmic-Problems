#include <iostream>
#include <fstream>
using namespace std;
ifstream in("input.in");
ofstream out("output.out");
int THIS[103][103],n;
void read()
{
    in>>n;
}
void build()
{
    int i,j,nr;
    nr=1;
    for(i=1;i<=n;i++)
    {
        for(j=n;j>=1;j--)
        {
            if(i+j==n)
            {
                THIS[i][j]=nr;
                nr++;
            }
        }
    }
}
void write()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            out<<THIS[i][j]<<" ";
        }
        out<<"\n";
    }
}
int main()
{
    read();
    build();
    write();
    return 0;
}
