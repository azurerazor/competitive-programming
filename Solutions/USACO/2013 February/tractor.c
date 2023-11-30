#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int a;
    int b;
    int cost;
} Edge;

int cmp(const void * a, const void * b) {
    Edge * ea = (Edge*) a;
    Edge * eb = (Edge*) b;
    return ea->cost - eb->cost;
}

int DSU[250000];
int DSUGroups = 0;

int initSet(int v) {
    DSU[v] = -1;
    DSUGroups++;
}

int findSet(int v) {
    if (DSU[v] < 0) return v;
    return DSU[v] = findSet(DSU[v]);
}

bool unionSets(int a, int b) {
    a = findSet(a); b = findSet(b);
    if (a == b) return false;
    if (DSU[a] > DSU[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    DSU[a] += DSU[b];
    DSU[b] = a;
    return true;
}

int main() {
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    int n;
    scanf("%i", &n);

    int grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%i", &grid[i][j]);
        }
    }

    Edge edges[2*n*n];
    int edgecnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i+1 < n) {
                edges[edgecnt].a = i*n+j;
                edges[edgecnt].b = (i+1)*n+j;
                edges[edgecnt].cost = abs(grid[i+1][j] - grid[i][j]);
                edgecnt++;
            }
            if (j+1 < n) {
                edges[edgecnt].a = i*n+j;
                edges[edgecnt].b = i*n+j+1;
                edges[edgecnt].cost = abs(grid[i][j+1] - grid[i][j]);
                edgecnt++;
            }
        }
    }

    qsort(edges, edgecnt, sizeof(Edge), cmp);

    for (int i = 0; i < n*n; i++) {
        initSet(i);
    }

    int ans = 0;
    for (int i = 0; i < edgecnt; i++) {
        if (unionSets(edges[i].a, edges[i].b)) {
            ans = edges[i].cost;
            if (abs(DSU[findSet(edges[i].a)]) >= (n*n+1)/2) break;
        }
    }

    printf("%i\n", ans);
    return 0;
}
