#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 105
#define LEN 4

int main()
{
    int T = 0;
    char s[MAXN];
    const double value[] = {12.01, 1.008, 16.00, 14.01};
    const char atomic[] = {'C', 'H', 'O', 'N'};

    scanf("%d", &T);
    while(T--) {
        double sum = 0;
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len;) {
            char c = s[i++];
            int j = 0;
            while(j < LEN) {
                if (atomic[j] == c)
                    break;
                j++;
            }
            int k = 0;
            while(i < len && isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
                i++;
            }
            if (k == 0) {
                k = 1;
            }
            sum += k * value[j];
        }

        printf("%.3lf\n", sum);
    }
}
