#include <stdio.h>

int pts[100000];
int main(int argc, char **argv)
{
    int n,i;
    int hist[101] = {0};
    /* freopen("score.in","r",stdin); */
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", pts+i);
        hist[pts[i]]++;
    }
    for(i = 1; i < 101; i++) {
        hist[i] += hist[i-1];
    }
    for(i = 0; i < n; i++) {
        printf("%d\n", n+1-hist[pts[i]]);
    }
    return 0;
}

