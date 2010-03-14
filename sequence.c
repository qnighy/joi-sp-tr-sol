#include <stdio.h>

int main(int argc, char **argv)
{
    int m,mask,cyc,i;
    int cur = 0;
    int next_bit;
    int start;
    long long p,q,pm,qm,pqr,cnt;
    scanf("%d%lld%lld", &m, &p, &q);p--;
    mask = (1<<m)-1;
    for(i = 0; i < m; i++) {
        int a; scanf("%d", &a);
        cur |= (a&1)<<i;
    }
    start = cur;
    for(i = 0; ; i++) {
        if(i && start==cur) {
            cyc = i;
            break;
        }
        next_bit = (cur>>(m-1))^cur;
        next_bit&=1;
        cur = (cur>>1)^(next_bit<<(m-1));
    }
    pm = p%cyc;
    qm = q%cyc;
    pqr = q/cyc - p/cyc;
    cnt = 0;
    for(i = 0; i < cyc; i++) {
        if(i<pm)cnt-=cur&1;
        if(i<qm)cnt+=cur&1;
        cnt+=(cur&1)*pqr;

        next_bit = (cur>>(m-1))^cur;
        next_bit&=1;
        cur = (cur>>1)^(next_bit<<(m-1));
    }
    printf("%lld\n",cnt);
    return 0;
}

