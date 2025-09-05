#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int x,y;
};
bool cmp1(node a,node b){
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmp2(node a,node b){
    if (a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}
int solve1(vector<node> &a){
    int ymin=LONG_LONG_MAX,ymax=LONG_LONG_MIN;
    int n=a.size();
    for (auto &i:a){
        ymin=min(ymin,i.y);
        ymax=max(ymax,i.y);
    }
    if ((ymax-ymin+1)*(a[n-1].x-a[0].x+1) > n) return (ymax-ymin+1)*(a[n-1].x-a[0].x+1);
    else return min((ymax-ymin+2)*(a[n-1].x-a[0].x+1),(a[n-1].x-a[0].x+2)*(ymax-ymin+1));
}
int solve2(vector<node> &a){
    int xmin=LONG_LONG_MAX,xmax=LONG_LONG_MIN;
    int n=a.size();
    for (auto &i:a){
        xmin=min(xmin,i.x);
        xmax=max(xmax,i.x);
    }
    if ((xmax-xmin+1)*(a[n-1].y-a[0].y+1) > n) return (xmax-xmin+1)*(a[n-1].y-a[0].y+1);
    else return min((xmax-xmin+2)*(a[n-1].y-a[0].y+1),(a[n-1].y-a[0].y+2)*(xmax-xmin+1));
}
signed main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<node> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y;
        }
        if (n==1 || n==2) cout<<n<<endl;
        else{
            sort(a.begin(), a.end(),cmp1);
            auto tmp=vector <node> (a.begin()+1,a.end());
            int ans=LONG_LONG_MAX;
            ans=min(ans,solve1(tmp));
            tmp=vector <node> (a.begin(),a.end()-1);
            ans=min(ans,solve1(tmp));
            sort(a.begin(), a.end(),cmp2);
            tmp=vector <node> (a.begin()+1,a.end());
            ans=min(ans,solve2(tmp));
            tmp=vector <node> (a.begin(),a.end()-1);
            ans=min(ans,solve2(tmp));
            cout<<ans<<endl;
        }
    }
}