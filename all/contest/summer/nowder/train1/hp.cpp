#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int S = 65536;
int n, q, L[S], R[S], Cnt[S];
ull Val[maxn];
bool Flag[maxn];
//-----------------------------------------------------//
inline ull BitBetween(int l, int r)
{
    ull ret = r == 63 ? -1uLL : (1uLL << (r + 1)) - 1;
    ret ^= (1uLL << l) - 1;
    return ret;
}
inline void Update(int val, ull &ret, int &ri)
{
    ret += ri * L[val] + Cnt[val];
    ri = R[val] + (L[val] >> 4) * ri;
}
struct Bitset
{
    int sz, ptr;
    vector<ull> vec;
    Bitset() : Bitset(0) {}
    Bitset(int _sz)
    {
        sz = _sz;
        ptr = 0;
        vec.resize((_sz + 63) >> 6);
    }
    void Add(int cnt, ull val)
    {
        if (cnt <= 64 - (ptr & 63))
        {
            vec[ptr >> 6] |= (val << (ptr & 63));
        }
        else
        {
            ull mask = BitBetween(0, 64 - (ptr & 63) - 1);
            vec[ptr >> 6] |= (val & mask) << (ptr & 63);
            vec[(ptr >> 6) + 1] = val >> (64 - (ptr & 63));
        }
        ptr += cnt;
    }
    void GetSame(const Bitset &rhs)
    {
        // while (sz != ptr || rhs.sz != rhs.ptr) ; //没存储完就死循环
        for (int i = 0; i < vec.size(); i++)
            vec[i] ^= ~rhs.vec[i];
        int mn_sz = min(sz, rhs.sz);                  // 两边相同时，其实没必要
        for (int i = mn_sz >> 6; i < vec.size(); i++) // 有未使用的空间，因为空间向上取整
        {
            int l_bit = max(0ll, mn_sz - (i << 6));
            int r_bit = 63;
            vec[i] &= ~BitBetween(l_bit, r_bit);
        }
    }
    ull Calc() const
    {
        ull ret = 0;
        for (int i = 0, ri = 0; i < vec.size(); i++)
        {
            Update(vec[i] & (S - 1), ret, ri);
            Update(vec[i] >> 16 & (S - 1), ret, ri);
            Update(vec[i] >> 32 & (S - 1), ret, ri);
            Update(vec[i] >> 48 & (S - 1), ret, ri);
        }
        return ret;
    }
};
Bitset GetBitset(int l, int r) // 获得[l, r]的Bitset   //一块一块处理
{
    Bitset ret(r - l + 1);
    if ((l >> 6) == (r >> 6))
    {
        ull val = (Val[l >> 6] & BitBetween(l & 63, r & 63)) >> (l & 63);
        ret.Add(r - l + 1, val);
    }
    else
    {
        ull val = (Val[l >> 6] & BitBetween(l & 63, 63)) >> (l & 63);
        ret.Add(63 - (l & 63) + 1, val);
        for (int i = (l >> 6) + 1; i < (r >> 6); i++)
            ret.Add(64, Val[i]);
        val = Val[r >> 6] & BitBetween(0, r & 63);
        ret.Add((r & 63) + 1, val);
    }
    return ret;
}
void solve()
{
    string s;
    cin >> n >> q;
    cin >> s;
    for (int x = 0; x < S; x++)
    {
        for (int i = 0; i < 16; i++)
        {
            if ((x >> i) & 1)
                L[x]++;
            else
                break;
        }
        for (int i = 0; i < 16; i++)
        {
            if ((x >> (15 - i)) & 1)
                R[x]++;
            else
                break;
        }
        for (int i = 0, j = 0; i < 16; i++)
        {
            j = ((x >> i) & 1) ? j + 1 : 0;
            Cnt[x] += j;
        }
    }
    for (int i = 0; i < n; i += 64)
    {
        ull val = 0;
        for (int j = 0; j < 64 && i + j < n; j++)
            val |= ull(s[i + j] - '0') << j;
        Val[i >> 6] = val;
    }
    while (q--)
    {
        int op, l, r, a, b;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r;
            l--, r--;
            if ((l >> 6) == (r >> 6))
                Val[l >> 6] ^= BitBetween(l & 63, r & 63);
            else
            {
                Val[l >> 6] ^= BitBetween(l & 63, 63);
                Val[r >> 6] ^= BitBetween(0, r & 63);
                Flag[(l >> 6) + 1] ^= 1;
                Flag[r >> 6] ^= 1;
            }
        }
        else
        {
            for (int i = 0, pre = 0; i < n; i += 64)
            {
                Flag[i >> 6] ^= pre;
                pre = Flag[i >> 6];
                if (Flag[i >> 6])
                {
                    Val[i >> 6] ^= BitBetween(0, 63);
                    Flag[i >> 6] = false;
                }
            }
            cin >> l >> a >> b;
            a--, b--;
            Bitset u = GetBitset(a, a + l - 1), v = GetBitset(b, b + l - 1);
            u.GetSame(v);
            ull ans = u.Calc();
            cout << ans << endl;
        }
    }
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}