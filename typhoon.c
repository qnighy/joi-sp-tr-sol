#include <stdio.h>
#include <stdlib.h>

struct qq {
    int id;
    int at;
    int pt;
    int fac;
};
int cmpqq(const void *v0, const void *v1) {
    return ((const struct qq*)v0)->pt - ((const struct qq*)v1)->pt;
}
int cmpint(const void *v0, const void *v1) {
    return *(const int*)v0-*(const int*)v1;
}

int bit[(1<<20)] = {0};
int main(int argc, char **argv) {
    int n,m,kk;
    int i,j,k;
    int as[100000];
    int bs[100000];
    struct qq qs[200000];
    int ptmap[300000];
    int ptmap_size = 0;
    int count[100000] = {0};
    scanf("%d%d%d", &n, &m, &kk);
    for(i = 0; i < n; i++) {
        scanf("%d%d", as+i, bs+i);
        bs[i]++;
        ptmap[ptmap_size++] = as[i];
        ptmap[ptmap_size++] = bs[i];
    }
    for(i = 0; i < m; i++) {
        int p,q,r;
        scanf("%d%d%d", &p, &q, &r);q--;
        qs[i*2  ].id = qs[i*2+1].id = i;
        qs[i*2  ].at = qs[i*2+1].at = p;
        qs[i*2  ].pt = q; qs[i*2  ].fac = -1;
        qs[i*2+1].pt = r; qs[i*2+1].fac = 1;
        ptmap[ptmap_size++] = p;
    }
    qsort(ptmap, ptmap_size, sizeof(*ptmap), cmpint);
    for(i = 1, j = 1; i < ptmap_size; i++) {
        ptmap[j] = ptmap[i];
        if(ptmap[j]!=ptmap[j-1])j++;
    } ptmap_size = j;

#define compress(pt) ((int*)bsearch(&(pt),ptmap,ptmap_size,sizeof(*ptmap),cmpint)-ptmap)
    for(i = 0; i < n; i++) {
        as[i] = compress(as[i]);
        bs[i] = compress(bs[i]);
    }
    for(i = 0; i < 2*m; i++) {
        qs[i].at = compress(qs[i].at);
    }
    qsort(qs, m*2, sizeof(*qs), cmpqq);
    for(i=0, j=0; ;) {
        if(j>=m*2) {
            break;
        } else if(qs[j].pt<=i || i>=n) {
            int subsum = 0;
            for(k = qs[j].at+(1<<19); k; k>>=1) {
                subsum += bit[k];
            }
            count[qs[j].id]+=subsum*qs[j].fac;
            j++;
        } else if(i<n) {
            for(k = as[i]+(1<<19); k; k>>=1) {
                if(k&1)bit[k-1]--;
            }
            for(k = bs[i]+(1<<19); k; k>>=1) {
                if(k&1)bit[k-1]++;
            }
            i++;
        }
    }
    for(i = 0; i < m; i++) {
        printf("%d\n", count[i]);
    }
    return 0;
}

