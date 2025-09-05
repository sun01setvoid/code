#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int ,int > PII;
int a[300010];
int main(){
    int x,n,m,l,r,c;
    vector <int> alls;//区间端点也要加上去,这样更容易计算前缀和和查询;不加很难做左边需要判断确定能不能-1
    vector <PII> add,query;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for (int i=0;i<m;i++){
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());//去重
    for (auto item:add){//遍历
        int j=lower_bound(alls.begin(),alls.end(),item.first)-alls.begin()+1;
        a[j]+=item.second;
    }
    for (int i=1;i<=(int)alls.size();i++)    a[i]=a[i-1]+a[i];//long unsigned alls.size()
    for (auto item:query){
        int l1=lower_bound(alls.begin(),alls.end(),item.first)-alls.begin()+1;
        int r1=lower_bound(alls.begin(),alls.end(),item.second)-alls.begin()+1;    
        cout<<a[r1]-a[l1-1]<<endl;
    }
}
//可以a数组存储val和order
//然后a排序后在原位置上更改离散后的大小,即是b[a[i].order]=i;i即是大小
