#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N =5e5, M = 2e6;
typedef pair<int, int> PII;
int h[N], e[M], w[M], ne[M], idx;
int st[N], dist[N];
int n, m, x;
const int INF = 0x3f3f3f3f3f3f3f3f;
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void bfs() {
    for (int i = 2; i <= 2 * n + 1; i++) dist[i] = INF;
    for (int i = 2; i <= 2 * n + 1; i++) st[i] = 0;
    dist[2] = 0;
    queue<int> q;
    q.push(2);
    st[2] = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        st[u] = 0;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                if (!st[v]) {
                    q.push(v);
                    st[v] = 1;
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> x;
        idx = 0;
        for (int i=2;i<=2*n+1;i++) h[i]=-1;
        vector <int> s1;
        int sum1=0,sum2=0;
        for (int i = 1; i <= x; i++){
            int tmp;
            cin >> tmp;
            if (tmp&1) {
                s1.push_back(tmp);
                sum1+=tmp;
            } else {
                sum2+=tmp;
            }
        }
        sort(s1.begin(),s1.end(),greater<int>());
        int a=sum1,b=sum2;
        if (s1.size()&1){
            sum1+=b;
            sum2+=a-s1.back();
        }
        else{
            if (s1.size() > 1) {
                sum1 += b - s1.back();
            }
            sum2+=a;
        }
        while (m--) {
            int u, v, c;
            c=1;
            cin >> u >> v;
            add(2 * u, 2 * v + 1, c);
            add(2 * u + 1, 2 * v, c);
            add(2 * v, 2 * u + 1, c);
            add(2 * v + 1, 2 * u, c);
        }
        bfs();
        for (int i = 1; i <= n; i++) {
            if (dist[2*i]<=sum2 ||  dist[2*i+1]<=sum1) cout <<"1";
            else cout << "0";
        }
        cout<<endl;
    }
}