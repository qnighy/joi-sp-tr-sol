#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int n,i;
    int newlen,count;
    char str[1000020];
    strcpy(str, "IO");
    scanf("%d\n", &n);
    fgets(str+2, sizeof(str)-2, stdin);
    strcpy(str+n+2, "OI");
    newlen = n;
    count = 0;
    for(i = 2; i < n+2; i++) {
        if(str[i-1]==str[i] && str[i]==str[i+1]) {
            str[i] = str[i]=='I' ? 'O' : 'I';
            count++;
        }
    }
    for(i = 1; i < n+4; i++) {
        if(str[i-1]==str[i]) {
            count++;
            newlen--;
        }
    }
    printf("%d\n%d\n", count, newlen);
    return 0;
}

