#include <iostream>
#include <map>
using namespace std;
typedef struct node{
    int first,second,third;
} PII;
const int M=1e5+10;
string a[M];
int main(){
    map<string,PII> mp;
    int n,m;
    string tmp;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>tmp;
        mp[tmp].first=1;
    }
    cin>>m;
    int cnt=0;
    for (int i=1;i<=m;i++){
        cin>>tmp;
        a[i]=tmp;
        if (mp.count(tmp)){
            if (mp[tmp].third==0)cnt++;
            mp[tmp].third=1;
        }
    }
    cout<<cnt<<"\n";
    int val=0,len=m;
    for (int i=1,j=1;i<=m;i++){
        if (mp.count(a[i])){
            if (mp[a[i]].second==0) val++;
            mp[a[i]].second++;
        }
        for (;j<=i;){
            if (val<cnt) break;
            else if (val==cnt){
                len=min(len,i-j+1);
                if (mp.count(a[j])){
                    mp[a[j]].second--;
                    if (mp[a[j]].second==0) val--;
                }
                j++;
            }
        }
    }
    if (cnt==0) len=0; //特判
    cout<<len;
}