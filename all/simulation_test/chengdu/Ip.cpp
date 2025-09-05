#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const int N=2e5+10;
int cnt[N];
struct SegmentTree {
    int n;
    vector<int> tree;
 
    void init(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }
 
    void build(const vector<int> &a, int idx = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, idx * 2, l, mid);
        build(a, idx * 2 + 1, mid + 1, r);
        tree[idx] = gcd(tree[idx * 2], tree[idx * 2 + 1]);
    }
 
    void update(int pos, int val, int idx = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(pos, val, idx * 2, l, mid);
        else update(pos, val, idx * 2 + 1, mid + 1, r);
        tree[idx] = gcd(tree[idx * 2], tree[idx * 2 + 1]);
    }
 
    int query() { return n ? tree[1] : 0; }
 
    void erase(int pos) {
        update(pos, 0);
    }
};
 
struct GoodPartition {
    int n;
    set<int> breaks;               
    vector<int> diff;              
    map<int, int> pos_map;         
    SegmentTree st;
 
    void build() {
        diff.clear();
        pos_map.clear();
        vector<int> pts(breaks.begin(), breaks.end());
        for (int i = 0; i + 1 < (int)pts.size(); i++) {
            int d = pts[i + 1] - pts[i];
            diff.push_back(d);
            pos_map[pts[i]] = i;
        }
        st.init(diff.size());
        if (!diff.empty()) st.build(diff);
    }
 
    void insert_break(int x) {
        if (breaks.count(x)) return;
 
        auto nxt = breaks.lower_bound(x);
        auto prv = nxt;
        if (prv != breaks.begin()) --prv;
        else prv = breaks.end();
 
        if (prv != breaks.end() && nxt != breaks.end()) {
            int i = pos_map[*prv];
            int old_val = diff[i];
            int new_val1 = x - *prv;
            int new_val2 = *nxt - x;
            diff[i] = new_val1;
            st.update(i, new_val1);
 
            diff.insert(diff.begin() + i + 1, new_val2);
            st.n++;
            st.update(i + 1, new_val2);
 
            map<int, int> new_map;
            for (auto &[key, val] : pos_map) {
                if (val > i) new_map[key] = val + 1;
                else new_map[key] = val;
            }
            new_map[*prv] = i;
            new_map[x] = i + 1;
            pos_map = new_map;
 
        } else if (prv != breaks.end()) {
            int i = pos_map[*prv];
            int new_val = x - *prv;
            diff.push_back(new_val);
            st.n++;
            st.update((int)diff.size() - 1, new_val);
            pos_map[*prv] = i;
            pos_map[x] = (int)diff.size() - 1;
 
        } else if (nxt != breaks.end()) {
            diff.insert(diff.begin(), *nxt - x);
            st.n++;
            st.update(0, *nxt - x);
            map<int, int> new_map;
            for (auto &[key, val] : pos_map) {
                new_map[key] = val + 1;
            }
            new_map[x] = 0;
            pos_map = new_map;
        }
 
        breaks.insert(x);
    }
 
    void erase_break(int x) {
        if (!breaks.count(x)) return;
        auto it = breaks.find(x);
        auto nxt = next(it);
        auto prv = it == breaks.begin() ? breaks.end() : prev(it);
        if (prv != breaks.end() && nxt != breaks.end()) {
            int i = pos_map[*prv];
            int merged = *nxt - *prv;
            diff[i] = merged;
            st.update(i, merged);
            diff.erase(diff.begin() + (i + 1));
            st.n--;
            pos_map.erase(x);
            map<int, int> new_map;
            for (auto &[key, val] : pos_map) {
                if (val > i + 1) new_map[key] = val - 1;
                else new_map[key] = val;
            }
            new_map[*prv] = i;
            pos_map = new_map;
 
        } else if (prv != breaks.end()) {
            int i = pos_map[x];
            diff.erase(diff.begin() + i);
            st.n--;
            pos_map.erase(x);
 
        } else if (nxt != breaks.end()) {
            diff.erase(diff.begin());
            st.n--;
            pos_map.erase(x);
            map<int, int> new_map;
            for (auto &[key, val] : pos_map) {
                if (val == 0) continue;
                new_map[key] = val - 1;
            }
            pos_map = new_map;
        }
 
        breaks.erase(x);
    }
    int count_good_k(int n) {
        if (breaks.empty()) return n;
        if (diff.empty()) {
            int d = *breaks.begin();
            return cnt[d];
        }
        int g = st.query();
        return cnt[g];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            cnt[j]++;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 2);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        GoodPartition gp;
        gp.n = n;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) gp.breaks.insert(i);
        }
 
        gp.build();
        cout << gp.count_good_k(n) << '\n';
 
        while (q--) {
            int p, v;
            cin >> p >> v;
            if (p > 1 && a[p - 1] > a[p]) gp.erase_break(p - 1);
            if (p < n && a[p] > a[p + 1]) gp.erase_break(p);
            a[p] = v;
            if (p > 1 && a[p - 1] > a[p]) gp.insert_break(p - 1);
            if (p < n && a[p] > a[p + 1]) gp.insert_break(p);
            cout << gp.count_good_k(n) << '\n';
        }
    }
 
    return 0;
}