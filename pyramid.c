#include <stdio.h>

short dp0[3010][3010] = {{0}};
short dp1[3010][3010] = {{0}};
short dp2[3010][3010] = {{0}};
int main(int argc, char **argv)
{
    int w,h,n,i,j,x,y;
    long long cnt;
    scanf("%d%d%d", &w, &h, &n);
    for(i = 0; i < n; i++) {
        int hh;
        scanf("%d%d%d", &x, &y, &hh);
        if(dp0[x][y]<hh)dp0[x][y] = hh;
    }
    for(j = 0; j < 4; j++) {
        for(x = 0; x < w; x++) {
            for(y = 0; y < h; y++) {
                short d=dp0[j&1?x:w-1-x][j&2?y:h-1-y];
                if(       x>0 && d<dp1[x-1][y  ]-1)d=dp1[x-1][y  ]-1;
                if(       y>0 && d<dp1[x  ][y-1]-1)d=dp1[x  ][y-1]-1;
                if(x>0 && y>0 && d<dp1[x-1][y-1]-1)d=dp1[x-1][y-1]-1;
                dp1[x][y]=d;
                if(dp2[j&1?x:w-1-x][j&2?y:h-1-y]<d)
                    dp2[j&1?x:w-1-x][j&2?y:h-1-y]=d;
            }
        }
    }
    cnt = 0;
    for(x = 0; x < w; x++) {
        for(y = 0; y < h; y++) {
            cnt += dp2[x][y];
        }
    }
    printf("%lld\n", cnt);
    return 0;
}

