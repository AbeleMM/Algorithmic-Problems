#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n;//dimensiunea logica a vectorului!
int v[10001];
int i;
int main()
{
    f>>n;//citesc dimensiunea logica a vectorului
    for (i=1;i<=n;i++)//parcurg elementele
        f>>v[i];//citesc elementele
    for (i=1;i<=n;i++)
        cout<<v[i]<<"; ";
    cout<<endl;

    return 0;
}
