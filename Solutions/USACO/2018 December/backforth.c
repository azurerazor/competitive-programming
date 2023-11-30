#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool values[2001];
int perm[4];

int one[10];
bool oneU[10];
int two[10];
bool twoU[10];

void recurse(int count) {
    if (count == 4) {
        values[1000 - perm[0] + perm[1] - perm[2] + perm[3]] = true;
    } else {
        if (count % 2 == 0) {
            if (count != 0) {
                perm[count] = perm[count-1];
                recurse(count+1);
            }

            for (int i = 0; i < 10; i++) {
                if (oneU[i]) continue;
                oneU[i] = true;
                perm[count] = one[i];
                recurse(count+1);
                oneU[i] = false;
            }
        } else {
            perm[count] = perm[count-1];
            recurse(count+1);

            for (int i = 0; i < 10; i++) {
                if (twoU[i]) continue;
                twoU[i] = true;
                perm[count] = two[i];
                recurse(count+1);
                twoU[i] = false;
            }
        }
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    for (int i = 0; i < 10; i++) {
        scanf("%i", &one[i]);
        oneU[i] = 0;
    }

    for (int i = 0; i < 10; i++) {
        scanf("%i", &two[i]);
        twoU[i] = 0;
    }

    for (int i = 0; i <= 2000; i++) {
        values[i] = 0;
    }

    for (int i = 0; i < 4; i++) {
        perm[i] = 0;
    }

    recurse(0);

    int ans = 0;

    for (int i = 0; i <= 2000; i++) {
        ans += values[i];
    }

    printf("%i\n", ans);
}
