#include <iostream>

using namespace std;
void afisare_inv(){
    char c;
    cin.get(c);
    if(c!=' ')
        afisare_inv();
    cout<<c;
}
int main()
{
    afisare_inv();
    return 0;
}
