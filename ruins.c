#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int xs[128];
int ys[128];
int maxcnt = 0;
int l;
int pts[128];
int pts_size;
int dp[128][128];

int cmppt(const void *v0, const void *v1) {
    int i0 = *(const int*)v0;
    int i1 = *(const int*)v1;
    return (ys[i0]-ys[l])*(xs[i1]-xs[l])-(ys[i1]-ys[l])*(xs[i0]-xs[l]);
}

int main(int argc, char **argv) {
    int i,j,k;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d%d", xs+i, ys+i);
    }
    for(l = 0; l < n; l++) {
        pts_size = 0;
        for(i = 0; i < n; i++) {
            if(xs[i]>xs[l] || (xs[i]==xs[l] && ys[i]>ys[l])) {
                pts[pts_size++] = i;
            }
        }
        qsort(pts, pts_size, sizeof(*pts), cmppt);
        memset(dp, 0, sizeof(dp));
        for(j = 0; j < pts_size; j++) {
            dp[l][pts[j]]=2;
        }
        for(i = -1; i < pts_size; i++) {
            int ii = i==-1 ? l : pts[i];
            for(j = i+1; j < pts_size; j++) {
                int jj=pts[j];
                if(maxcnt<dp[ii][jj])maxcnt=dp[ii][jj];
                for(k = j+1; k < pts_size; k++) {
                    int kk=pts[k];
                    if(
                            (xs[ii]-xs[jj])*(ys[kk]-ys[jj])<
                            (xs[kk]-xs[jj])*(ys[ii]-ys[jj])) {
                        if(dp[jj][kk]<dp[ii][jj]+1)
                        dp[jj][kk]=dp[ii][jj]+1;
                    }
                }
            }
        }
    }
    printf("%d\n", maxcnt);
    return 0;
}

