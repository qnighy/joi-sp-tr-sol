#include <stdio.h>

int main(int argc, char **argv)
{
    int m,k;
    int a,b,cs[200010],ds[200010];
    int ss=0;
    scanf("%d%d", &m, &k);
    a=0;
    b=1;
    cs[ss]=1;
    ds[ss]=1;
    ss++;
    while(ss>=1) {
        int c,d;
        c=cs[ss-1];d=ds[ss-1];
        if(b+d>m) {
            if(d==1)break;
            if(!--k) {
                printf("%d %d\n",c,d);
                return 0;
            }
            a=c; b=d;
            ss--;
        } else {
            cs[ss]=a+c;
            ds[ss]=b+d;
            ss++;
        }
    }
    printf("-1\n");
    return 0;
}

