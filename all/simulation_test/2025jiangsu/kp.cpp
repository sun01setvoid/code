#include<bits/stdc++.h>
using namespace std;
#define int long long
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
void solve(){
    int ans=0;
    string s;cin>>s;
    int n=s.size();
    int k=0;
    vector<int>p;
    p.push_back('$');p.push_back('#');
    for(int i=0;i<n;i++)p.push_back(s[i]),p.push_back('#');p.push_back('$');
    n=p.size()+1;
    vector<int>re(n+5);
    int r=0,c=0;
    for(int i=1;i<n-1;i++){
        if(i<r)re[i]=min(re[c*2-i],r-i);
        while(p[i+re[i]+1]==p[i-re[i]-1])re[i]++;
        if(re[i]+i>r){
            r=re[i]+i;
            c=i;
        }
    }
    vector<int>bj;
    for(int i=2;i<n-1;i+=2)bj.push_back((re[i]+1)/2-1); 
    n=s.size();
    vector<int>vis(n+5),res(n+5);
    for(int i=0;i<=n;i++)res[i]=i;
    for(int i=0;i<n;i++){
        if(s[i]==s[0])res[i+1]=1;
        else break;
    }
    for(int i=0;i<n;i++){
        if(vis[i]||bj[i]==0)continue;
        int id=i+1,l=bj[i]+id;
        if(i-bj[i]!=0)res[l]=min(res[l],id); 
        else{
            while(1){
                if(l-1<n&&bj[l-1]){
                    vis[l-1]=1;
                    if(l-1-bj[l-1]!=0){
                        l+=bj[l-1];
                        break;
                    }
                    l+=bj[l-1];
                }else break;
            }
            res[l]=min(res[l],id); 
        }
    }
    int mx=res[n]; 
    for(int i=n;i>=1;i--){
        //cout<<res[i]<<" "; 
        mx=min(mx,res[i]);
        res[i]=mx;
        //cout<<mx<<" ";
    }
        
    for(int i=1;i<=s.size();i++)ans^=i*res[i];
    cout<<ans<<endl;
}
signed main(){ 
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}