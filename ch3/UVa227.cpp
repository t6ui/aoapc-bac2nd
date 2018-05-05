#include <stdio.h>
#include <string.h>

int main() {
    char square[5][5];
    char moves[105];
    const int dm[] = {-1, 1, 0, 0};
    const int dn[] = {0, 0, -1, 1};
    int c;
    int m, n;
    int round = 0;
    bool con = false;
    if ((c = getchar()) != EOF && c != 'Z') {
        con = true;
    }
    while(con) {
        //get square
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++) {
                if(i == 0 && j == 0){
                    square[i][j] = c;
                    continue;
                }
                if((c = getchar()) == '\n')
                    c = getchar();
                square[i][j] = c;
            }

        //find "space" position
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if (square[i][j] == ' ') {
                    m = i;
                    n = j;
                    break;
                }

        //get moves string
        memset(moves, 0, sizeof(moves));
        for(int i = 0; (c = getchar()) != EOF;) {
            if(c == '0') {
                c = getchar();
                break;
            }
            if(c != '\n')
                moves[i++] = c;
        }
        /* printf("%s\n", moves); */

        //move
        int len = strlen(moves);
        int success = 1;
        for(int i = 0; i < len; i++) {
            int x, y, t;
            switch(moves[i]) {
                case 'A': t = 0; break;
                case 'B': t = 1; break;
                case 'L': t = 2; break;
                case 'R': t = 3; break;
            }
            x = m + dm[t];
            y = n + dn[t];
            if(x >= 0 && x <= 4 && y >= 0 && y <= 4) {
                square[m][n] = square[x][y];
                square[x][y] = ' ';
                m = x; n = y;
            } else {
                success = 0;
                break;
            }
        }

        //diplay
        printf("Puzzle #%d:\n", ++round);
        if(success) {
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 4; j++)
                    printf("%c ", square[i][j]);
                printf("%c\n", square[i][4]);
            }
        } else {
            printf("This puzzle has no final configuration.");
        }
        if ((c = getchar()) != EOF && c != 'Z') {
            con = true;
            printf("\n");
        } else {
            con = false;
        }
    }
}
