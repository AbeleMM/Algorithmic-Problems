#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sumdiv.in");
ofstream out("sumdiv.out");
int n,a,b;
int ciur[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
unsigned long long s[1000000];
/*void ce(){
    ciur[0]=true;
    ciur[1]=true;
    for(int i=3;i*i<=1000000;i+=2)
        if(ciur[i]==false)
            for(int j=3;j<=1000000/i;j+=2)
                ciur[j*i]=true;
    out<<"2,";
    for(int i=3;i<=1000;i+=2)
        if(ciur[i]==false)
            out<<i<<",";
}
void calc(){
    unsigned long long sm=1;
    s[1]=1;
    for(int i=2;i<=1000000;++i){
        int nr=0;
        sm+=1+i;
        while(ciur[nr]*ciur[nr]<=i){
            int nralt=1;
            while(ciur[nr]*ciur[nr]*nralt*nralt<i){
                if(i%(ciur[nr]*nralt)==0){
                    sm+=ciur[nr]*nralt;
                    sm+=i/(ciur[nr]*nralt);
                }
                ++nralt;
            }
            if(ciur[nr]*nralt==i/(ciur[nr]*nralt) && i%(ciur[nr]*nralt)==0)
                sm+=ciur[nr]*nralt;
            ++nr;
        }
        s[i]=sm;
    }
    for(int i=1;i<=1000000;++i)
        out<<s[i]<<", ";
}*/
long long exp(int x, int n){
    long long p=1;
    while(n>0){
        if(n%2==1){
            p=p*x;
            --n;
        }
        else{
            x=x*x;
            n/=2;
        }
    }
    return p;
}
void s_desc(){
    long long sm=1;
    s[1]=1;
    for(int i=2;i<=1000000;++i){
        long long sd=1;
        int nr=0,ialt=i;
        while(ialt>0){
            long long f=0;
            while(ialt%s[nr]==0 && ialt>0){
                ++f;
                ialt/=s[nr];
            }
            if(f>0)
                sd*=((exp(s[nr],f+1)-1)/(s[nr]-1));
            ++nr;
        }
        sm+=sd;
        s[i]=sm;
    }
}
int main()
{
    s_desc();
    /*in>>n;
    for(int i=1;i<=n;++i){
        in>>a>>b;
        out<<s[b]-s[a-1]<<"\n";
    }*/
    return 0;
}
