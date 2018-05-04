#include <stdio.h>
#include <string.h>

int main()
{
    int counts[10] = {0};
    int T = 0;
    int value;
    scanf("%d", &T);
    while(T--) {
        memset(counts, 0, sizeof(counts));
        scanf("%d", &value);
        for(int i = 1; i <= value; i++) {
            int t = i;
            while(t) {
                counts[t % 10]++;
                t = t/10;
            }
        }
        for(int i = 0; i < 9; i++) {
            printf("%d ", counts[i]);
        }
        printf("%d\n", counts[9]);
    }
    return 0;
}
