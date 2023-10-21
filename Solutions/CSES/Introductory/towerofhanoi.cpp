#pragma GCC optimize("Ofast")
 
#include <cstdio>
 
void hanoi(int n, int from, int to, int hold) {
    if (n == 1) {
        printf("%i %i\n", from, to);
        return;
    }
 
    hanoi(n - 1, from, hold, to);
    printf("%i %i\n", from, to);
    hanoi(n - 1, hold, to, from);
}
 
int main() {
    int disks;
    scanf("%i", &disks);
 
    int m = (1 << disks) - 1;
 
    printf("%i\n", m);
 
    hanoi(disks, 1, 3, 2);
 
    return 0;
}