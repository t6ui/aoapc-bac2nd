#include <stdio.h>
#include <string.h>

int main() {
    int T, len, i, j;
    char s[81];
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        len = strlen(s);
        for(i = 1; i <= len; i++) {
            if(len % i == 0) {
                for(j = i; j <= len; j++)
                    if(s[j % i] != s[j])
                        break;
                if(j == len) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
        if(T) printf("\n");
    }
    return 0;
}
