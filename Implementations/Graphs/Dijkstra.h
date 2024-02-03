/*
* Source: https://cp-algorithms.com/graph/dijkstra_sparse.html
* Desc: single source shortest path from adjacency list in O((n + m)logn)
* Test: https://open.kattis.com/problems/shortestpath1
*/

#pragma once

vector<ll> dijkstra(vector<vector<pair<int, ll>>>& graph, int sp) {
    vector<ll> dist(graph.size(), 1e15);
    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, sp});
    dist[sp] = 0;

    while (pq.size()) {
        auto [d, c] = pq.top();
        pq.pop();

        if (d > dist[c]) continue;

        for (auto [t, w] : graph[c]) {
            if (dist[c] + w < dist[t]) {
                dist[t] = dist[c] + w;
                pq.push({dist[t], t});
            }
        }
    }

    return dist;
}
