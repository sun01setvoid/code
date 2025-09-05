#include <iostream>
#include <algorithm>
using namespace std;
int a[5010];
int main(){
    int n,temp=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=n-1;i>=0;i--){
        if (temp<a[(i+n-1)/2]+n-i)
            temp=a[(i+n-1)/2]+n-i;
    }
    cout<<temp;
}