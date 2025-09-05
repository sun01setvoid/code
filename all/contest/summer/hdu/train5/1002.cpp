#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
#define pa pair<int,int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr<<#x<<'='<<(x)<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
//再不卷就退役了
const int z = 2e5 + 10;
const int zz = 2e5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int n, m, k, p;
vii a(z);
bool check(int x) {
    if (x * k * p < m)return false;
    int del = 0, sum = 0, cnt = 0, res = 0;
    vii tmp;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k * x && cnt < p) {
            sum += k * x;
            cnt++;
        }
        else if (a[i] >= k * x)continue;
        else if (a[i] < k * x && cnt < p) {
            int t = a[i] / k;
            sum += t * k;
            del += x - t;
            tmp.pb(a[i] % k);
            cnt++;
        }
        else {
            int t = a[i] / k;
            res += t;
            tmp.pb(a[i] % k);
        }
        if (sum >= m)return true;
    }
    if (res >= del)sum += del * k;
    else {
        sort(tmp.rbegin(), tmp.rend());
        sum += res * k;
        del -= res;
        int len = tmp.size();
        len = min(del, len);
        for (int i = 0; i < len; i++)sum += tmp[i];
    }
    return sum >= m;
}
void solve() {
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++)cin >> a[i];
    sort(a.rbegin(), a.rend());
    int l = 0, r = m, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    cout << res << endl;
}
signed main() {
    IOS;
    int t = 1;
    cin >> t;
    while (t--)solve();
}