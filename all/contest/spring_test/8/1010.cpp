#include<bits/stdc++.h>
using namespace std;
set<long long> s;
bool check(long long hashb, long long val) {
    long long hasha = 0;
    long long bas = 1;
    if(hashb == 0) return false;
    while(hashb != 0) {
        if(hashb % 27 == 0) return false;
        hasha = (hasha + (hashb % 27) * bas) % 10007;
        bas = bas * 10;
        hashb /= 27;
    }
    return val == hasha;
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        s.clear();
        int k, c, d, e, f;
        cin >> k >> c >> d >> e >> f;
        long long limit = pow(27, k) - 1;
        for(long long i = 0; i < 10007; i++) {
            long long hashb = i * i * i * c + i * i * d + i * e + f;
            if(hashb <= limit && check(hashb, i))
                s.insert(hashb);
        }
        cout << s.size() << "\n";
    }
}