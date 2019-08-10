#include <iostream>

using namespace std;
int n,d,h;
int c,aux;
int main()
{
    cin>>n>>d>>h;
    if((d>2*h) or (d==1 && n>2))
        cout<<"-1";
    else{
        for(int i=1;i<=h;++i){
            cout<<i<<" "<<i+1<<"\n";
        }
        c=h+1;
        if(h!=d){
            c++;
            cout<<"1 "<<c<<"\n";
            for(int i=1;i<d-h;++i){
                c++;
                cout<<c-1<<" "<<c<<"\n";
            }
            while(c+1<=n){
                c++;
                cout<<"1 "<<c<<"\n";
            }
        }
        else{
            aux=c-1;
            while(c+1<=n){
                c++;
                cout<<aux<<" "<<c<<"\n";
            }
        }
    }
    return 0;
}
