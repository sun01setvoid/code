#include <bits/stdc++.h>
using namespace std;
const int N=2020;
int a[N], ma[N][N], mi[N][N], ans[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            ma[i][i] = mi[i][i] = a[i];
            for(int j = i+1; j <= n; j++){
                ma[i][j] = max(ma[i][j-1], a[j]);
                mi[i][j] = min(mi[i][j-1], a[j]);
            }
        }
        for(int l = 1; l <= n; l++){
            for(int r = l; r <= n; r++){
                ans[l][r] = 0;
            }
        }

        for(int k = 1; k < n; k++){
            for(int l = 1; l <= k; l++){
                int ma1 = ma[l][k];
                for(int r = k+1; r <= n; r++){
                    if(ma1 <= mi[k+1][r]){
                        ans[l][r]++;
                    }
                }
            }
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            cout << ans[l][r] << "\n";
        }
    }

    return 0;
}
