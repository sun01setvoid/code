
#include <bits/stdc++.h>
using namespace std;
int check(vector<int> a) {
    int n = a.size();
    auto b = a;
    map<int, int> mp;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i)
        mp[b[i]] = i;
    vector<int> bit(n + 1, 0);
    int f = 0;
    auto update = [&](int i) {
        for (++i; i <= n; i += i & -i)
            bit[i]++;
    };
    auto q = [&](int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    };
    for (int i = n - 1; i >= 0; --i) {
        int x = mp[a[i]];
        f ^= q(x - 1) % 2;
        update(x);
    }
    return f;
}

vector<int> build(vector<int> even, vector<int> odd) {
    int n = even.size() + odd.size();
    vector<int> res(n);
    int ei = 0, oi = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
            res[i] = even[ei++];
        else
            res[i] = odd[oi++];
    }
    return res;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), even, odd;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i % 2 == 0)
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);
        }
        vector<int> s1 = even, s2 = odd;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int f1 = check(even);
        int f2 = check(odd);
        vector<int> res;
        if (f1 == f2) {
            res = build(s1, s2);
        } else {
            vector<int> v1 = s1, v2 = s2;
            if (v1.size() >= 2)
                swap(v1[v1.size() - 1], v1[v1.size() - 2]);
            if (v2.size() >= 2)
                swap(v2[v2.size() - 1], v2[v2.size() - 2]);
            vector<int> c1 = build(v1, s2);
            vector<int> c2 = build(s1, v2);
            res = min(c1, c2);
        }
        for (int x : res)
            cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}