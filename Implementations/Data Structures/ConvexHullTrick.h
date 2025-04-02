/*
* Source: https://usaco.guide/plat/convex-hull-trick
* Desc: Computes min/max at point for a set of linear functions in O(n + q).
* Lines must be inserted in monotonic order of slopes, with increasing
* giving max value and decreasing giving min value. Try to avoid inserting
* two lines with the same slope. Queries must also be done in order of
* non-decreasing x.
* Test: https://codeforces.com/contest/311/problem/B
*/

#pragma once

template<class T>
struct Line {
    T m, b;
    Line(T m, T b) : m(m), b(b) {}
    T isect(const Line<T>& o) {
        return (o.b-b) / (m-o.m);
    }
};

template<class T>
struct CHT {
    deque<Line<T>> q;
    void insert(T m, T b) {
        Line<T> v(m, b);
        while (sz(q) > 1 && v.isect(q.back()) <= q.back().isect(q[sz(q)-2])) 
            q.pop_back();
        q.push_back(v);
    }
    T query(T x) {
        while (sz(q) > 1 && q[0].isect(q[1]) < x) 
            q.pop_front();
        auto [m, b] = q.front();
        return m * x + b;
    }
};
