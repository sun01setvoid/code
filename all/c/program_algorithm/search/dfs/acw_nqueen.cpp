#include <stdio.h>
int n,st[9],rt[17],lt[17];//斜线用他的截距来表示
char mp[9][9];
void dfs(int r){
    if (r==n)
        {
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++)
                    printf("%c",mp[i][j]);
                printf("\n");
            }//也可以图开大点一次输出一行
            printf("\n");
            return;
        }
    for (int i=0;i<n;i++){
        if (!st[i] && !rt[r+i] && !lt[i-r+n-1]){
            mp[r][i]='Q';
            st[i]=rt[r+i]=lt[i-r+n-1]=1;
            dfs(r+1);
            mp[r][i]='.';
            st[i]=rt[r+i]=lt[i-r+n-1]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            mp[i][j]='.';
    dfs(0);
}