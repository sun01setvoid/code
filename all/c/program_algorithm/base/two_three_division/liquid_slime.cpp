#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1010;
int n,m,k,cnt;
char Map[N][N];
int a[N],sum[N],vis[N][N],dir[4][2]={0,-1,0,1,1,0,-1,0};
void dfs(int x,int y)
{
  int si,sj;
for (int i=0;i<4;i++){
       	si=x+dir[i][0],sj=y+dir[i][1];
        if (si<x || si>n || sj<1 || sj>m ) continue;
        if (vis[si][sj]==0 && Map[si][sj]=='.'){
         cnt++;
         vis[si][sj]=1;
         dfs(si,sj);}
}
}
bool check(int x){
	if (sum[x]<k)
  		return false;
  memset(vis,0,sizeof vis);
  	int ans=0,si,sj;
  	for (int j=1;j<=n;j++)
      	if(Map[x][j]=='.' && vis[x][j]==0){
        	vis[x][j]=1;
      		cnt=1;
    		for (int i=0;i<4;i++){
       			si=x+dir[i][0],sj=j+dir[i][1];
        		if (si<x || si>n || sj<1 || sj>m ) continue;
        		if (vis[si][sj]==0 && Map[si][sj]=='.'){
          			cnt++;
          			vis[si][sj]=1;
         			dfs(si,sj);
        		}
      	 	}
        ans=max(cnt,ans);
       	}
   if (ans<k)
       return false;
   else
       return true;
}
int main(){
int t,l,r,mid,ans;
cin>>t;
for (int i=0;i<t;i++){
  	cin>>n>>m>>k;
    ans=n+1;
    memset(sum,0,sizeof sum);
    for (int j=1;j<=n;j++){
      for (int v=1;v<=m;v++){
        	cin>>Map[j][v];
        	if (Map[j][v]=='.')
          		a[j]++;
      }
    }
    for (int j=n;j>=1;j--) sum[j]=sum[j+1]+a[j];
    	if (sum[1]<k){
      		cout<<"-1"<<endl;
      		continue;}
    l=1,r=n;
    while (l<=r){
      	mid=(l+r)/2;
        if (check(mid))
          	ans=mid,r=mid-1;
        else
          	l=mid+1;
      	}
     if (ans!=n+1)
      	 cout<<ans<<endl;
     else
       	 cout<<"-1"<<endl;
    }
  }