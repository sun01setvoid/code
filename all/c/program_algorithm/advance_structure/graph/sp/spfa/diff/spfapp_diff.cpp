//spfa
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
const int N = 1e6 + 10;//点数和边数都小于这个
int n, idx, h[N], dist[N], tim[N];
bool vis[N];
struct Node { int to, next, w; }edge[N];//链式前向星
int spfa(int s) {
    int cur;
    memset(vis, 0, sizeof vis);
    memset(dist, 0x3f, sizeof dist);
    memset(tim, 0, sizeof tim);
    queue <int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        vis[cur] = 0;
        for (int i = h[cur];i != -1;i = edge[i].next) {
            int j = edge[i].to;
            if (dist[j] > dist[cur] + edge[i].w) {
                dist[j] = dist[cur] + edge[i].w;
                tim[j] = tim[cur] + 1;
                if (tim[j] > n)
                    return -1;
                if (!vis[j]) {
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
  if (dist[n]>1e8)   return -2;
  return dist[n];
}
void init() {
    memset(h, -1, sizeof h);
    idx = 0;//0或1没啥关系，因为只是存储
}//初始化
void add(int a, int b, int c) {
    edge[idx].to = b;edge[idx].w = c;edge[idx].next = h[a];h[a] = idx++;
}//填充链式前向星
int main() {
    int a, b, c, t, x, y;
    cin >> t;
        for (int j = 0;j < t;j++) {
        init();
        cin >> n >> x >> y;
        for (int i = 0;i < x;i++) {
            cin >> a >> b >> c;
            add(a, b, c);
        }
        for (int i = 0; i < y;i++) {
            cin >> a >> b >> c;
            add(b, a, -c);
        }
        for (int i = 1;i < n;i++) add(i + 1, i, 0);//可以排在一起
        for (int i = 1;i <= n;i++) add(0, i, 0);
        int flag = spfa(0);
     if (flag == -1)  cout << flag << endl;
     else
     {
       spfa(1);
       if (dist[n] >1e8)   cout << "-2" << endl;
       else cout << dist[n] << endl;
     }
     }
}