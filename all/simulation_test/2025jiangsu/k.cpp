#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i,st,en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a,st,en)             \
    cerr << #a << "=[";             \
    repn(i, st, en) cerr << a[i] << ' '; \
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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
	string s1;
	cin>>s1;
	int n=s1.size();
	string s2;
	s2.pb('$');
	for (int i=0;i<n;i++){
		s2.pb('#');s2.pb(s1[i]);
	}
	s2.pb('#');s2.pb('&');
	int r=0,mid;
	n=s2.size();
	vii p(n,0);
	for (int i=1;i<n-1;i++){
		if (i<r) p[i]=min(r-i,p[2*mid-i]);
		while (s2[i-p[i]-1]==s2[i+p[i]+1]){
			p[i]++;
		}
		if (i+p[i]>r) r=i+p[i],mid=i;
	}
	vii len,vis(n+1,0),res(n+2,LLONG_MAX);
	for (int i = 1; i < n; i++)
    {
        if (s1[i] == s1[0]) res[i+1] = 1;
        else break;
    }
	for (int i=2;i<n-1;i+=2){
		len.pb(p[i]/2); //只找奇数串
	}
	n=s1.size();
	for (int i=0;i<n;i++){
		int id=i+1,rr=id+len[i];
		if (vis[i]) continue;
		if (i-len[i]!=0) res[rr]=min(id,res[rr]);
		else{
            while(1){
                if(rr-1<n&& len[rr-1]){
                    vis[rr-1]=1;
                    if(rr-1-len[rr-1]!=0){
                        rr+=len[rr-1];
                        break;
                    }
                    rr+=len[rr-1];
                }else break;
            }
		}
        res[rr]=min(res[rr],id); 
	}
	//vdebug(res);
	int ans=0;
	for (int i=n;i>=1;i--){
		res[i]=min(res[i],res[i+1]);
		ans^=i*res[i];
	}
	cout<<ans<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}