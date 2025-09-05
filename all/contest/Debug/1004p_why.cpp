#include <bits/stdc++.h>
using namespace std;
const int B = 2000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, T;
    cin >> S >> T;
    auto brute = [&](int l, int r, int x, int y) -> bool
    {
        int p = x;
        for (int i = l; i < r; i++)
        {
            if (S[i] == T[p])
            {
                p += 1;
            }
            if (p == y)
            {
                return true;
            }
        }
        return false;
    };
    int Q;
    cin >> Q;
    while (Q--)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        --l;
        --x;
        int len1 = r - l;
        int len2 = y - x;
        int w = len1 - len2 * 2;
        if (w >= B)
        {
            cout << "YES\n";
        }
        else if (w <= -B)
        {
            cout << "NO\n";
        }
        else
        {
            cout << (brute(l, r, x, y) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}