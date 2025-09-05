#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int a[100010];
int main(){
    int n;
    cin>>n;
    unordered_map <int,int> mp;
    for (int i=0;i<n;i++)   cin>>a[i];
    int res=0;
    for (int i=0,j=0;i<n && j<n;j++){
        if (!mp.count(a[j]))    mp[a[j]]=1;
        else mp[a[j]]+=1;
        while (mp[a[j]]>1 && i<j)  mp[a[i]]--,i++;//找以前有没有出现过，且更新指针前面的值都要清空
        res=max(res,j-i+1);
    }
    cout<<res;
}
//这是从最小开始，通过前后指针调节头尾，i是j的条件下可达到的最远位置，j是始终移动的指针