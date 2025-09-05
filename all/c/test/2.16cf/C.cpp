//一个往前走，一个往后走，求和->前缀和与后缀和
//且自写代码不对，因为从这里开始+,若正，则无法回头到更左，若负则无法回头到更右
//所以是前缀+后缀
//无法回头只能算->i<-
#include <iostream>
using namespace std;
typedef long long ll;
struct Node{
    ll val;
    int id;
};
Node zhen[200010];
Node fu[200010];
int re[200010];
int main(){
    int t;
    int n;
    ll temp;
    cin>>t;
    while (t--){
        cin>>n;
        bool f=1;
        for (int i=1;i<=n;i++)  zhen[i].val=0,fu[i].val=0,zhen[i].id=0,fu[i].id=0,re[i]=0;
        int cnt[2]={1,1};
        int num=0;
        cin>>temp;
        if (temp<0) f=1,fu[cnt[1]].val+=abs(temp),fu[cnt[1]].id=++num,re[num]=cnt[1],cnt[0]=0;
        else    f=0,zhen[cnt[0]].val+=temp,zhen[cnt[0]].id=++num,re[num]=cnt[0],cnt[1]=0;
        for (int i=2;i<=n;i++){
            cin>>temp;
            if (temp<0){
                if (f==0)   cnt[1]++,f=1,++num,fu[cnt[1]].id=num,re[num]=cnt[1];               
                fu[cnt[1]].val+=abs(temp);
            }
            else if (temp>0){
                if (f==1)   cnt[0]++,f=0,++num,zhen[cnt[0]].id=num,re[num]=cnt[0];               
                zhen[cnt[0]].val+=abs(temp);
            }
        }
        for (int i=1;i<=cnt[0];i++) zhen[i].val=zhen[i-1].val+zhen[i].val;
        for (int i=1;i<=cnt[1];i++) fu[i].val=fu[i-1].val+fu[i].val;
        ll ma=0;
        int a=-1,b=-1;
        int c=-1,d=-1;
        for (int i=cnt[1];i>=1;i--){
            if (fu[i].id>zhen[1].id)  {a=i;break;}
        }
        if (a!=-1)  {
            for (int i=cnt[0];i>=1;i--){
                if  (zhen[i].id < a)    {b=zhen[i].id;break;}
            }
        }
        for (int i=1;i<=cnt[0];i++){
            if (zhen[i].id<fu[cnt[1]].id)  {c=i;break;}
        }
        if (c!=-1)  {
            for (int i=1;i<=cnt[1];i++){
                if  (fu[i].id > c)    {d=fu[i].id;break;}
            }
        }
        if (zhen[cnt[0]].val>ma)    ma=zhen[cnt[0]].val;
        if (fu[cnt[1]].val>ma)  ma=fu[cnt[1]].val;
        if (a!=-1 && zhen[re[b]].val+fu[re[a]].val>ma)   ma=zhen[re[b]].val+fu[re[a]].val;
        if (c!=-1 && zhen[cnt[0]].val-zhen[re[c]-1].val+fu[cnt[1]].val-fu[re[d]-1].val>ma) ma=zhen[cnt[0]].val-zhen[re[c]-1].val+fu[cnt[1]].val-fu[re[d]-1].val;
        cout<<ma<<endl;
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<ll> pre(n), suf(n);
    if (a[0] > 0)
        pre[0] = a[0];

    for (int i = 1; i < n; i++){
        pre[i] = pre[i - 1];
        if (a[i] > 0)
            pre[i] += a[i];
    }

    if (a[n - 1] < 0)
        suf[n - 1] = -a[n - 1];
    
    for (int i = n - 2; i >= 0; i--){
        suf[i] = suf[i + 1];
        if (a[i] < 0)
            suf[i] -= a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, pre[i] + suf[i]);
    
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
*/