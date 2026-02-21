#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
int nxt[N];
char str1[N],str2[N];//字符串从1开始
void find_next(char* s){
  	int j=0;
	for (int i=2;s[i]!='\0';i++)
    {
    	if (j && s[j+1]!=s[i] ) j=nxt[j];//往前还能不能判断
      	if (s[i]==s[j+1]) j++;
      	nxt[i]=j;
    }
}
int main(){
  while (scanf("%s",str1+1)){
  	if (str1[1]=='#')
      break;
    int cnt=0;
    memset(nxt,0,sizeof(nxt));
    scanf("%s",str2+1);
    find_next(str2);//注意要让传进去的字符串的是s[1]为起始位置
    for (int i=1,j=0;str1[i]!='\0';i++){
    	while (j && str1[i]!=str2[j+1]) j=nxt[j];
      	if (str2[j+1]==str1[i]) j++;
      	if (str2[j+1]=='\0'){
        	cnt++;
          	j=0;
        }
    }
    printf("%d\n",cnt);
  }
}

//kmp  nextval优化 
//s[j]!=s[next[j]] nextval[j]=next[j]
//相等则继续往前找
//假设考虑这样的一个1-i的1-i-1的公共前后缀长度为k,
//若s[i]==s[k],!!!!!!!!!!如果i这位置都不匹配，k+1这位置也不可能匹配
//也就是说1-i-1在i失去匹配后，k+1位置也失去匹配
//这是考虑字符串本身的性质（匹配的优化）