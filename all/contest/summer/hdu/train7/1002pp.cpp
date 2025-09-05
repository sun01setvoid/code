#include <bits/stdc++.h>
using namespace std;

using int64 = long long;


static inline long long sum_abs_to_point(const vector<long long>& a, long long m) {
    long long s = 0;
    for (auto x : a) s += llabs(x - m);
    return s;
}


static inline long long interval_distance(long long L1, long long R1, long long L2, long long R2) {
    if (R1 < L2) return L2 - R1;
    if (R2 < L1) return L1 - R2;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> q(n), r(n), s(n);
        for (int i = 0; i < n; ++i) {
            cin >> q[i] >> r[i] >> s[i];
        }
        sort(q.begin(), q.end());
        sort(r.begin(), r.end());
        sort(s.begin(), s.end());
        
        long long QL = q[(n - 1) / 2], QR = q[n / 2];
        long long RL = r[(n - 1) / 2], RR = r[n / 2];
        long long SL = s[(n - 1) / 2], SR = s[n / 2];
        long long Amin = sum_abs_to_point(q, QL);  
        long long Bmin = sum_abs_to_point(r, RL);
        long long Cmin = sum_abs_to_point(s, SL);
        
        long long I_L = QL + RL, I_R = QR + RR;     
        long long J_L = -SR,     J_R = -SL;          
        
        long long d = interval_distance(I_L, I_R, J_L, J_R);
        
        long long ans = (Amin + Bmin + Cmin + d) / 2;
        cout << ans << "\n";
    }
    return 0;
}