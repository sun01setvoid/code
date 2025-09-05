#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while (t--){
        int q,s,v;
        cin>>q;
        int sum=0,cnt=0,r=0;
        deque <int> dq[2];
        int cur=0;
        while (q--){
            cin>>s;
            if  (s==1){
                int a1=dq[cur].back(),a2=dq[cur^1].front();
                dq[cur].pop_back(),dq[cur^1].pop_front();
                dq[cur].push_front(a1),dq[cur^1].push_back(a2);
                r=r-a1*cnt+sum;
            }
            else if (s==2){
                cur=cur^1;
                r=(cnt+1)*sum-r;
            }
            else{
                cin>>v;
                cnt++;
                sum+=v;
                dq[cur].push_back(v);
                dq[cur^1].push_front(v);
                r+=v*cnt;
            }
            cout<<r<<endl;
        }
    }
}