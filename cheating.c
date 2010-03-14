#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int xs[100000];
unsigned int ys[100000];
int numcmp(const unsigned int *i0, const unsigned int *i1) {
    int ii0=*i0, ii1=*i1;
    return ii0==ii1 ? 0 : ii0<ii1 ? -1 : 1;
}
int main(int argc, char **argv)
{
    int n,m,i;
    unsigned int hi,lo;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++) {
        scanf("%u%u", xs+i, ys+i);
    }
    qsort(xs, m, sizeof(*xs), (int(*)(const void*,const void*))numcmp);
    qsort(ys, m, sizeof(*ys), (int(*)(const void*,const void*))numcmp);
    lo = -1;
    hi = 2000000005;
    while(hi-lo>1) {
        unsigned int d = (hi+lo)>>1;
        int x = 0;
        int y = 0;
        int cnt = 0;
        for(i = 0; i < m; i++) {
            if(x <= xs[i]) {
                x = xs[i]+d+1;
                cnt++;
            }
        }
        for(i = 0; i < m; i++) {
            if(y <= ys[i]) {
                y = ys[i]+d+1;
                cnt++;
            }
        }
        if(cnt<=n)
            hi = d;
        else
            lo = d;
    }
    printf("%d\n", hi);
    return 0;
}

