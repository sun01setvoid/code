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
const int z = 2e5 + 10;
int vis[z], mp[z][4], p[z][4];
int mk(int a, int b) {
    return min(a, b) * z + max(a, b);
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mp[i][0];
        for (int j = 1; j <= mp[i][0]; j++)cin >> mp[i][j];
    }
    set<int>se;
    for (int j = 1; j <= n; j++)for (int k = 1; k <= 3; k++)p[j][k] = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] > 0)cout << vis[i] << endl;
        else {
            int now = i, len = 1, pre = 0, prl = 0, tt;
            vector<int>tmp;
            se.clear();
            se.insert(0);
            while (p[now][len] == 0) {
                prl = len;
                pre = now;
                p[now][len] = se.size();
                if (len == 1)tmp.push_back(now);
                tt = mp[now][len];
                se.insert(mk(now, tt));
                for (int j = 1; j <= mp[tt][0]; j++) {
                    if (mp[tt][j] == now) {
                        len = j + 1;
                        break;
                    }
                }
                if (len == mp[tt][0] + 1)len = 1;
                now = tt;
                //cout<<mp[now][len]<<" "<<now<<" "<<len<<endl;
            }
            se.insert(mk(now, pre));
            p[pre][prl] = se.size();
            int ttt = p[now][len];
            int de = p[pre][prl] - ttt;
            for (auto t : tmp) {
                if (p[t][1] > ttt)vis[t] = de;
                else vis[t] = de + ttt - p[t][1];
            }
            cout << vis[i] << endl;
        }
    }
}
signed main() {
    IOS;
    int t = 1;
    //cin>>t;
    while (t--)solve();
}