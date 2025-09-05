//????题
#include <iostream>
#include <string.h>
using namespace std;
const int N=50010;
int nxt[2*N],n,m;
char str1[N],str2[N],p[2*N];//字符串从1开始
void find_next(){
  	int j=0;
	for (int i=2;i<=n+m;i++)
    {
    	if (j && p[j+1]!=p[i] ) j=nxt[j];//往前还能不能判断
      if ( p[i] == p[j+1] ) j++;
      nxt[i]=j;
    }
   if(!nxt[n+m])
      printf("0\n");
    else{
      int tmp = nxt[n+m];
      str1[tmp+1]='\0';
      if(n > m){
        if(tmp>m)
          printf("%s %d\n" , str2+1 , m);
        else
          printf("%s %d\n" , str1+1, tmp);
      }
      else{
        if(tmp>n)
          printf("%s %d\n" , str1+1 , n);
        else
          printf("%s %d\n" , str1+1 , tmp);
	}
    }
}
int main(){
  while (scanf("%s %s",str1+1,str2+1)!=EOF){
    n=strlen(str1+1),m=strlen(str2+1);
    memset(nxt,0,sizeof nxt);
    strcpy(p+1,str1+1);
    strcat(p+1,str2+1);
    find_next();//注意这里是p 
  }
}