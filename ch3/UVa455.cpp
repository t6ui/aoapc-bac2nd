#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char s[81];
    char set[81];
    scanf("%d", &T);
    while(T--) {
        memset(set, 0, 81);
        scanf("%s", s);
        int len = strlen(s);
        set[0] = s[0];
        for(int i = 0; i < len; i++) {
            int n = strlen(set);
            int j = i % n;
            printf("%d %c\n", i, s[i]);
            printf("%d %c\n", j, set[j]);

            if (set[j] != s[i]) {
                for(int k = 0; k <= i; k++ )
                    set[k] = s[k];
            }
        }
        int size = strlen(set);
        if (len % size == 0) {
            printf("%d\n", size);
        } else {
            printf("%d\n", len);
        }
    }
}
