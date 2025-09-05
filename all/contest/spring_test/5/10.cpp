#include <iostream>
#include <vector>
using namespace std;
const int N = 5e5 + 10;
typedef long long LL;
typedef long long ll;
LL qp(LL a,LL k){
    LL res=1;
    while (k){
        if (k&1)    res=res*a;
        a=a*a;
        k/=2;
    }
    return res;
}
struct node
{
    int v;
    int d;
};
vector<node> G[N];
int cnt1 = 0, cnt2 = 0;
void dfs(int u, int fa, int dis)
{
    if (dis == 0)
        cnt1++;
    else
        cnt2++;
    for (auto i : G[u])
    {
        if (i.v == fa)
            continue;
        dfs(i.v, u, (dis + i.d) % 2);
    }
}
int main()
{
    int t;
    int n, a, b, c;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while (t--)
    {
        cnt1 = cnt2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            G[i].clear();
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> a >> b >> c;
            G[a].push_back({b, c % 2});
            G[b].push_back({a, c % 2});
        }
        dfs(1, 1, 0);
        LL ans = qp(cnt1,3)+qp(cnt2,3) ;
        cout<<ans<<endl;
    }
}