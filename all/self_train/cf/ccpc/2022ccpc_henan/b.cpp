#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef unsigned long long  ULL;
const int P=31,N=1e5+10,MOD=1;
int dp[N][8];
char s[N];
ULL h[N],p[N];
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int p[8],r[26];
int main(){
    string s;
    cin>>s;
    p[0]=1;
    r[0]=1,r['e'-'a']=2,r['h'-'a']=3,r['n'-'a']=4;
    for (int i=1;i<=8;i++) p[i]=31*p[i-1];
    for (int i=1;i<=s.size();i++){
        for (int j=1;j<=6;j++){
            dp[i][j]=dp[i-1][j-1]+p[i];
        }
    }
}