#include <bits/stdc++.h>
typedef long long ll;
struct Basis
{
    static const int K = 60;
    ll a[K];
    Basis() { memset(a, 0, sizeof a); }
    bool ins(ll x)
    {
        for (int i = K - 1; ~i; --i)
            if (x >> i & 1)
            {
                if (!a[i])
                {
                    a[i] = x;
                    return true;
                }
                x ^= a[i];
            }
        return false;
    }
    ll max_val(ll x = 0)
    {
        for (int i = K - 1; ~i; --i)
            if ((x ^ a[i]) > x)
                x ^= a[i];
        return x;
    }
} B;