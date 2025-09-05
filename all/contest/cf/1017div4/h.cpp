// 记录个数，记录全部索引位置
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, vector<int>> pos;
        map<int, int> cnt;
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pos[a[i]].push_back(i);
            cnt[a[i]] = 0;
        }
        vector<tuple<int, int, int, int>> qr(q);
        vector<int> res(q + 1);
        int c = 0;
        for (auto &[l, r, v, i] : qr)
        {
            cin >> v >> l >> r;
            i = ++c;
        }
        sort(qr.begin(), qr.end());
        int prel = 1;
        for (auto &[l, r, v, idd] : qr)
        {
            for (int j = prel; j < l; j++)
            {
                cnt[a[j]]++;
            }
            prel=l;
            vector<PII> facts;
            for (int i = 1; i * i <= v; i++)
            {
                if (v % i)
                    continue;
                int fact1 = v / i, fact2 = i;
                if (!(pos[fact1].size() == 0 || cnt[fact1] >= pos[fact1].size() || pos[fact1][cnt[fact1]] > r || fact1 == 1))
                    facts.push_back({pos[fact1][cnt[fact1]], fact1});
                if (fact1 == fact2)
                    continue;
                if (!(pos[fact2].size() == 0 || cnt[fact2] >= pos[fact2].size() || pos[fact2][cnt[fact2]] > r || fact2 == 1))
                    facts.push_back({pos[fact2][cnt[fact2]], fact2});
            }
            sort(facts.begin(), facts.end());
            int pl = l;
            int ans = 0;
            for (auto &it : facts)
            {
                int pr = it.first;
                if (v % it.second)
                    continue;
                else
                    ans += (pr - pl) * v;
                while (v % it.second == 0)
                {
                    v /= it.second;
                }
                pl = pr;
            }
            if (facts.empty())
                ans += (r - l + 1) * v;
            else
                ans += (r - pl + 1) * v;
            res[idd] = ans;
        }
        for (int i = 1; i <= q; i++)
            cout << res[i] << endl;
    }
}