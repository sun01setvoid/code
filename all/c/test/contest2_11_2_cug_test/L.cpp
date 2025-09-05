#include <iostream>
using namespace std;
int main(){
    int a[100000],n,l,max=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    l=(n-1)/2;
    for (int i=n-1-l;i<n;i++){
        if (a[i]>max)
        max=a[i];
    }
    cout<<max;
    getchar();
    getchar();
}