#include <bits/stdc++.h>
const int N=2e5+10;
int a[N];
using namespace  std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        for (int i=1;i<n;i++) cin>>a[i];
        for (int i=4,j=3;i<=n-3;i+=2,j+=2){
            if (a[i]-a[i-2]>0 && a[j]-a[j-2]>0){
                
            }
            else if (a[i]-a[i-2]<0 && a[j]-a[j-2]<0){

            }
        }
    }
}