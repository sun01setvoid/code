#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector <int> a(n);
        int cnt=0;
        for (int i=0;i<n;i++){
            cin>>a[i];
            if (a[i]==1) cnt++;
        }
        if (cnt==n) {
            cout<<"YES\n";
            continue;
        }
        bool f=0;
        for (int i=1;i<n;i++){
            if(a[i]==0 && a[i-1]==0) {
                f=1;
                break;
            }
        }
        if (f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}