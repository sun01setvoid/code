#include <iostream>
using namespace std;
int a[110];
int main(){
    int t;
    cin>>t;
    while (t--){
        int mi=0,ma=0,n;
        string s;
        cin>>n;
        cin>>s;
        a[0]=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='<'){
                a[i+1]=--mi;
            }
            if (s[i]=='>'){
                a[i+1]=++ma;
            }
        }
        for (int i=0;i<n;i++){
            a[i]+=(1-mi);
            cout<<a[i]<<" \n"[i==n-1];
        }
    }
}