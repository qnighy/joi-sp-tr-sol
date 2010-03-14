#include <stdio.h>

#define MY_INF 10000

int main(int argc, char **argv)
{
    int m,n,a,b,x,y,minval;
    int table[1010][1010] = {{0}};
    freopen("mall.in","r",stdin);
    scanf("%d%d%d%d", &m, &n, &a, &b);
    minval=MY_INF*a*b;
    for(y = 0; y < n; y++) {
        for(x = 0; x < m; x++) {
            scanf("%d", &table[y][x]);
            if(table[y][x]==-1)table[y][x]=MY_INF;
        }
    }
    for(y = 0; y < n; y++) {
        int subsum = 0;
        for(x = 0; x <= m; x++) {
            int leaving = 0;
            if(x>=a) {
                leaving=table[y][x-a];
                table[y][x-a]=subsum;
            }
            if(x==m)break;
            subsum += table[y][x];
            subsum -= leaving;
        }
    }
    for(x = 0; x < m; x++) {
        int subsum = 0;
        for(y = 0; y <= n; y++) {
            int leaving = 0;
            if(y>=b) {
                leaving=table[y-b][x];
                table[y-b][x]=subsum;
            }
            if(y==n)break;
            subsum += table[y][x];
            subsum -= leaving;
        }
    }
    for(y = 0; y < n-b+1; y++) {
        for(x = 0; x < m-a+1; x++) {
            if(minval>table[y][x]) {
                minval=table[y][x];
            }
        }
    }
    printf("%d\n", minval);
    return 0;
}

