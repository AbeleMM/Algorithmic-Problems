#include <iostream>

int main() {
    int nrCases, g1, s1, b1, g2, s2, b2;
    std::cin>>nrCases;
    for (int i = 0; i < nrCases; i++) {
        std::cin>>g1>>s1>>b1>>g2>>s2>>b2;
        std::cout<<((g1 + s1 + b1 > g2 + s2 + b2) ? 1 : 2)<<std::endl;
    }
}
