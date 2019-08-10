#include<iostream>

using namespace std;
int n,nr;
void hanoi(int n,char sursa,char dest, char aux)
{
    nr++;
    if(n==1) cout<<sursa<<"->"<<dest<<"\n";
    else
    {
        hanoi(n-1,sursa,aux,dest);
            cout<<sursa<<"->"<<dest<<"\n";
        hanoi(n-1,aux,dest,sursa);
    }
}
int main()
{
    cin>>n;
    cout<<"\n";
    hanoi(n,'A','B','C');
    cout<<"\n"<<nr;
    return 0;
}
