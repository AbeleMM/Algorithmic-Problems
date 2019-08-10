#include <iostream>
#include <fstream>
using namespace std;
ifstream in("joc9.in");
ofstream out("joc9.out");
int n, matA[136][136], matB[136][136], matC[136][136], maxA, maxB, maxC, stA, stB, stC, sol, start;
int main()
{
    int i, j;
    in>>n;
    for(i=1; i<=n+1; i++)
        for(j=1; j<=i; j++){
            in>>matA[i][j];
            matC[i][j] = matB[i][j] = matA[i][j];
            if(i == 1 && j == 1)
                stA = matA[i][j];
            else if(i == n+1 && j == 1)
                stB = matB[i][j];
            else if(i == n+1 && j == n+1)
                stC = matC[i][j];
        }

    // matA inspre BC; pozA = 1, 1
    for(i=1; i<=n+1; i++)
        for(j=1; j<=i; j++){
            matA[i][j] += max(matA[i-1][j], matA[i-1][j-1]);
        }

    for(j=1; j<=n+1; j++)
        if(matA[n+1][j] > maxA)
            maxA = matA[n+1][j];

    // matB inspre AC; pozB = n+1, 1
    for(i=n+1; i>=1; i--)
        for(j=1; j<=i; j++){
            matB[i][j] += max(matB[i][j-1], matB[i+1][j]);
        }

    for(i=1; i<=n+1; i++)
        if(matB[i][i] > maxB)
            maxB = matB[i][i];

    // matC inspre BC; pozC = n+1, n+1
    for(i=n+1; i>=1; i--)
        for(j=n+1; j>=1; j--){
            matC[i][j] += max(matC[i][j+1], matC[i+1][j+1]);
        }

    for(i=1; i<=n+1; i++)
        if(matC[i][1] > maxC)
            maxC = matC[i][1];
    //
    sol = max(max(maxA, maxB), maxC);
    if(sol == maxA){
        start = stA;
        if(sol == maxB)
            start = min(start, stB);
        if(sol == maxC)
            start = min(start, stC);
    }
    else if(sol == maxB){
        start = stB;
        if(sol == maxA)
            start = min(start, stA);
        if(sol == maxC)
            start = min(start, stC);
    }
    else if(sol == maxC){
        start = stC;
        if(sol == maxA)
            start = min(start, stA);
        if(sol == maxB)
            start = min(start, stB);
    }

    out<<sol<<"\n"<<start;
    return 0;
}
