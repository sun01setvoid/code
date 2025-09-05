#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int tr[1000010],n;
int lowbit(int x){
    return x&-x;
}
void add(int x,int c){
    for (int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x){
    int ans=0;
    for (int i=x;i;i-=lowbit(i))    ans+=tr[i];
    return ans;
}
int main(){
    int temp;
    while (cin>>n){
        memset(tr,0,sizeof tr);
        vector <int> a;
        vector <int> b;
        map<int,int> mp;
        for (int i=0;i<n;i++){
            cin>>temp;
            a.push_back(temp);
            b.push_back(temp);
        }
        sort(b.begin(),b.end());
        for (int i=0;i<b.size();i++)    mp[b[i]]=i+1;
        int ans=0;
        for (int i=0;i<a.size();i++){
            add(mp[a[i]],1);
            ans+=sum(n)-sum(mp[a[i]]);
        }
        cout<<ans<<endl;
    }
}