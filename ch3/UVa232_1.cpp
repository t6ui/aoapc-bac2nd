#include <stdio.h>
#include <string.h>

#define maxn 10
int kase = 0, r, c, cnt;
int xs[maxn*maxn + 10], ys[maxn*maxn + 10];
char frame[maxn+2][maxn+2];

void dispaly()
{
    printf("\nprint frame:\n");
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++)
            putchar(frame[i][j]);
        putchar('\n');
    }
    printf("\n");
}

void print_word(int k, int is_across)
{
    printf("%3d.", k);
    for(int x = xs[k], y = ys[k]; frame[x][y] != '*'; (is_across)?(y++):(x++))
        putchar(frame[x][y]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    while(scanf("%d%d", &r, &c) == 2 && r != 0) {
        memset(frame, '*', sizeof(frame));
        cnt = 0;

        getchar();
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++)
                frame[i][j] = getchar();
            getchar();
        }
        //dispaly();

        for(int i = 1; i <= r; i++) {
            for(int j = i; j <= c; j++) {
                if((frame[i][j] != '*') &&
                        (frame[i-1][j] == '*' || frame[i][j-1] == '*')) {
                    cnt++;
                    xs[cnt] = i;
                    ys[cnt] = j;
                }
            }
        }

        if(kase++)
            printf("\n");
        printf("puzzle #%d:\n", kase);
        printf("Across\n");
        for(int k = 1; k <= cnt; k++)
            if(frame[xs[k]][ys[k] -1] == '*')
                print_word(k,1);
        printf("Down\n");
        for(int k = 1; k <= cnt; k++)
            if(frame[xs[k] - 1][ys[k]]  == '*')
                print_word(k,0);
    }
    return 0;
}
