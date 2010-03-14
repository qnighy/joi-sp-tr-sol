#include <stdio.h>
#include <string.h>

typedef long long int64_t;


int main(int argc, char **argv)
{
    int n,i,j;
    char str[22];
    char hist[256] = {0};
    int64_t sum = 0;
    int64_t curr = 1;
    freopen("anagram.in", "r", stdin);

    fgets(str, 22, stdin);
    n = strlen(str);
    str[--n]='\0';
    for(i = n-1; i >= 0; i--) {
        curr *= n-i;
        curr /= ++hist[str[i]];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < str[i]; j++) {
            if(hist[j]) {
                sum += curr*(hist[j])/(n-i);
            }
        }
        curr *= hist[str[i]]--;
        curr /= n-i;
    }
    printf("%lld\n", sum+1);
    return 0;
}

