#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int n,m,i,j;
    int hei[1000] = {0};
    int len[1000] = {0};

    /* freopen("building.in","r",stdin); */
    scanf("%d", &n);
    m = 0;
    for(i = 0; i < n; i++) {
        scanf("%d", hei+i);
        len[i]=1;
        for(j = 0; j < i; j++) {
            if(hei[j]<hei[i] && len[j]+1>len[i])len[i]=len[j]+1;
        }
        if(m<len[i])m=len[i];
    }
    printf("%d\n", m);
    return 0;
}

