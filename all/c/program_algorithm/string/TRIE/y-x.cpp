#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e3 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int son[2];
    int cnt;
    int tag;
    oo(){son[0]=son[1]=0;cnt=0;tag=0;}
}t[maxn*10];
int tot=0,n,a[maxn];
void insert(int val)
{
    int now=0;
    for(int i=0;i<=62;i++)
    {
        int target=((val>>i)&1);
        if(!t[now].son[target])t[++tot]=oo(),t[now].son[target]=tot;
        now=t[now].son[target];t[now].cnt++;
    }
}
int C(int a,int b)
{
    if(a<b)return 0;int ans=1;
    for(int i=a;i>=a-b+1;i--)ans*=i;
    for(int i=1;i<=b;i++)ans/=i;
    return ans;
}
int erase(int val,int ct)
{
    int now=0;int sum=0;
    for(int i=0;i<=62;i++)
    {
        int me=((val>>i)&1);
        now=t[now].son[me];t[now].cnt-=ct;
        sum+=t[now].tag*C(ct,2);
    }
    return sum;
}
int query(int val,int cnt)
{
    int now=0,sum=0;
    for(int i=0;i<=62;i++)
    {
        int me=((val>>i)&1);
        int you=me^1;
        if(i%2==0)
        {
            sum+=t[t[now].son[you]].cnt;
            t[t[now].son[you]].tag+=cnt;
        }
        now=t[now].son[me];
    }
    return sum;
}

void Raze()
{
    cin>>n;t[0]=oo();map<int,int>mp;
    int ans=C(n,3);tot=0;
    for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]++;
    for(int i=1;i<=n;i++)insert(a[i]);
    for(auto it :mp)
    {
        int val=it.fi,cnt=it.so;
        int sum=query(val,cnt);
        int res =C(cnt,2)*sum+C(cnt,3);
        res+=erase(val,cnt);
        ans-=res;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}