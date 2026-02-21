#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;
int h[N], cnt;
void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}
void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        swap(h[u], h[u / 2]);
        u >>= 1;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]); //O(n)建堆，sum(层节点*据底层的层数)=O((n+1)/2)
    cnt = n;
    for (int i = n / 2; i; i -- ) down(i);//把上面的down 一下就好
    while (m -- )
    {
        printf("%d ", h[1]);
        h[1] = h[cnt -- ];
        down(1);
    }
    puts("");
    return 0;
}
//删中间的话，先up(k)再down(k)