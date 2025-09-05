#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)

const int maxn = 1e5 + 10;
int st[maxn];
vector<int> primes;
void init_primes(int n) {
    rep(i, 2, n) {
        if (!st[i]) {
            st[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > n / i) break;
            st[p * i] = p;
            if (i % p == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> vis(n + 1, false); 
    rep(i, 1, n) a[i] = i;
    for (int i = primes.size() - 1; i >= 0; --i) {
        int p = primes[i];
        if (p > n) continue;
        vector<int> gouzao;
        for (int j = p; j <= n; j += p) {
            if (!vis[j]) {
                gouzao.push_back(j);
            }
        }
        if (gouzao.size() > 1) {
            repn(k, 0, gouzao.size()) {
                int cur = gouzao[k];
                int ne = gouzao[(k + 1) % gouzao.size()];
                a[cur] = ne;
                vis[cur] = true;
            }
        }
    }
    rep(i, 1, n) cout << a[i] << (i == n ? '\n' : ' ');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init_primes(1e5);  // 预处理质数
    
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}