#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n;
    scanf("%i %i", &k, &n);

    int ranks[k][n];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            scanf("%i", &a);
            ranks[i][--a] = j;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) continue;
            bool f = 1;
            for (int l = 0; l < k; l++) {
                if (ranks[l][i] > ranks[l][j]) f = 0;
            }
            ans += f;
        }
    }

    printf("%i\n", ans);
    return 0;
}
