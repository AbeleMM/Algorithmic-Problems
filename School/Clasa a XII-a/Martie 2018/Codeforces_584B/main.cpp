#include <iostream>

using namespace std;
const long mod = 1000000007;
unsigned long long sol = 0, n;

inline unsigned long long ridic_put(unsigned long long exp, unsigned long long put){
    unsigned long long rez = 1;
    while(put > 0){
        if(put % 2 == 1){
            rez = (rez * exp) % mod;
            put--;
        }
        exp = (exp * exp) % mod;
        put /= 2;
    }
    return rez;
}

int main()
{
    cin>>n;
    // adaugam mod dupa prima ridicare la putere petru a ne asigura
    sol = (ridic_put(3, n*3) + mod - ridic_put(7, n)) % mod;
    cout<<sol;
    return 0;
}
