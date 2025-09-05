#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[100000];
int t,n,k,l,r,mid,ans;
int check(int x)
{
  vector<int> v[x];
	int cnt=0,res;
	for(int i=0;i<n;++i)
	{
		cnt%=x;
		if(v[cnt].empty()||a[i]>=2*v[cnt].back())
		{
			v[cnt].push_back(a[i]);
			cnt++;
		}
	}
for(int i=0;i<x;++i) if(v[i].size()<k) return false;
	return true;
}
int main()
{
  cin>>t;
  for(int i=0;i<t;i++)
  {
  cin>>n>>k;
    for (int j=0;j<n;j++)
      cin>>a[j];
    sort(a,a+n);
    if (!check(1))//注意0座塔的情况，0不能为被模数
      cout<<'0'<<endl;
   else
   {l=1,r=n/k;
    while (l<=r)
    {
    mid=(l+r)/2;
      if (check(mid)) ans=mid,l=mid+1;
      else r=mid-1;
    }
    cout<<ans<<endl;
   }
  }
}