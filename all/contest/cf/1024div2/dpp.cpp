#include <bits/stdc++.h>
using namespace std;
int lowbit(int x)
{
    return x & (-x);
}
void update(int i, vector<int> &tr, int n)
{
    i++;
    for (; i <= n; i += lowbit(i))
    {
        tr[i]++;
    }
}
int query(int i, vector<int> &tr)
{
    int res = 0;
    i++;
    for (; i > 0; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}
int check(vector<int> a)
{
    int n = a.size();
    auto b = a;
    sort(b.begin(), b.end());
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
        mp[b[i]] = i;
    vector<int> tr(n + 1);
    int f = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int x = mp[a[i]];
        f ^= query(x - 1, tr) % 2;
        update(x, tr, n);
    }
    return f;
}

vector<int> build(vector<int> &even, vector<int> &odd)
{
    int n = even.size() + odd.size();
    vector<int> res(n);
    for (int i = 0, j = 0, k = 0; i < n; ++i)
        res[i] = (i % 2 == 0) ? even[j++] : odd[k++];
    return res;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), even, odd;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i % 2 == 0)
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);
        }
        vector<int> s1 = even, s2 = odd;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int f1 = check(even), f2 = check(odd);
        vector<int> ans;
        if (f1 == f2)
        {
            ans = build(s1, s2);
        }
        else
        {
            auto v1 = s1, v2 = s2;
            if (v1.size() >= 2)
                swap(v1[v1.size() - 1], v1[v1.size() - 2]);
            if (v2.size() >= 2)
                swap(v2[v2.size() - 1], v2[v2.size() - 2]);
            ans = min(build(v1, s2), build(s1, v2));
        }
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
//奇数位置换位交换两次保证偶位置不变原来不变