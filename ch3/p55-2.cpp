#include<stdio.h>
#include<string.h>
#define maxn 10000000 + 10

char s[maxn];
int main() {
    scanf("%s", s);
    int tot = 0;
    /* for(int i = 0; i < strlen(s); i++) */
    int len = strlen(s);
    for(int i = 0; i < len; i++)
        if(s[i] - '0' == 1) tot++;
    printf("%d\n", tot);
}
