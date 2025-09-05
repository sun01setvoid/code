#include <bits/stdc++.h>
using namespace std;
int mp[110][15], ans[110][15];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int h;
        cin >> h;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= 10; j++) {
                cin >> mp[i][j],ans[i][j]=0;
            }
        }          
        for (int i=1;i<=h;i++){
            int cnt=0;
            for (int j=1;j<=10;j++){
                if (mp[i][j]==0){
                    cnt++;
                }
                else {
                    if (cnt) {
                        ans[i][j-cnt]=cnt;
                    }
                    cnt=0;
                }
            }
            if (cnt) {
                ans[i][10-cnt+1]=cnt;
            }
        }
        for (int i=1;i<=h;i++){
            for (int j=1;j<=10;){
                if (ans[i][j]){
                    for (int k=1;k<=ans[i][j]-1;k++){
                        ans[i][j+k]=ans[i][j]-k;
                    }
                    j=j+ans[i][j];
                }
                else j++;
            }
        }
        bool f=0;
        for (int i=1;i<=h-1;i++){
            for (int j=2;j<=9;j++){
                if (ans[i][j]>=2 && ans[i+1][j-1]>=2){
                    f=1;
                    break;
                }
            }
            if (f) break;
        }
        if (f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}