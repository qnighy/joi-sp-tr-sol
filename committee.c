#include <stdio.h>
#include <limits.h>

int s[100010];
int a[100010];
int main(int argc, char **argv)
{
    int n,i,m=INT_MIN;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d%d", s+i, a+i);
        s[i]--;
    }
    for(i = n-1; i >= 0; i--) {
        if(a[i]>m)m=a[i];
        if(i&&a[i]>0)a[s[i]]+=a[i];
    }
    printf("%d\n", m);
    return 0;
}

