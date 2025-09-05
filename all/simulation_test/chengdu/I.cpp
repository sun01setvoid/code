#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,q;
int cnt[N];
bool check(int mid,vector <int> &a){
    for (int i=0;i<(n+mid-1)/mid;i++){
        for (int j=0;j<mid-1 && i*mid+j+1<n;j++){
            if (a[i*mid+j]>a[i*mid+j+1]) return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n>>q;
    vector <int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    int l=1,r=n;
    int k;
    while (l<=r){
        int mid=(l+r)>>1;
        if (check(mid,a)){
            l=mid+1;
            k=mid;
        }
        else r=mid-1;
    }
    cout<<cnt[k]<<endl;
    while (q--){
        int pos,val;
        cin>>pos>>val;
        --pos;
        int d=pos%k,ran=pos/k;
        if (val<a[pos]){
            a[pos]=val;
            if (d!=0 && pos!=0 && a[pos]<a[pos-1]){
                if (k%d==0) k=d;
                else k=1; 
            }else if ( pos==k-1 && pos+1<n && a[pos]<a[pos+1]){
                l=k,r=n;
                while (l<=r){
                    int mid=(l+r)>>1;
                    if (check(mid,a)){
                    l=mid+1;
                    k=mid;
                    }
                    else r=mid-1;
                }
            }
        }else if (val>a[pos]){
            a[pos]=val;
            if  (k!=1 && pos!=k-1 && pos!=n-1 && a[pos]>a[pos+1]){
                if (k%(d+1)) k=d;
                else k=1;
            }else if (pos==k && pos-1>=0 && a[pos]>a[pos-1]){

                l=k,r=n;
                while (l<=r){
                    int mid=(l+r)>>1;
                    if (check(mid,a)){
                        l=mid+1;
                        k=mid;
                    }
                    else r=mid-1;
                }
                cout<<k<<endl;
            }
        }else a[pos]=val;
        cout<<cnt[k]<<endl;
    }
}
int yinzi(int x){
    int ans=0;
    for (int i=1;i*i<=x;i++){
        if (x%i==0) {
            ans++;
            if (x/i!=i) ans++;
        }
    }
    return ans;
}
signed main(){
    int t;
    cin>>t;
    for (int i=1;i<=N;i++){
        cnt[i]=yinzi(i);
    }
    while (t--){
        solve();
    }
}