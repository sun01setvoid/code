#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> PII;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector <double> alls;
        vector <PII> qry;
        for (int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            qry.push_back({l+0.1,r-0.1});
            alls.push_back(l+0.1);
            alls.push_back(l+0.15);
            alls.push_back(r-0.15);
            alls.push_back(l+0.05);
            alls.push_back(r-0.05);
            alls.push_back(r-0.1);
        }
        sort(alls.begin(),alls.end());
        alls.erase(unique(alls.begin(),alls.end()),alls.end());
        sort(qry.begin(),qry.end());
        priority_queue <double,vector<double>,greater<double>> q;
        int ans=0;
        for (int i=0,j=0;i<alls.size() && j<qry.size();i++){
            while (j<qry.size() && qry[j].first<=alls[i]){
                q.push(qry[j].second);
                j++;
            }
            while (!q.empty()){
                double tmp=q.top();
                if (tmp+1.0<alls[i]){
                    q.pop();
                }
                else break;
            }
            ans=max(ans,(int)q.size());
        }
        cout << ans << "\n";
    }
}