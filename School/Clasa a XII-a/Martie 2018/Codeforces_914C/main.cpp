#include <iostream>
#include <cstring>
using namespace std;
short int k, nrTransf[1001], len, sumUnu[1001], nrUnuCur;
char n[1001];
long long sol, comb[1001][1001];

short int transf(short int val){
    short int nou = 0;
    while(val != 0){
        nou += val%2;
        val /=2;
    }
    return nou;
}

int main()
{
    int i, j, nr;

    cin>>n;
    cin>>k;

    for(i=2; i<=1000; i++){
        nr = i;
        while(nr != 1){
            ++nrTransf[i];
            nr = transf(nr);
        }
    }

    for(i=0; i<=100; i++){
        comb[i][0] = comb[i][i] = 1;
        for(j=1; j<i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % 1000000007;
    }

    len = strlen(n);
    sumUnu[0] = n[0] - '0';
    for(i=1; i<len; i++)
        sumUnu[i] = sumUnu[i-1] + (n[i] - '0');

    if((len < 10) or (len == 10 and strcmp(n, "1111101000") <= 0)){
        int temp = 0, put =1;
        for(i=len-1; i>=0; i--){
            temp += (n[i] - '0') * put;
            put *=2;
        }
        for(i=2; i<=temp; i++)
            if(nrTransf[i] == k)
                ++sol;
    }
    else{
        for(i=0; i<len; i++){
            for(j=2; j<=1000; j++)
                if(sumUnu[j] == k - nrUnuCur - 1)
                    sol = (sol + comb[len - 1 - i][sumUnu[j]]) % 1000000007;
            nrUnuCur += n[i] - '0';
        }
    }

    cout<<sol;
    return 0;
}
