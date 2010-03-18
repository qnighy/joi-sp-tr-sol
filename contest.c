#include <stdio.h>
#include <stdlib.h>

int cmpintd(const void *v0, const void *v1) {
    return *(const int*)v1-*(const int*)v0;
}

int cnt[3000];
int sum[3000];
int unks[6000]; int unks_size = 0;
int s1s[3000]; int s1s_size = 0;
int s2s[3000]; int s2s_size = 0;
int cksum[3000] = {0};
int ckcnt[3000] = {0};
int main(int argc, char **argv)
{
    int n,c,i;
    int lo,hi;
    scanf("%d%d", &n, &c);c--;
    for(i = 0; i < 2*n; i++) {
        int s,a;
        scanf("%d%d", &s, &a);a--;
        if(a==-1) {
            unks[unks_size++]=s;
        } else {
            ckcnt[a]++;
            cksum[a]+=s;
        }
    }
    for(i = 0; i < n; i++) {
        if(i==c) {
        } else if(ckcnt[i]==1) {
            s1s[s1s_size++] = cksum[i];
        } else if(ckcnt[i]==2) {
            s2s[s2s_size++] = cksum[i];
        }
    }
    qsort(unks, unks_size, sizeof(*unks), cmpintd);
    qsort(s1s, s1s_size, sizeof(*s1s), cmpintd);
    qsort(s2s, s2s_size, sizeof(*s2s), cmpintd);
    lo = -1; hi = n;
    while(hi-lo>1) {
        int x = (hi+lo)>>1;
        int unkidx = 0;
        int unkidx2;
        int s1idx = 0;
        int s1idx2;
        int j;
        int xi;
        char unkselect[6000] = {0};
        int cc = cksum[c];
        char flag = 1;
        for(j = 0; j < 2-ckcnt[c]; j++) {
            cc += unks[unkidx++];
        }
        xi = 0;
        for(j = 0; j < s2s_size; j++) {
            if(s2s[j]>cc)xi++;
        }
        if(xi>x)flag=0;
        for(; xi < x; xi++) {
            if(s1idx<s1s_size &&
                    (unks_size-unkidx<=s1s_size-s1idx ||
                    s1s[s1idx]>unks[unkidx+1])) {
                s1idx++; unkidx++;
            } else {
                unkidx+=2;
            }
        }
        unkidx2 = unkidx;
        for(s1idx2 = s1s_size-1; s1idx2 >= s1idx; s1idx2--) {
            while(unkidx2<unks_size && (unkselect[unkidx2] ||
                    unks[unkidx2]+s1s[s1idx2]>cc)) unkidx2++;
            if(unkidx2>=unks_size){flag=0;break;}
            unkselect[unkidx2]=1;
        }
        unkidx2 = unks_size-1;
        for(; unkidx < unkidx2; unkidx++) {
            if(unkselect[unkidx])continue;
            while(unkselect[unkidx2])unkidx2--;
            if(unkidx>=unkidx2)break;
            if(unks[unkidx]+unks[unkidx2]>cc){flag=0;break;}
            unkselect[unkidx2]=1;
        }
        if(flag) hi=x; else lo=x;
    }
    printf("%d\n", hi+1);
    return 0;
}

