#include <iostream>

using namespace std;
int a, b, n;
const int mod = 1000000007;
long long sol, fact[1000001];

inline bool isGood(long long nr){
    while(nr > 0){
        if(!(nr%10 == a || nr%10 == b))
            return false;
        nr /=10;
    }
    return true;
}

// (a / b) % m = (a % m * inv(b) % m) % m;
long long inv(long long exp){ // inversul modular al lui a = a^(mod-2); mod trebuie sa fie nr. prim;
    long long rez = 1, p = mod - 2;
    while(p > 0){
        if(p%2 == 1){
            rez = (rez *exp) % mod;
            p--;
        }
        exp = (exp * exp) % mod;
        p /= 2;
    }
    return rez % mod;
}

int main()
{
    int i;

    cin>>a>>b>>n;

    fact[0] = fact[1] = 1;
    for(i=2; i<=n; i++)
        fact[i] = (fact[i-1] * i) % mod;

    for(i=0; i<=n; i++){ // i - cate cifre a sunt in numarul de n cifre
        if(isGood(a * i + b * (n - i))){
            sol = (sol + (fact[n] * inv((fact[n-i] * fact[i]) % mod)) % mod) % mod;
        }
    }

    cout<<sol;
    return 0;
}
