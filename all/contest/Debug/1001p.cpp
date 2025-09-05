#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string str1, str2;
        cin >> str1 >> str2;
        if (str1.size() != str2.size()) {
            cout << "fool" << endl;
            continue;
        }
        bool f = 0;
        int k = 0;
        for (k = 0; k < str1.size(); k++) {
            f = 1;
            for (int i = 0, j = 0; j < str2.size(); i++, j++) {
                if (str1[(k + i) % str1.size()] != str2[j]) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                break;
            }
        }
        if (f) {
            cout << k + 1 << endl;
        } else {
            cout << "fool" << endl;
        }
    }
}