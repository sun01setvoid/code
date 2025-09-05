#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
#define pa pair<int,int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr<<#x<<'='<<(x)<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
//再不卷就退役了
const int z=5e4+10;
const int zz=5e4;
const int B=1ll<<7;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
void solve(){
    cout<<"10000 10000\n";
    for(int i=1;i<=10000;i++){
        int x=rand()%10000,y=rand()%10000,w=rand()%10000;
        cout<<x<<" "<<y<<" "<<w<<" ";
    }
}
signed main(){
    IOS;
    srand(0);
    int t=1;
    cin>>t;
    cout<<t<<endl;
    while(t--)solve();
}