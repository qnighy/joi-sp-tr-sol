#include <stdio.h>

int uf[10010];
int root(int x) {
    return uf[x]<0 ? x : (uf[x]=root(uf[x]));
}

int main(int argc, char **argv)
{
    int n,m,i,c;
    freopen("fiber.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) {
        uf[i]=-1;
    }
    c=n;
    for(i = 0; i < m; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        a=root(a-1);
        b=root(b-1);
        if(a!=b) {
            c--;
            uf[b]=a;
        }
    }
    printf("%d\n", c-1);
    return 0;
}

