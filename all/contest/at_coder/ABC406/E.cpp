#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll N;int K;
struct node {
    ll cnt;  
    ll sum;  
    node() : cnt(0), sum(0) {}
    node(ll cnt, ll sum) : cnt(cnt), sum(sum) {}
};
node dp[61][61][2];
bool vis[61][61][2];
node dfs(int pos, int cnt, int limit, const string &s) {
    if (pos == s.size()) {
        return node(cnt == K, 0);
    }
    if (vis[pos][cnt][limit]) {
        return dp[pos][cnt][limit];
    }
    vis[pos][cnt][limit] = true;
    node res;
    int md = limit ? (s[pos] - '0') : 1;
    for (int d = 0; d <= md; ++d) {
        int new_limit = limit && (d == md);
        int new_cnt = cnt + (d == 1);
        if (new_cnt > K) continue;
        node tmp = dfs(pos + 1, new_cnt, new_limit, s);
        res.cnt = (res.cnt + tmp.cnt) % MOD;
        res.sum = (res.sum + tmp.sum + (d ? (1LL << (s.size() - pos - 1)) % MOD * tmp.cnt % MOD : 0)) % MOD;
    }
    return dp[pos][cnt][limit] = res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;    
        string s;
        while (N > 0) {
            s += (N % 2) + '0';
            N /= 2;
        }
        reverse(s.begin(), s.end());
        memset(vis, false, sizeof(vis));
        node res = dfs(0, 0, 1, s);
        cout << res.sum << '\n';
    }
    return 0;
}