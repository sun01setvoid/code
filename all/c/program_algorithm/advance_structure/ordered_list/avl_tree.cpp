//平衡的二叉搜索树
//使abs(h(rs)-h(ls))<=1
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ke[N],he[N],ls[N],rs[N],sz[N],ke_cnt[N];
int head,cnt;
//空间从1->n  不断加入，也可以删除
//当前键值，以当前点为根的树的高度，左空间，右空间，以当前节点为根的树的节点个数，当前键值的个数
//有词频统计！！！
void clear(){
    fill(ke+1,ke+cnt+1,0);fill(he+1,he+cnt+1,0);
    fill(ls+1,ls+cnt+1,0);fill(rs+1,rs+cnt+1,0);
    fill(ke_cnt+1,ke_cnt+cnt+1,0);fill(sz+1,sz+cnt+1,0);
    cnt=0;head=0;
}
void up(int i){
    sz[i]=sz[ls[i]]+sz[rs[i]]+ke_cnt[i];
    he[i]=max(he[ls[i]],he[rs[i]])+1;
}
int leftRotate(int i){
    int r=rs[i];
    rs[i]=ls[r];
    ls[r]=i;
    up(i);up(r);
    return r;
}
int rightRotate(int i){
    int l=ls[i];
    ls[i]=rs[l];
    rs[l]=i;
    up(i);up(l);
    return l;
}
int maintain(int i){ //检查是否违规
    int lh=he[ls[i]],rh=he[rs[i]];
    if (lh-rh>1){
        if (he[ls[ls[i]]]>=he[rs[ls[i]]]){
            i=rightRotate(i);
        }else{
            ls[i]=leftRotate(ls[i]);
            i=rightRotate(i);
        }
    }else if (rh-lh>1){
        if (he[rs[rs[i]]]>=he[ls[rs[i]]]){
            i=leftRotate(i);
        }
        else {
            rs[i]=rightRotate(rs[i]);
            i=leftRotate(i);
        }
    }
    return i;
}
int add(int i,int num){
    if (i==0){
        ke[++cnt]=num;
        ke_cnt[cnt]=sz[cnt]=he[cnt]=1;
        return cnt;
    }
    if (ke[i]==num) ke_cnt[i]++;
    else if (ke[i]>num) ls[i]=add(ls[i],num);
    else rs[i]=add(rs[i],num);
    up(i);
    return maintain(i);
}
void add(int num){  //加节点时违规类型只有一种,且只会处理一次
    head=add(head,num);
}
int getrk(int i,int num){
    if (i==0) return 0;
    if (ke[i]>=num){
        return getrk(ls[i],num); 
    }else{
        return sz[ls[i]]+ke_cnt[i]+getrk(rs[i],num);
    }
}
int getrk(int num){ //rank  小于等于它的数的数量+1
    return getrk(head,num)+1;
}
int removeMostLeft(int i,int mostLeft){
    if (i==mostLeft) return rs[i];
    else{
        ls[i]=removeMostLeft(ls[i],mostLeft);
        up(i);
        return maintain(i);
    }
}
int remove(int i,int num){
    if (ke[i]<num) rs[i]=remove(rs[i],num);
    else if (ke[i]>num) ls[i]=remove(ls[i],num);
    else{
        if (ke_cnt[i]>1) ke_cnt[i]--;
        else if (ls[i]==0 && rs[i]==0) return 0;
        else if (ls[i]!=0 && rs[i]==0) i=ls[i];
        else if (ls[i]==0 && rs[i]!=0) i=rs[i];
        else{
            int mostLeft=rs[i];
            while (ls[mostLeft]!=0){
                mostLeft=ls[mostLeft];
            }
            rs[i]=removeMostLeft(rs[i],mostLeft);
            ls[mostLeft]=ls[i];
            rs[mostLeft]=rs[i];
            i=mostLeft;
        }
    }
    up(i);
    return maintain(i);
}
void remove(int num){ //删节点时可能同时出现LL和LR同时出现，按LL调整，可能RR，RL同时出现，按RR调整
    if (getrk(num)!=getrk(num+1)){  //这个数存在,有num,rk(num+1)才会变
        head=remove(head,num);
    }
}
int index(int i,int x){  //查询排名x的数
    if (sz[ls[i]]>=x) return index(ls[i],x);
    else if (sz[ls[i]]+ke_cnt[i]<x) return index(rs[i],x-sz[ls[i]]-ke_cnt[i]);
    return ke[i];
}
int index(int x){
    return index(head,x);
}
int pre(int i,int num){  //小于x,尽量大，前驱
    if (i==0) return INT_MIN;
    if (ke[i]>=num) return pre(ls[i],num);
    else return max(ke[i],pre(rs[i],num));
}
int suf(int i,int num){//后继
    if (i==0) return INT_MAX;
    if (ke[i]<=num) return suf(rs[i],num);
    else return min(ke[i],suf(ls[i],num));
}
int pre(int num){
    return pre(head,num);
}
int suf(int num){
    return suf(head,num);
}
int main(){
    int n;
    cin>>n;
    while (n--){
        int opt,x;
        cin>>opt>>x;
        if (opt==1) add(x);
        else if (opt==2) remove(x);
        else if (opt==3) cout<<getrk(x)<<endl;
        else if (opt==4) cout<<index(x)<<endl;
        else if (opt==5) cout<<pre(x)<<endl;
        else cout<<suf(x)<<endl;
    }
    clear();
}