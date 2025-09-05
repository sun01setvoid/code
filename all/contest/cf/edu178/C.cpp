#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        int cnt1=0,cnt2=0;
        int f1[2]={0,0},f2[2]={0,0};
        int ma1=0,ma2=0;
        for (int i=1;i<=n;i++){
            if (s[i-1]=='A'){
                cnt1++;
                if (i==1) f1[0]=1;
                if (i==n) f1[1]=1;
                else {
                    ma1=max(ma1,i);
                }
            }
            else{
                cnt2++;
                ma2=max(ma2,i);
                if (i==1) f2[0]=1;
                if (i==n) f2[1]=1;
            }
        }
        if (f1[0] && f1[1]) cout<<"Alice"<<"\n";
        else if (f2[0] && f2[1]) cout<<"Bob"<<"\n";
        else if (f1[0] && f2[1]){
            if (cnt2>=2) cout<<"Bob"<<"\n";
            else cout<<"Alice"<<"\n"; 
        } 
        else if (f1[1] && f2[0]){
            if (ma1>ma2){
                    cout<<"Alice"<<"\n";
            }
            else cout<<"Bob"<<"\n";
        }
    }
}