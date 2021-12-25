#include <iostream>

int main() {
    int nrCases, n, p, k;
    std::cin>>nrCases;
    for (int i = 0; i < nrCases; i++) {
        std::cin>>n>>p>>k;

        int val = n / k * (p % k) + p / k + 1 + std::min(p % k, n % k);
        std::cout<<val<<std::endl;
    }
}
