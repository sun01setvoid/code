#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n,m;
ll f[21]={1};
vector <int> ans;
vector <int> st;
void kt_rev(){
    m=m-1;//从0开始变成了从1开始
    for (int i=0;i<n;i++){
        int t=m/f[n-i-1];//第t+1个从小到大在vector中的数，索引为t
        ans.push_back(st[t]);
        st.erase(st.begin()+t);//删掉或者打标记；
        m=m-t*f[n-i-1];//substract it
    }
}
int main(){
    for (int i=1;i<21;i++)  f[i]=f[i-1]*i;
    while(cin>>n>>m){
        int ori=n;//记录原长
        ans.clear();
        st.clear();
        for (int i=0;i<n;i++)   st.push_back(i+1);
        if (n>8){
            for (int i=0;i<n-8;i++){
                ans.push_back(st[0]);
                st.erase(st.begin());
            }
            ori=n;
            n=8;
        }//从小到大是先从大的开始变的，8！有超过10000中排列，7！小于10000，所以对后8个数进行操作
        kt_rev();
        cout<<ans[0];
        for (int i=1;i<ori;i++)  cout<<" "<<ans[i];
        cout<<endl;
    }
}