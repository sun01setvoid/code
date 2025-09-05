#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e5;
int n;
int id[10][10][10][10];
struct node {int x, y, x_, y_;} a[N];
vector<int> g[N], h[N];
int ans[N], cnt[N];
queue<int> q;

void add(int u, int a, int b, int x_, int y_) {
	if(a > b) swap(a, b);
	int v = id[x_][y_][a][b];
	g[u].eb(v);
	h[v].eb(u);
}

int main() {
	rep(x, 0, 9) rep(y, x, 9) rep(x_, 0, 9) rep(y_, x_, 9) {
		a[++ n] = (node){x, y, x_, y_}, id[x][y][x_][y_] = n;
		if(x == 0 && y == 0) ans[n] = 1, q.push(n);
		else if(x_ == 0 && y_ == 0) ans[n] = 2, q.push(n);
	} 
	rep(x, 0, 9) rep(y, max(1, x), 9) rep(x_, 0, 9) rep(y_, max(1, x_), 9) {
		int u = id[x][y][x_][y_];
		if(x) {
			if(x_) add(u, (x + x_) % 10, y, x_, y_);
			add(u, (x + y_) % 10, y, x_, y_);
		}
		if(x_) add(u, (y + x_) % 10, x, x_, y_);
		add(u, (y + y_) % 10, x, x_, y_);
	}
	
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(ans[u] == 1) {
			for(auto v : h[u]) if(!ans[v]) {
				cnt[v] ++;
				if(cnt[v] == (int)g[v].size()) ans[v] = 2, q.push(v);
			}
		} else {
			for(auto v : h[u]) if(!ans[v]) ans[v] = 1, q.push(v);
		}
	}
	
	int T = read();
	while(T --) {
		int x = read(), y = read();
		int x_ = read(), y_ = read();
		if(x > y) swap(x, y);
		if(x_ > y_) swap(x_, y_);
		printf("%d\n", ans[id[x][y][x_][y_]]);
	}
	
	return 0;
}

//逆向迭代来做有平局态的题目