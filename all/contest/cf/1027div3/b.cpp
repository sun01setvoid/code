#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k;
        string s;
        int c0=0,c1=0;
        cin>>n>>k;
        cin>>s;
        for (int i=0;i<n;i++){
            if (s[i]=='0') c0++;
            else c1++;
        }
        int d=n/2-k;
        if (c1>=d && c0>=d){
            if ((c1-d)%2==0 && (c0-d)%2==0){
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
}