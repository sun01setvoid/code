//spfa差分约束
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 10 ;
int e[N * 2] , ne[N * 2] , h[N * 2] , idx , w[N * 2] , dis[N] , vis[N] , n , out[N];
bool st[N] ;

void add(int a , int b , int c)
{
	a ++ , b ++ ;
	e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}
queue<int> q ;
void SPFA(int from)
{
	for(int i = 0;i <= N;i ++) dis[i] = 0x3f3f3f3f ;
	q.push(from) ;
	memset(st , false , sizeof st) ;
	dis[from] = 0 ; 
	st[from] = true ;
	int flag = 0 ;
	while(q.size())
	{
		int t = q.front() ;
		q.pop() ;
        st[t] = false ;
		for(int i = h[t] ;i != -1 ;i = ne[i])
		{
			int j = e[i] ;
			if(dis[j] > dis[t] + w[i])
			{
				dis[j] = dis[t] + w[i] ;
				if(!st[j])
				 {
				 	st[j] = true ;
				 	q.push(j) ;
				 }
		
			}
		}
		
	}
    return ;
}
int main()
{
	int  n1 , n2 ;
	while(~scanf("%d",&n))
	{
	idx = 0 ;
	int a ,b , c ;
	int from = 0x3f3f3f3f , to = 0 ;
	memset(h , -1 , sizeof h);
	for(int i = 1;i <= n ;i ++)
	{
		scanf("%d%d%d",&a, &b, &c) ;
		add(b , a - 1, -c) ;
		if(from > a) from = a ;
		if(b > to) to = b ;
	}
	for(int i = from ;i <= to ;i ++)
	 add(i - 1 , i , 1) , add(i , i - 1 , 0) ;
	SPFA(to + 1) ;
	printf("%d\n" , -dis[from]);
	}
	
	return  0;
} 
