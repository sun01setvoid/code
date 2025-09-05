#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int ,int> PII;//必须放在namespace底下
int main(){
    string subs="kira";
    string s;
    int n,res=0;
    cin>>n>>s;
    //O(n)
    vector <PII> a(n);
    a[0]={0,0};
    if (s[0]=='k'){
        a[0].second=1;
    }
    for (int i=1;i<=n-1;i++){
        a[i]=a[i-1];//状态复制
        if (subs[a[i].second]==s[i]){
            if (s[i]=='a'){
                a[i].first+=1;
                a[i].second=0;
            }
            else{
                a[i].second+=1;
            }
        }
    }
    vector <PII> b(n);
    string subst="ikod";
    b[n-1]={0,0};
    if (s[n-1]=='i')    b[n-1].second+=1; 
    for (int i=n-2;i>=0;i--){
        b[i]=b[i+1];//状态复制
        if (subst[b[i].second]==s[i]){
            if (s[i]=='a'){
                b[i].first+=1;
                b[i].second=0;
            }
            else{
                b[i].second+=1;
            }
        }
    }
    for (int i=0;i<=n-2;i++){
        res=max(res,a[i].first*4+b[i+1].first*4);
    }
    cout<<res;
}