#include <iostream>
#include <cstring>
using namespace std;
char s[100001];
int len;
bool existaLit[26]; // v[1] - a, v[2] - b, ... v[25] - z;
int nrLit[26]; //nr. de aparitii al unei anume litere in subsirul curent

inline bool check(int valK){
    int i;
    // -1 = ineligibil, 0 = inca nu gasit (subsir curent), 1 = gasit (subsir curent)

    for(i=0; i<=25; i++)
        existaLit[i] = false, nrLit[i] = 0;

    //vedem literele prezente in primul subsir de lungime k
    for(i=0; i<valK; i++)
        existaLit[s[i] - 'a'] = true, nrLit[s[i] - 'a']++;

    //verificam daca celelalte subsiruri de lungime k au macar o litera comuna (cu primul subsir)
    for(i=valK; i<len; i++){
        nrLit[s[i]-'a']++;
        nrLit[s[i - valK] - 'a']--;
        if(nrLit[s[i - valK] - 'a'] == 0)
            existaLit[s[i - valK] - 'a'] = false;
    }

    for(i=0; i<=25; i++)
        if(existaLit[i] == 1)
            return true;
    return false;
}

inline int bs(int st, int dr){
    int mj = st+(dr-st)/2;
    if(check(mj) == false)
        return bs(mj+1, dr);
    else{
        if(check(mj-1) == false || mj-1 < 1)
            return mj;
        else
            return bs(st, mj-1);
    }
}

int main()
{
    cin>>s;
    len = strlen(s);
    cout<<bs(1, len/2+1);
    return 0;
}
