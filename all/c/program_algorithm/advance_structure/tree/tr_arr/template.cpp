// int tr[maxn];
// int lowbit(int x) { return x & -x; }
// void add(int x, int val)
// {
//     for (int i = x; i <= n; i += lowbit(i))
//         tr[i] += val;
// }
// int q(int x)
// {
//     int ans = 0;
//     for (int i = x; i >= 1; i -= lowbit(i))
//         ans += tr[i];
//     return ans;
// }