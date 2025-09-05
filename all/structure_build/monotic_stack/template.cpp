//lg p5788
//单调栈和单调队列还是有点像的
//单调栈求一个方向的最近的和他产生x关系的数
//单调队列求滑动窗口最值，单看队列有时候也可以知道离他最近的比他小(大)的数(看滑动窗口的要求，且如果在滑动窗口范围内存在的话)
#include <iostream>
using namespace std;
const int N=3e6+10;
int stk[N],a[N],ans[N];
int main(){
    int n,tmp;
    cin>>n;
    int top=-1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=n;i;i--){
        while (top!=-1 && a[stk[top]]<=a[i])  top--;
        if (top==-1)    ans[i]=0;
        else    ans[i]=stk[top];
        stk[++top]=i;
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}