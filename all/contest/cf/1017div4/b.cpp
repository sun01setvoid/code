#include <bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    cin>>t;
    while (t--){
        int n,m,l,r;
        cin>>n>>m>>l>>r;
        if (l==0){
            cout<<0<<" "<<l+m<<endl;
        }
        else if (l<0){
            if (abs(l)<=m) cout<<l<<" "<<m-abs(l)<<endl;
            else cout<<-m<<" "<<0<<endl;
        }
    }
}