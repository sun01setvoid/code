#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map <int,int> mp1;//并查集
unordered_map <int,int> mp2;//排序到的位置
unordered_map <int,int> mp3;//在不在区间
int a[1010];
int b[1010];
int find (int x){
    if (mp1[x]!=x)  mp1[x]=find(mp1[x]);
    else return mp1[x];
}
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        mp1[a[i]]=a[i];
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++){
        mp2[b[i]]=i;
    }
    for (int i=1;i<=n;i++){
        if (mp3.count(a[i]-k)){
            int f1=find(a[i]-k),f2=find(a[i]);
            if (f1!=f2)
                mp1[f1]=f2;
        }
        else if (mp3.count(a[i]+k)){
            int f1=find(a[i]+k),f2=find(a[i]);
            if (f1!=f2)
                mp1[f1]=f2;
        }
        mp3[a[i]]=1;
    }
    for (int i=k+1;i<=n;i++){
        int f1=find(a[i]),f2=find(a[i-k]);
        if (f1!=f2) mp1[f1]=f2;
    }
    bool f=0;
    for (int i=1;i<=n;i++){
        f=0;
        if ((mp2[a[i]]-i)%k==0)  f=1;
        else {
            int f1=find(a[i]),f2=find(a[mp2[a[i]]]);
            if (f1==f2) f=1;
        }
        if (!f) break;  
    }
    if (f)  cout<<"YES"<<endl;
    else {
        cout<<"NO"<<endl;
    }
}