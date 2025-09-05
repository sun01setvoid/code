#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define double long double
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
//再不卷就退役了
const double mod=8e18;
const double pi=3.141592653589793;
void solve(){
	int n,x,y;cin>>n>>x>>y;
	vector<double>p1,p2,ppp;
	double t1=0,t2=mod;
	for(int i=1;i<=n;i++){
		int a,b;cin>>a>>b;a-=x;b-=y; 
		double p=a*a+b*b;
		double tt=a/sqrt(p);
		double pp=acos(tt);
		if(b<0)pp=2*pi-pp;
		ppp.push_back(pp);
		if(p>t1){
			p1.clear();
			t1=p;
			p1.push_back(pp);
		}else if(p==t1)p1.push_back(pp);
		if(t2>p){
			p2.clear();
			t2=p;
			p2.push_back(pp);
		}else if(t2==p)p2.push_back(pp);
	}
	sort(p1.begin(),p1.end());
	sort(p2.begin(),p2.end());
	int f=0,pr=ppp[0],ff=0;
	for(int i=0;i<n;i++){
		if(ff==1)ppp[i]+=2*pi;
		if(pr<ppp[i])pr=ppp[i];
		else{
			if(ff==0){
				ff=1;
				ppp[i]+=2*pi;
				pr=ppp[i];
			}else{
				f=1;
				break;
			}
		}
	}
	double res=0;
	for(int i=1;i<p1.size();i++){
		double tt=p1[i]-p1[i-1];
		if(tt>res)res=tt;
	}
	double tt=p1[0]-p1[p1.size()-1]+2*pi;
	if(tt>res)res=tt;
	if(!f){
			for(int i=1;i<p2.size();i++){
			double tt=p2[i]-p2[i-1];
			if(tt>res)res=tt;
		}
		tt=p2[0]-p2[p2.size()-1]+2*pi;
		if(tt>res)res=tt;
	}
	cout<<fixed<<setprecision(12)<<res<<endl;
}
signed main(){    
    //IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}