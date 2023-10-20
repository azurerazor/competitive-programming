/*
 * Source: The C++ variant of this
 * Desc: Maintains union of disjoint sets in O(alpha(n)) amortized
 * Test: https://cses.fi/problemset/task/1676/
 */

import java.util.Arrays;

class DSU {
    int[] s;
    int groups;
    public DSU(int n) {
        s = new int[n];
        Arrays.fill(s, -1);
        groups = n;
    }
    int find(int v) {return (s[v] < 0) ? v : (s[v] = find(s[v]));};
    int size(int v) {return -s[find(v)];}

    boolean union(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) {
            int temp = b;
            b = a;
            a = temp;
        }
        s[a] += s[b];
        s[b] = a;
        groups--;
        return true;
    }
}
