//从单个到多个，从相邻到不相邻
//状态表示：f[i][j]表示前i个字符删除j个后不同的字符串数。
//f[i][j]=f[i-1][j]+f[i-1][j-1](-f[last-1][j-(i-last)])(if j>=i-last)
//找到离他最近的与是s[i]相等的s[x]，删除(x,i+1),(x+1,i)得到的后面是一样的
#include <iostream>
#include <cstring>
using namespace std;
int len;
int f[110][4];
int last[30];
char s[110];
int main(){
    scanf("%s",s+1);
    len=strlen(s+1);
    //f[0][i]=0;f[i>=1][0]=1
    for (int i=1;i<=len;i++)    f[i][0]=1;
    for (int i=1;i<=len;i++){
        int c=s[i]-'a';
        for (int j=1;j<=i-1 && j<=3;j++){
            if (i-1!=j)
                f[i][j]=f[i-1][j]+f[i-1][j-1];//不动i时，至少有1种，不能前面是0,后面就不算了
            else 
                f[i][j]=1+f[i-1][j-1];
            if (last[c] && j>=i-last[c]){
                if (j!=i-1)
                f[i][j]-=f[last[c]-1][j-(i-last[c])];
                else 
                    f[i][j]-=1;
            }//对前面进行删除,有多少种不同的，就重复了多少个（找到相同的，那么后面的一串即对是否不同无影响）
        }
        last[c]=i;
        //只记录最近的，若以更前面的c结尾，其实就是last时[llast,last)删了。（若llast没被删，则x的数量肯定不对,所以以last结尾的包含以llast结尾的情况，并且更多）
        //递归下去，可证last就是最多的包含所有的那种，所以这里用last其实是包含所有可以取到的前面的x之和（x的数量在变->近似x的位置在变）
    }
    cout<<f[len][0]+f[len][1]+f[len][2]+f[len][3];
}
//若是单单求长度为n的不同序列最多有多少个,则为O(len*n*c),dp从长度为1开始,每个位置加上前面与之不同的结尾的子序列的数量（因为后面一定包括前面）
//且将前面的结尾的最大值记录下来，然后查询'a'-(tail-1),(tail+1)-'z'的和(线段树)
//c约等于(log26+1)*2,就是可以查两边，或者先更新，再查全部-tail的数量