#include <stdio.h>
#include <stdlib.h>


long long pts[2000000];
int cmpll(const long long *i0, const long long *i1) {
    return *i0==*i1 ? 0 : *i0>*i1 ? 1 : -1;
}
int main(int argc, char **argv)
{
    int n,a,b,i;
    int cnt,maxcnt,maxcntcnt;
    int ptssize=0;
    scanf("%d%d%d", &n, &a, &b);
    for(i = 0; i < n; i++) {
        int p,q,r,s;
        long long x,y;
        scanf("%d%d%d%d", &p, &q, &r, &s);
        p--; q--; r--; s--;
        for(x = p; x <= r; x++) {
            for(y = q; y <= s; y++) {
                pts[ptssize++]=x+y*a;
            }
        }
    }
    qsort(pts,ptssize,sizeof(*pts),(int(*)(const void*,const void*))cmpll);
    cnt = 0;
    maxcnt = 0;
    maxcntcnt = 0;
    for(i = 0; i < ptssize; i++) {
        cnt++;
        if(i+1==ptssize || pts[i]!=pts[i+1]) {
            if(cnt>maxcnt) {
                maxcnt = cnt;
                maxcntcnt = 0;
            }
            if(cnt==maxcnt) {
                maxcntcnt++;
            }
            cnt = 0;
        }
    }
    printf("%d\n%d\n", maxcnt, maxcntcnt);
    return 0;
}

