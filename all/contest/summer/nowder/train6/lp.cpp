#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;

const int mod = 1e9 + 7;

using namespace std;

struct dt
{
    ll l, r;
    bool operator<(dt &oth)
    {
        if (l != oth.l)
            return l > oth.l;
        return r > oth.r;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<dt> a(m);
        vector<char> ans(2 * n + 1, ')');
        for (int i = 0; i < m; i++)
            cin >> a[i].l >> a[i].r;
        sort(a.begin(), a.end());
        ll cnt = 0;
        ll lst = 1e9;
        for (int i = 0; i < m; i++)
        {
            //cout << lst << " " << a[i].r << endl;
            if (lst > a[i].r)
            {
                ans[a[i].l] = '(';
                lst = a[i].l;
                cnt++;
                if (cnt > n)
                    break;
            }
        }
        if (cnt > n)
            cout << -1 << endl;
        else
        {
            //int p = 1;
            int cntz = 0, cnty = 0;
            for (int p=1;p<=2*n;p++)
            {
                if (ans[p] != '(' && cnt < n)
                {
                    ans[p] = '(';
                    cnt++;
                }
                if (ans[p] == '(')
                    cntz++;
                else
                    cnty++;
                //cout << p << " " << cntz << " " << cnty << endl;
                if (cnty > cntz)
                {
                    //cout <<1111 << endl;
                    break;
                }
            }
            if (cnty > cntz)
            {
                cout << -1 << endl;
                continue;
            }
            for (int i=1;i<=2*n;i++)
                cout << ans[i];
            cout << endl;
        }
    }
}
