#include <stdio.h>

int main(int argc, char **argv)
{
    int n,m,i;
    /* freopen("factorial.in","r",stdin); */
    scanf("%d", &n);
    m=0;
    for(i = 2; n>2; ++i,i|=1) {
        int c=0;
        if(n%i)continue;
        while(n%i==0) {
            n/=i;
            c++;
        }
        while(1) {
            int mc=m;
            int c_remain = c;
            while(mc>0) {
                mc/=i;
                c_remain -= mc;
            }
            if(c_remain<=0)break;
            m=m/i*i+i;
        }
    }
    printf("%d\n", m);
    return 0;
}

