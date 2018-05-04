#include <stdio.h>
#include <string.h>

#define MAXN 105

int main()
{
    int T = 0;
    char s[MAXN];
    scanf("%d", &T);

    while(T--) {
        int score = 0;
        int j = 0;
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            if(s[i] == 'O') {
                j++;
                score += j;
            } else { //'X'
                j = 0;
            }
        }
        printf("%d\n", score);
    }
}
