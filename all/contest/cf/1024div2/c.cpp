#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dfs(int n) {
    vector<vector<int>> mp(n, vector<int>(n, 0));
    int l = 0, r = n - 1;
    int l1 = 0, r1 = n - 1;
    int num = 0;
    while (l <= r && l1 <= r1) {
        for (int i = l; i <= r; ++i) {
            mp[l1][i] = num++;
        }
        ++l1;
        for (int i = l1; i <= r1; ++i) {
            mp[i][r] = num++;
        }
        --r;
        if (l1 <= r1) {
            for (int i = r; i >= l; --i) {
                mp[r1][i] = num++;
            }
            --r1;
        }
        if (l <= r) {
            for (int i = r1; i >= l1; --i) {
                mp[i][l] = num++;
            }
            ++l;
        }
    }
    return mp;
}

int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> a = dfs(n);
        for (auto& r : a) {
            for (auto& i : r) {
                cout << n*n-1-i <<" ";
            }
            cout <<"\n";
        }
    }
    return 0;
}
