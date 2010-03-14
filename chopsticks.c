#include <stdio.h>

int main(int argc, char **argv)
{
    int n,l,i,j,k;
    char str[310];
    int dp[310][310];
    scanf("%d\n", &n);
    fgets(str, 310, stdin);
    for(l = 1; l <= n; l++) {
        for(i = 0; i+l <= n; i++) {
            j = i+l;
            if(l==1) {
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=n*2;
            for(k = i+1; k <= j-1; k++) {
                if(dp[i][k]+dp[k][j]<dp[i][j]) {
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
                if(str[i]==str[k] && dp[i][k]+dp[k][j]-1<dp[i][j]) {
                    dp[i][j]=dp[i][k]+dp[k][j]-1;
                }
                if(str[k-1]==str[j-1] && dp[i][k]+dp[k][j]-1<dp[i][j]) {
                    dp[i][j]=dp[i][k]+dp[k][j]-1;
                }
            }
            /*printf("%d-%d: %d\n", i,j,dp[i][j]);*/
        }
    }
    printf("%d\n", dp[0][n]);
    return 0;
}

