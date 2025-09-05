#include <bits/stdc++.h>
using namespace std;
bool isp(int x){
    if (x==1) return false;
    for(int i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        if (k==1){
            if (isp(n))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else {
            if (n!=1) cout<<"NO\n";
            else{
                if (k==2) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}