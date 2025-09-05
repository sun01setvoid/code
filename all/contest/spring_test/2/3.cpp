#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=1000010;
int a[N];
int vis[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n=0;
    cin>>t;
    while (t--){
        memset(vis,0,sizeof vis);
        int l[2]={0,0};
        unordered_map <int,int> mp;//p
        unordered_map <int,int> mp1;//0p
        unordered_map <int,int> mp2;//p0p
        unordered_map <int,int> mp3;//qp0p个数
        int cnt=0;//p0p个数
        ll  ans=0;
        cin>>n;
        for  (int i=1;i<=n;i++) {
            cin>>a[i];
            while (a[i]==0 && l[0]<l[1]){
                mp1[vis[l[0]]]=1;
                l[0]++;
            }
            if (a[i]!=0){
                if (cnt && mp3[a[i]]<cnt)   ans=ans-(ll)mp3[a[i]]+(ll)cnt,mp3[a[i]]=cnt;    
                if (mp1.count(a[i])  &&  !mp2.count(a[i])){
                    mp2[a[i]]=1;
                    cnt++;
                }
                if (!mp.count(a[i]))    {mp[a[i]]=1;vis[l[1]++]=a[i];}
            }
        }
        cout<<ans<<endl;
    }
}