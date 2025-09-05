#include <bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    cin>>t;
    while (t--){
        string p,s;
        cin>>p>>s;
        bool f=1;
        int i1,i2,j1,j2;
        for (i1=0,i2=0,j1=0,j2=0;i1<p.size();i1=i2,j1=j2){
            if (p[i1]!=s[j1]){
                f=0;
                break;
            }
            while (i2<p.size() && p[i2]==p[i1]){
                i2++;
            }
            while (j2<s.size() && s[j2]==s[j1]){
                j2++;
            }
            if (!((j2-j1+1)/2<=i2-i1 && i2-i1<=j2-j1)){
                f=0;
                break;
            }
        }
        if (j1!=s.size()){
            f=0;
        }
        if (f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}