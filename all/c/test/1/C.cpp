#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int,int> PII;
const int N=20; 
int sum[N],ans[N];

int main(){
    int n,li,ri;
    vector <PII> add;
    vector <long long> alls;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>li>>ri;
        add.push_back({li-i,ri-i});
        alls.push_back(li-i);
        alls.push_back(ri-i);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for (auto item:add){
        int l=lower_bound(alls.begin(),alls.end(),item.first)-alls.begin()+1;
        int r=lower_bound(alls.begin(),alls.end(),item.second)-alls.begin()+1;
        sum[l]+=1;
        sum[r+1]-=1;
    }
    int flag=0,cnt=1;
    for (int i=1;i<=(int)alls.size();i++){
        sum[i]=sum[i-1]+sum[i];
        if (sum[i]==n){
            flag=1;
            ans[cnt++]=alls[i-1];
        }
    }
    if (flag){
        
    }       
    else 
        cout<<-1;
}