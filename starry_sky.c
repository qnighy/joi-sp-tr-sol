#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int n;
int l;
int maxcnt;
int xs[4000];
int ys[4000];
int ls[4000];
int ymap[4000];
int pts[8000];
int bit[1<<13];
int cmpint(const void *v0, const void *v1) {
    return *(const int*)v0-*(const int*)v1;
}
int cmpx(const void *v0, const void *v1) {
    int i0 = *(const int*)v0;
    int i1 = *(const int*)v1;
    int x0 = xs[i0>>1]+l*(i0&1);
    int x1 = xs[i1>>1]+l*(i1&1);
    return x0-x1 ? x0-x1 : (i0&1)-(i1&1);
}
int main(int argc, char **argv) {
    int i,j,k;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d%d%d", xs+i, ys+i, ls+i);
        ymap[i]=ys[i];
    }
    for(i = 0; i < n*2; i++) {
        pts[i]=i;
    }
    qsort(ymap, n, sizeof(*ymap), cmpint);
    maxcnt = 0;
    for(i = 0; i < n; i++) {
        l = ls[i];
        memset(bit, 0, sizeof(bit));
        qsort(pts, n*2, sizeof(*pts), cmpx);
        for(j = 0; j < n*2; j++) {
            int fac = pts[j]&1 ? -1 : 1;
            int y = ys[pts[j]>>1];
            int yy, yyy;
            int lo=-1, y0=n, y1=n;
            if(ls[pts[j]>>1]<l)continue;
            while(y0-lo>1) {
                int mid=(lo+y0)>>1;
                ymap[mid]<y ? (lo=mid) : (y0=mid);
            }
            while(y1-lo>1) {
                int mid=(lo+y1)>>1;
                ymap[mid]<y+l+1 ? (lo=mid) : (y1=mid);
            }
            yy = y0+(1<<12);
            while(yy) {
                if(yy&1) {
                    bit[yy^1]-=fac;
                }
                if(yy<=1)break;
                yyy = bit[yy]<bit[yy^1] ? bit[yy^1] : bit[yy];
                bit[yy]-=yyy;
                bit[yy^1]-=yyy;
                bit[yy>>1]+=yyy;
                yy>>=1;
            }
            yy = y1+(1<<12);
            while(yy) {
                if(yy&1) {
                    bit[yy^1]+=fac;
                }
                if(yy<=1)break;
                yyy = bit[yy]<bit[yy^1] ? bit[yy^1] : bit[yy];
                bit[yy]-=yyy;
                bit[yy^1]-=yyy;
                bit[yy>>1]+=yyy;
                yy>>=1;
            }
            if(bit[1]>maxcnt)maxcnt=bit[1];
        }
    }
    printf("%d\n",maxcnt);
    return 0;
}

