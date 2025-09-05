#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;
 
 
//****************************************************************
// Miller_Rabin 算法进行素数测试
//速度快，而且可以判断 <2^63的数
//****************************************************************
const int S=20;//随机算法判定次数，S越大，判错概率越小
 
 
//计算 (a*b)%c.   a,b都是int的数，直接相乘可能溢出的
//  a,b,c <2^63
int mult_mod(int a,int b,int c)
{
    a%=c;
    b%=c;
    int ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}
 
 
 
//计算  x^n %c
int pow_mod(int x,int n,int mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    int tmp=x;
    int ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}
 
 
 
 
 
//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(int a,int n,int x,int t)
{
    int ret=pow_mod(a,x,n);
    int last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}
 
// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;
 
bool Miller_Rabin(int n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    int x=n-1;
    int t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        int a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}
 
 
//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
int factor[100];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始
 
int gcd(int a,int b)
{
    if(a==0)return 1;//???????
    if(a<0) return gcd(-a,b);
    while(b)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
 
int Pollard_rho(int x,int c)
{
    int i=1,k=2;
    int x0=rand()%x;
    int y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        int d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
//对n进行素因子分解
void findfac(int n)
{
    if(Miller_Rabin(n))//素数
    {
        factor[tol++]=n;
        return;
    }
    int p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}
int main()
{
    int n;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        tol=0;
    findfac(n);
    if(tol==1){
        printf("Prime\n");
        continue;
    }
    sort(factor,factor+tol);
        cout<<factor[0]<<endl;
    }
}
