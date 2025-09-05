#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ke[N],he[N],ls[N],rs[N],sz[N],ke_cnt[N];
int head,cnt;
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
void add(int num){  
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
void remove(int num){ 
    if (getrk(num)!=getrk(num+1)){  
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
int pre(int i,int num){  //小于x,尽量大
    if (i==0) return INT_MIN;
    if (ke[i]>=num) return pre(ls[i],num);
    else return max(ke[i],pre(rs[i],num));
}
int suf(int i,int num){
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