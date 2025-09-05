#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int N = 105;  
const int M = 105;   
const int X = 5005; 

int dp[N][X];
int s[N][M]; 
int a[N][M];  

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x;
        cin >> n >> m >> x;
        int sum = 0;  
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> s[i][j] >> a[i][j];
                sum += a[i][j];
                s[i][j] += s[i][j-1];
                a[i][j] += a[i][j-1];
            }
        }
        
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i) {         
            for (int j = x; j >= 0; --j) {      
                dp[i][j] = dp[i-1][j];          
                for (int k = 1; k <= m; ++k) {  
                    if (s[i][k] > j) break;     
                    if (j >= s[i][k]) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j - s[i][k]] + a[i][k]);
                    }
                }
            }
        }
        
        cout << sum - dp[n][x] << "\n";
    }
    return 0;
}