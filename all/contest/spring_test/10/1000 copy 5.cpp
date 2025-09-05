#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int t,n,m;
        cin>>t>>n>>m;
        vector<int> a(n);
        for (auto &i:a){
            cin>>i;
        }
        sort(a.begin(),a.end());
        int cnt=0;
        for (int i=0;i<a.size();i++){
            if (a[i]<=t) ++cnt,t-=a[i];
            if (cnt==m) break;
        }
        if (cnt==m){
            cout<<t/40;
        }
        else cout<<-1<<"\n";
    }
}