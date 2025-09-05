#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> PII;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
     cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<PII> v(n);
        for (int i = 0; i <n; ++i) {
            cin >> v[i].first;
            v[i].second = i + 1;
        }
        sort(v.rbegin(), v.rend());
        vector<bool> act(n + 2);
        int clones = 0;
        
        for (int i = 0; i < n; ) {
            int val = v[i].first;
            vector<int> pos;
            for (; i < n && v[i].first == val; ++i)
                pos.push_back(v[i].second);
            sort(pos.begin(), pos.end());
            for (int j = 0; j < pos.size(); ++j) {
                int L = pos[j], R = L;
                while (j+1 < pos.size() && pos[j+1] == R+1) 
                    R = pos[++j];
                clones += !act[L-1] && !act[R+1];
            }
            for (int p : pos) act[p] = true;
        }
        cout << clones << '\n';
    }
}