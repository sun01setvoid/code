//dboj_gcd
//gcd从左到右非增，每次变化至少/2，因为变化因子至少为2
//所以每个区间最多有logM个,M是max(a[i]),nlognlogM
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
#define long long ll
const int N=1e5+10;
int st[N][18],a[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int rgcd(int l,int r){
    int k=(int)log2(r-l+1);
    return gcd(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
  	ios::sync_with_stdio(0);
  	cin.tie(0);cout.tie(0);
    int t,n,q;
    int x,y,res;
    int cnt=0;
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        map <int,int> mp;
        for (int i=1;i<=n;i++)  st[i][0]=a[i];
        int m=log2(n);
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n-(1<<i)+1;j++){
                int k=1<<i-1;
                st[j][i]=gcd(st[j][i-1],st[j+k][i-1]);
            }
        }
        for (int i=1;i<=n;i++){
            int j=i,ans=a[i];
            while (j<=n){
                int l=j,r=n;
                while  (l<=r){
                    int m=l+r>>1;
                    if (rgcd(j,m)>=ans) l=m+1;
                    else    r=m-1;
                }
                if (!mp.count(ans)) mp[ans]=l-j;
                else    mp[ans]+=l-j;
                j=l;
                if (j<=n)   ans=gcd(ans,a[j]);
            }
        }
        cin>>q;
        cout<<"Case #"<<++cnt<<":\n";
        while (q--){
            cin>>x>>y;
            res=rgcd(x,y);
            cout<<res<<" "<<mp[res]<<endl;
        }  
    }
}