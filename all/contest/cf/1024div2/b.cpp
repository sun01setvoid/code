#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<int> a(n);
        int tmp;
        cin>>a[0],a[0]=abs(a[0]);
        tmp=a[0];
        for (int i=1;i<n;i++){
            cin>>a[i];
            a[i]=abs(a[i]);
        }
        sort(a.begin(),a.end());
        if ( lower_bound(a.begin(),a.end(),tmp)-a.begin()>n/2){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
}