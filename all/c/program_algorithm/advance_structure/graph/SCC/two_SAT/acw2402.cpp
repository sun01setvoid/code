// 点2*i假(这一条件),2*i+1真,有scanf那里得出，这样设方便点，当然也可以交换
// 2为一个块
// 或者前cnt假后cnt真，差真假cnt步
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2e6 + 10, M = N;
int h[N], ne[M], e[M], idx;
int stk[N], top = -1;
bool in_stk[N];
int dfn[N], low[N], ts;
int id[N], scc_cnt;
int n, m;
void add(int a, int b)
{
	cout << a << " " << b << endl;
	e[idx] = b;
	ne[idx] = h[a], h[a] = idx++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++ts;
	stk[++top] = u, in_stk[u] = true;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
			tarjan(j), low[u] = min(low[u], low[j]);
		else if (in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}
	if (low[u] == dfn[u])
	{
		++scc_cnt;
		int y;
		do
		{
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
		} while (y != u);
	}
}
int main()
{
	int i, j, a, b;
	memset(h, -1, sizeof h);
	scanf("%d %d", &n, &m);
	while (m--)
	{
		scanf("%d %d %d %d", &i, &a, &j, &b);
		i--, j--; // 因为从0开始
		add(2 * i + !a, 2 * j + b);
		add(2 * j + !b, 2 * i + a);
	}
	for (int i = 0; i < 2 * n; i++)
	{
		if (!dfn[i])
			tarjan(i); // 不一定从最高点开始tarjan
	}
	for (int i = 0; i < n; i++)
	{
		if (id[2 * i] == id[2 * i + 1])
		{
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	puts("POSSIBLE");
	for (int i = 0; i < n; i++) // trick
	{							// 我们一定取更靠后的那一个 ,id前的靠后
		cout << id[2 * i] << " " << id[2 * i + 1] << endl;
		if (id[2 * i] > id[2 * i + 1])
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
}
/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;
const int maxn = 3005;
struct edge{
	int to;
	int next;
}e[maxn*maxn];
int head[maxn];
int dfn[maxn];
int low[maxn];
int scc[maxn];
stack<int>s;
int tot,cnt,res;
void clear_set()
{
	tot = cnt = res = 0;
	memset(head,-1,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(scc,0,sizeof(scc));
	while(!s.empty())	s.pop();
}
void addedge(int x,int y)
{
	e[tot].to = y;
	e[tot].next = head[x];
	head[x] = tot++;
}
void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	s.push(x);
	for(int i = head[x];~i;i = e[i].next){
		int y = e[i].to;
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
		}
		else if(!scc[y]){
			low[x] = min(low[x],dfn[y]);
		}
	}
	if(low[x] == dfn[x]){
		res++;
		while(true){
			int t = s.top();
			s.pop();
			scc[t] = res;
			if(t == x)		break;
		}
	}
}
int main()
{
	int n,m;
	while(~scanf("%d",&n)){
		scanf("%d",&m);
		clear_set();
		for(int i = 0;i < m;i++){
			int a,b,x,y;
			scanf("%d%d%d%d",&a,&b,&x,&y);
			a = 2*a + x;	b = 2*b + y;
			addedge(a,b^1); addedge(b,a^1);
		//	ax by有矛盾
		}
		for(int i = 0;i < 2*n;i++){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		bool f = true;
		for(int i = 0;i < n;i++){
			if(scc[i*2] == scc[i*2+1]){
				f = false;
				break;
			}
		}
		if(f){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}

*/