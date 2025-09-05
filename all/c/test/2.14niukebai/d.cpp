#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int  a[1010];
int mi;
map <string,int> mp;
void dfs(int l,int r,string p,int sum){
    if (l>r)    {mi=min(sum,mi);return;}
    mp[p]=1;
    if (a[l]>a[r])    sum+=a[l],l++;
    else    sum+=a[r],r--;
    if (!mp.count(p+to_string(a[l])))
        dfs(l+1,r,p+to_string(a[l]),sum);
     if (!mp.count(p+to_string(a[r])))
        dfs(l,r-1,p+to_string(a[r]),sum);
}
int main(){
    int n;
    cin>>n;
    int res=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        res+=a[i];
    }
    mi=res;
    dfs(1,n,"",0);
    cout<<mi<<" "<<res-mi;
}