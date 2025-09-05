//单调队列单调栈
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    int num;
    int p;
};
int main(){
    Node st[100010];
    int n,top=-1,temp;
    double ans=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>temp;
        while (top!=-1 && st[top].num>temp){
            top--;
        }
        for (int j=0;j<=top;j++){
            ans=max((double)(temp-st[j].num)/(i-st[j].p),ans);
        }
        st[++top]={temp,i};
    }
    cout<<ans;
}