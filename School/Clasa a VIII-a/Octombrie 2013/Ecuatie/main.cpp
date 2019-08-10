#include <iostream>

using namespace std;

int main()
{
    float a,b,x;
    cout<<"Introduceti primul termen: ";
    cin>>a;
    cout<<"Introduceti cel de al doilea termen: ";
    cin>>b;
    if (a==0)
    {
         cout<<"Ecuatia nu are solutie!";
    }

    else
    {
          x=-b/a;
          cout<<"Valoare necunoscutei este: "<<x<<";";
    }


    return 0;
}
