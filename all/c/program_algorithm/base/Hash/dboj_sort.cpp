#include <stdio.h>
#include <cstring>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	int n,m,temp;
  while (~scanf("%d %d",&n,&m)){
    memset(a,0,sizeof a);
  	for (int i=0;i<n;i++){
    	scanf("%d",&temp);
      	a[temp+500000]+=1;
    }
    for (int i=1e6;m!=0;i--){
    	while (a[i]!=0){
          if(m!=1)	
          printf("%d ",i-500000);
          else
            printf("%d",i-500000);
          a[i]--;
          m--;
        }
    }
    printf("\n");
  }
}