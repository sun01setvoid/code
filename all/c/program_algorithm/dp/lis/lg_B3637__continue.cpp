//dp但优化，不同长度的上升子序列末尾的值依次递增(反证)，更新使这样递增的值更小，才能让序列越来越长(最长，那就对每个长度分析)
//表面dp,实际是贪心+二分的感觉
//最长上升子序列
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,a[5010],q[5010],mlen=1;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int len=0;//q数组的长度
    q[0]=-2e9;//哨兵,找不到的话在这里停下,要置l+1的位置
    for (int i=0;i<n;i++){
        int l=0,r=len;
        while (l<r){
            int mid=(l+r+1)>>1;
            if (q[mid]<a[i]){
                l=mid;
            }
            else 
            r=mid-1;
        }//考虑边界初始（哨兵），考虑全都比他大（至哨兵处），全都比他小，在中间
        q[l+1]=a[i];
        len=max(len,l+1);//更新长度
    }
    cout<<len;
    system("pause");
}
/*
//dfs  1 2 4 3 4
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,a[5010],nex,mlen=1;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++){
        nex=a[i];
        int length=1;
        for (int j=i+1;j<n;j++){
            if (a[j]>a[nex])
                nex=a[j],length+=1;//朴素搜索要返程啊dfs,应该是更复杂的(下次再写吧。。。。。)O(n+m)
        }
        mlen=max(mlen,length);
    }
    cout<<mlen<<endl;
    system("pause");   
}
*/
/*
//dp（换种想法的话，若集合改为前i个数中的上升子序列(属性为max),那么在状态计算时就有问题了
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,a[5010],f[5010]={0},mlen=1;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    //f[0]=0;//当然还要初始化为0，（初始化为1，因为f[0]取不到）(显然是错误的想法)，后面的点不一定能够被f[0]更新
    for (int i=1;i<n;i++){
        for (int j=0;j<=i-1;j++){
            if (a[i]>a[j]){
                f[i]=max(f[j]+1,f[i]);//注意是max属性
            }
        }
    }
    for (int i=0;i<n;i++)
        mlen=max(mlen,f[i]+1);//还是在这里加一带上起点的初始长度
    cout<<mlen;
    system("pause");
}
*/