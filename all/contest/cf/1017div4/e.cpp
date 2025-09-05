// 异或运算的话对单独每一位考虑，或许会好很多,因为没有进位
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
        vector<int> cnt(30, 0);
        for (int i = 0; i < 30; i++)
        {
            int cnt1 = 0;
            for (int j = 0; j < n; j++)
            {
                if ((a[j] >> i & 1) == 1)
                    cnt1++;
            }
            cnt[i] = cnt1;
        }
        int ma = 0;
        for (int j = 0; j < n; j++)
        {
            int ans = 0;
            for (int i = 0; i < 30; i++)
            {
                if (a[j] >> i & 1)
                    ans += (1 << i) * (n - cnt[i]);
                else
                    ans += (1 << i) * cnt[i];
            }
            ma = max(ma, ans);
        }
        cout << ma << endl;
    }
}