#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    char * s = (char*)calloc(60, sizeof(char));
    scanf("%s", s);

    int start[26], end[26];
    for (int i = 0; i< 26; i++) {
        start[i] = end[i] = -1;
    }

    for (int i = 0; i < 52; i++) {
        int letter = (int) (s[i] - 'A');
        if (start[letter] != -1) end[letter] = i;
        else start[letter] = i;
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) continue;
            if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]) ans++;
        }
    }

    printf("%i\n", ans);
}