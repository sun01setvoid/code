#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <long long ,long long> PII;
const int N=20; 
int sum[N],ans[N];
long long inf=1e12+(long long)10;
int main(){
    int n,flag=1;
    long long li,ri,ans=0;
    vector <PII> add;
    cin>>n;
    add.push_back({0,inf});
    for (int i=1;i<=n;i++){
        cin>>li>>ri;
        add.push_back({li-i,ri-i});
    }
    add.push_back({-(long long)(n+1),inf});
    long long l=add[0].first,r=add[0].second,res=0;
    for (int i=1;i<(int)add.size();i++){
        if (add[i].first<=r && add[i].second>=0){
            if (add[i].first>l) res=add[i].first;
            ans+=res-l+1;
        }
        else{
            flag=0;
            break;
        }           
        l=res,r=add[i].second;
    }
    if (flag){
        cout<<ans;
    }
    else    cout<<-1;
}