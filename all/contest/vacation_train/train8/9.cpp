#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int a[1010],stk[1010],top=-1;
    cin>>n;
    for (int i=1;i<=n;i++)    cin>>a[i];
    vector <int> ans;int cur=0;
    ans.push_back(a[1]);
    int i=2,m=0;
    while (i<=n){
        if (a[i]<ans.back())    ans.push_back(a[i]),i++;
        else{
            if (top==-1 || a[i]>stk[top])    stk[++top]=a[i],i++;
            else{
                m=max(m,(int)ans.size());
                ++cur;ans.clear();
                while (stk[top]>a[i] && top!=-1){
                    ans.push_back(stk[top--]);
                }
                ans.push_back(a[i]);i++;
            }
        }
    }
    if (ans.size())    m=max(m,(int)ans.size()),cur++;
    if (top!=-1)    m=max(m,top+1),cur++;
    cout<<cur<<" "<<m;
}