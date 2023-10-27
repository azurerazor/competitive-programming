/*
* Source: KACTL
* Desc: Maintains union of disjoint sets in O(alpha(n)) amortized
* Test: N/A
*/

#pragma once

struct DSU {
    vector<int> s;
    int groups;
    DSU(int n) {s = vector<int>(n, -1); groups = n;}
    int find(int v) { return ((s[v] < 0) ? v : s[v] = find(s[v]));}
    int size(int v) { return -s[find(v)]; }
    
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b]; s[b] = a;
        groups--;
        return true;
    }
};
