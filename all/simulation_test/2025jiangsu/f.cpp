#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
const int maxm = 1e1 + 5;
int n, a, b;
int s;
struct oo
{
	int t;
	string p;
	string v;
};
bool cmp(oo& a, oo& b) { return a.t < b.t; }
void solve()
{
	cin >> n >> a >> b;cin >> s;
	map<string, int>cnt, ok;
	map<string, int>tmp;
	int now = 0, ct = 0;
	vector <oo>temp;
	vector<int>may;
	for (int i = 1; i <= s; i++)
	{
		int t; string p, v;
		cin >> t >> p >> v;
		temp.push_back({ t,p,v });
	}
	for (int i = 0; i < temp.size(); i++)
	{
		int t = temp[i].t;
		string p = temp[i].p, v = temp[i].v;
		if (ok[p])continue;
		if (v == "ac")
		{
			ok[p] = 1; now += t + cnt[p] * 20; ct++;
		}
		else if (v == "rj")
		{
			cnt[p]++;
		}
		else
		{
			if (tmp.find(p) == tmp.end())tmp[p] = t + cnt[p] * 20;
		}
	}
	if (ct > a || (ct == a && now < b)) { cout << "0" << endl; return; }
	for (auto it : tmp)may.push_back(it.second);
	sort(may.begin(), may.end());
	for (int i = 0; i < may.size(); i++)
	{
		now += may[i]; ct++;
		if (ct > a || (ct == a && now < b))
		{
			cout << i + 1 << endl; return;
		}
	}
	cout << "-1" << endl;
}
signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); int _ = 1;
	cin >> _;
	while (_--)solve(); return 0;
}