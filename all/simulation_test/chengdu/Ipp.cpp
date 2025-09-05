#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
struct SegTree {
    int N;
    vector<int> tr;
    void pushup(int u) {
        tr[u] = __gcd(tr[u*2], tr[u*2+1]);
    }
    void build(int u, int l, int r) {
        if (l == r) {
            tr[u] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(u*2, l, mid);
        build(u*2+1, mid+1, r);
        pushup(u);
    }
    void update(int u, int l, int r, int idx, int val) {
        if (l == r) {
            tr[u] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(u*2, l, mid, idx, val);
        } else {
            update(u*2+1, mid+1, r, idx, val);
        }
        pushup(u);
    }
    SegTree(int size) {
        N = size;
        tr.resize(4*(N+1), 0);
        if (N > 0) {
            build(1, 1, N);
        }
    }
    void update(int idx, int val) {
        if (idx < 1 || idx > N) return;
        update(1, 1, N, idx, val);
    }
    int query() {
        if (N == 0) return 0;
        return tr[1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> cnt(MAXN+1, 0);
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            cnt[j]++;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 1 << '\n';
            while (q--) {
                int p, v;
                cin >> p >> v;
                a[p] = v;
                cout << 1 << '\n';
            }
            continue;
        }
        SegTree seg(n-1);
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i+1]) {
                seg.update(i, i);
            } else {
                seg.update(i, 0);
            }
        }
        int g = seg.query();
        if (g == 0) {
            cout << n << '\n';
        } else {
            cout << cnt[g] << '\n';
        }
        while (q--) {
            int p, v;
            cin >> p >> v;
            if (p > 1) {
                seg.update(p-1, 0);
            }
            if (p < n) {
                seg.update(p, 0);
            }
            a[p] = v;
            if (p > 1) {
                if (a[p-1] > a[p]) {
                    seg.update(p-1, p-1);
                } else {
                    seg.update(p-1, 0);
                }
            }
            if (p < n) {
                if (a[p] > a[p+1]) {
                    seg.update(p, p);
                } else {
                    seg.update(p, 0);
                }
            }
            g = seg.query();
            if (g == 0) {
                cout << n << '\n';
            } else {
                cout << cnt[g] << '\n';
            }
        }
    }
    return 0;
}