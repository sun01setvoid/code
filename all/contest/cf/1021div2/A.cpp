#include <iostream>
#include <cstring>
using namespace std;
const int N=15;
int stk[N];
int main(){
    int t;
    cin>>t;
    string s;
    while (t--){
        memset(stk,0,sizeof stk);
        cin>>s;
        for (int i=1;i<=10;i++){
            stk[s[i-1]-'0']++;
        }
        for (int i=1;i<=10;i++){
            for (int j=10-i;j<=9;j++){
                if (stk[j]) {cout<<j;stk[j]--;break;}
            }
        }
        cout<<"\n";
    }
}