#include <stdio.h>

int main(int argc, char **argv)
{
    int p,n,i,j,cnt;
    int expmap[10000];
    int zcount[10000] = {0};
    freopen("fermat.in","r",stdin);
    scanf("%d%d", &p, &n);
    for(i = 0; i < p; i++) {
        int x=1;
        for(j=16; j>=0; j--) {
            x=(x*x)%p;
            if((n>>j)&1) x=(x*i)%p;
        }
        expmap[i]=x;
        zcount[x]++;
    }
    cnt=0;
    for(i = 0; i < p; i++) {
        cnt+=zcount[expmap[i]];
    }
    for(i = 0; i < p; i++) {
        cnt+=zcount[(expmap[i]+1)%p]*(p-1);
    }
    printf("%d\n", cnt);
    return 0;
}

