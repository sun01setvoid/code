//前缀和的应用，找那些里面和对称的匹配，相加为0，1，0->1,-1,也可以直接找,不改为1，-1（存储m-f)，map用来查找，map有两个元素可以设置位置
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int pre[100010];
int main(){
    int n,temp,t,res=0;
    cin>>n;
    unordered_map <int,int> S; 
    for (int i=1;i<=n;i++){
        cin>>temp;
        pre[i]=pre[i-1]+(temp?1:-1);
        if (!S.count(pre[i]))
            S[pre[i]]=i;
    }//1只与最近的0匹配
    S[0]=0;//前缀和的第0位；
    for (int i=1;i<=n;i++){
        if (S.count(pre[i]))
            res=max(res,i-S[pre[i]]);
    }
    cout<<res;
}
//总结：01匹配找个数一样的——即找前缀和相同的
