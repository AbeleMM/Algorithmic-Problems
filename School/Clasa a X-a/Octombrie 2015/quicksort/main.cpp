#include <iostream>

using namespace std;
long v[100010];
int n;
void quicksort(long a[100010], int st, int dr)
{
    int i=st,j=dr,t;
    int x=a[i+(j-i)/2];
    while(i<=j){
        while(i<dr && a[i]<x)
            i++;
        while(j>st && a[j]>x)
            j--;
        if(i<=j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }
    if(st<j)
        quicksort(a,st,j);
    if(i<dr)
        quicksort(a,i,dr);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    quicksort(v,1,n);
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    return 0;
}
