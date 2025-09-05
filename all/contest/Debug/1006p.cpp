#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector <int> alls;
        vector <PII> qry;
        for (int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            qry.push_back({l,r});
            alls.push_back(l);
            alls.push_back(r);
        }
        sort(alls.begin(),alls.end());
        alls.erase(unique(alls.begin(),alls.end()),alls.end());
        sort(qry.begin(),qry.end());
        priority_queue <int,vector<int>,greater<int>> q;
        int ans=0;
        for (int i=0,j=0;i<alls.size() && j<qry.size();i++){
            while (j<qry.size() && qry[j].first<=alls[i]){
                q.push(qry[j].second);
                j++;
            }
            while (!q.empty()){
                int tmp=q.top();
                if (tmp+1<=alls[i]){
                    q.pop();
                }
                else break;
            }
            ans=max(ans,(int)q.size());
        }
        cout << ans << "\n";
    }
}