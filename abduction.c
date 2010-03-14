#include <stdio.h>
#define MOD 10000000
int main(int argc, char **argv)
{
    int w,h,n,i,x,y,dir;
    char str[10010];
    int xp[1010] = {0};
    int yp[1010] = {0};
    scanf("%d%d%d\n", &w, &h, &n);w++;h++;
    fgets(str, 10010, stdin);
    xp[0]=yp[0]=1;
    dir = str[0]=='L' ? 0 : 1;
    for(i = 0; i < n+1; i++) {
        int subsum = 0;
        if(dir==0) {
            for(x = 0; x < w; x++) {
                int t = xp[x];
                xp[x] = subsum;
                subsum += t;
                subsum %= MOD;
            }
        } else if(dir==1) {
            for(y = 0; y < h; y++) {
                int t = yp[y];
                yp[y] = subsum;
                subsum += t;
                subsum %= MOD;
            }
        } else if(dir==2) {
            for(x = w-1; x >= 0; x--) {
                int t = xp[x];
                xp[x] = subsum;
                subsum += t;
                subsum %= MOD;
            }
        } else if(dir==3) {
            for(y = h-1; y >= 0; y--) {
                int t = yp[y];
                yp[y] = subsum;
                subsum += t;
                subsum %= MOD;
            }
        }
        if(str[i]=='L') {
            dir=(dir+1)%4;
        } else if(str[i]=='R') {
            dir=(dir+3)%4;
        } else {
            break;
        }
    }
    printf("%lld\n", (((long long)xp[w-1])*yp[h-1])%MOD);
    return 0;
}

