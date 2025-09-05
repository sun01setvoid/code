//hdu 4027
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll sum[N<<2],n,m,k,l,r;
inline ll read()
{
	char c;ll res=0,flag=1;
	for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
	for(;isdigit(c);c=getchar())res=res*10+c-'0';
	return res*flag;
}
void build(int i,int l,int r)
{
	if(l==r)
	{
		sum[i]=read();
		return;
	}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	sum[i]=sum[i<<1]+sum[i<<1|1];
}

void modify(int i,int l,int r,int x,int y)
{
	if(sum[i]<=r-l+1)
		return;
	if(l==r)
	{
		sum[i]=sqrt(sum[i]);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) modify(i<<1,l,mid,x,y);
	if(y>mid)  modify(i<<1|1,mid+1,r,x,y);
	sum[i]=sum[i<<1]+sum[i<<1|1];
}

ll query(int i,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return sum[i];
	int mid=l+r>>1;
	ll ans=0;
	if(x<=mid) ans+=query(i<<1,l,mid,x,y);
	if(y>mid)  ans+=query(i<<1|1,mid+1,r,x,y);
	return ans;
}
int cnt;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d:\n",++cnt);
		build(1,1,n);
		m=read();
		while(m--)
		{
			k=read();
			l=read(),r=read();
			if(l>r)l^=r^=l^=r;
			if(!k) modify(1,1,n,l,r);
			else printf("%lld\n",query(1,1,n,l,r));
		}
		putchar('\n');
		memset(sum,0,sizeof sum);
	}
	return 0;
}