#include <iostream>

int main() {
    int nrCases, n;
    std::cin>>nrCases;
    for (int i = 0; i < nrCases; i++) {
        std::cin>>n;
        int nr = 0;
        for (int c = 1; c <= n; c++) {
            int b = 2 * c;
            while (b <= n) {
                int f = 0;
                while (f * b + c <= n) {
                    nr++;
                    f++;
                }
                b += c;
            }
        }
        std::cout<<nr<<std::endl;
    }
}
