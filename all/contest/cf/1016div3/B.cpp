#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        bool f=0;
        int ans=0;
        for (int i=s.size()-1;i>=0;i--){
            if (s[i]!='0'){
                if (!f) f=1;
                else{
                    ans++;
                }
            }
            else{
                if (!f) ans++;
            }
        }
        cout<<ans<<"\n";
    }
}