#include <iostream>
using namespace std;
const int N=2e5+10;
typedef long long LL;
LL  a[N],b[N],absa[N];
struct node {
    LL v;
    int id;
}stk[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t,n;
    LL x;
    cin>>t;
    while (t--){
        cin>>n;
        cin>>x;
        LL ma=0,sum=0;
        for (int i=1;i<=n;i++)  cin>>a[i],ma=max(ma,a[i]);
        a[n+1]=a[0]=ma;
        absa[1]=absa[0]=0;
        for (int i=2;i<=n;i++)  absa[i]=abs(a[i]-a[i-1]),sum+=absa[i],absa[i]+=absa[i-1]; 
        LL num=sum-x+2*ma;
        int top=-1;
        stk[++top]={absa[0]-a[0],0};
        node tmp={absa[1]-a[1],1};
        if (sum<=x) {cout<<0<<endl;continue;}
        int ans=n+1;
        for (int i=2;i<=n+1;i++){
            int k=top;
            while (absa[i]+a[i]-stk[k].v<num)  k--;
            if (k!=-1 && absa[i]+a[i]-stk[k].v>=num) ans=min(i-1-stk[top].id,ans);
            while (top!=-1 && tmp.v<=stk[top].v)  top--;
            stk[++top]={tmp.v,tmp.id};
            tmp={absa[i]-a[i],i};
        }
        cout<<ans<<endl;
    }
}