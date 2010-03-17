#include <stdio.h>
#include <string.h>
#define MY_MAX 1000000000

int dp0[380];
int dp1[380][3000];
int dp2[380][3000];
int main(int argc, char **argv) {
    int n,d;
    int i,j;
    scanf("%d%d", &n, &d);
    for(i = 0; i <= d; i++) {
        dp0[i] = MY_MAX;
        for(j = 0; j < n; j++) {
            dp1[i][j] = dp2[i][j] = MY_MAX;
        }
    }
    dp0[0] = 0;
    for(i = 0; i < d; i++) {
        for(j = 0; j < n; j++) {
            int prc,p2,p3; scanf("%d", &prc);
            p2=prc*9/10; p3=prc*7/10;
            if(dp1[i+1][j]>dp0[i]+prc)dp1[i+1][j]=dp0[i]+prc;
            if(dp2[i+1][j]>dp1[i][j]+p2)dp2[i+1][j]=dp1[i][j]+p2;
            if(dp2[i+1][j]>dp2[i][j]+p3)dp2[i+1][j]=dp2[i][j]+p3;
            if(dp0[i+1]>dp1[i+1][j])dp0[i+1]=dp1[i+1][j];
            if(dp0[i+1]>dp2[i+1][j])dp0[i+1]=dp2[i+1][j];
        }
    }
    printf("%d\n",dp0[d]);
    return 0;
}

