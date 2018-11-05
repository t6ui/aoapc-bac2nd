#include <stdio.h>
#include <string.h>

int main() {
    int count = 0;
    char puzzle[10][10];
    int serial[10][10];
    int m, n; //index of puzzle[][]
    char word[10];
    int w = 0; //index of work[]
    int k; //serial number
    char c;
    bool con = false;
    bool keep;
    scanf("%d", &m);
    if (m != 0) {
        con = true;
    }
    while(con) {
        count++;
        printf("puzzle #%d:\n", count);

        scanf("%d", &n);

        //get square
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if((c = getchar()) == '\n')
                    c = getchar();
                puzzle[i][j] = c;
            }

        k = 1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if (puzzle[i][j] != '*' &&
                        (i < 1 || j < 1 || puzzle[i-1][j] == '*' || puzzle[i][j-1] == '*'))
                    serial[i][j] = k++;
                else
                    serial[i][j] = 0;
            }

        /* for(int i = 0; i < m; i++) { */
        /*     for(int j = 0; j < n-1; j++) */
        /*         printf("%2d ", serial[i][j]); */
        /*     printf("%2d\n", serial[i][n-1]); */
        /* } */

        printf("Across\n");
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n;) {
                w = 0;
                memset(word, 0, sizeof(word));
                while(j < n && (c = puzzle[i][j++]) != '*'){
                    if(w == 0)
                        k = serial[i][j - 1];
                    word[w++] = c;
                }
                if(word[0] != 0)
                    printf("%3d.%s\n", k, word);
            }
        }

        printf("Down\n");
        for(int h = 0; h < m; h++) {
            for(int j = 0; j < n; j++) {
                keep = false;
                for(int i = 0; i < m;) {
                    w = 0;
                    memset(word, 0, sizeof(word));
                    while(i < m && (c = puzzle[i++][j]) != '*') {
                        if(w == 0) {
                            k = serial[i -1][j];
                            if((i - 1) == h) {
                                keep = true;
                            }
                        }
                        word[w++] = c;
                    }
                    if(word[0] != 0 && keep) {
                        printf("%3d.%s\n", k, word);
                        break;
                    }
                }
            }
        }

        scanf("%d", &m);
        if (m != 0) {
            con = true;
            printf("\n");
        } else {
            con = false;
        }
    }
}
