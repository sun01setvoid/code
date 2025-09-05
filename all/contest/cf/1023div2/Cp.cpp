#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NEG_INF = -1000000000000000000LL;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int dp = 0, ma = LLONG_MIN;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                dp = max(dp + a[i], a[i]);
                ma = max(ma, dp);
                if(dp < 0) dp = 0;
            } 
            else  dp = 0;
        }
        if(ma > k){
            cout << "No\n";
            continue;
        }
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            if(ma == k){
                cout << "Yes\n";
                for(int it : a) cout << it <<" ";
                cout<<"\n";
            } else {
                cout << "No\n";
            }
            continue;
        }
        int suf = 0, Lmax = LLONG_MIN;
        bool f = false;
        for(int i = pos - 1; i >= 0 && s[i] == '1'; i--){
            suf += a[i];
            Lmax = max(Lmax, suf);
            f = true;
        }
        int L = f ? Lmax : 0;
        int pre = 0, Rmax = LLONG_MIN;
        f = false;
        for(int i = pos + 1; i < n && s[i] == '1'; i++){
            pre += a[i];
            Rmax = max(Rmax, pre);
            f = true;
        }
        int R = f ? Rmax : 0;
        int x;
        if(L >= 0 && R >= 0)    x = k - L - R;
        else if(L >= 0 && R <= 0)   x = k - L;
        else if(L <= 0 && R >= 0)   x = k - R;
        else    x = k;
        cout << "Yes\n";
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(i == pos) cout << x;
                else        cout <<NEG_INF;
            } 
            else    cout << a[i];
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}