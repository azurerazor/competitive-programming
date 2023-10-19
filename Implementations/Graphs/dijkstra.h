/*
* Source: https://cp-algorithms.com/graph/dijkstra_sparse.html, some UCF hackpack, some own code
* Desc: single source shortest path from adjacency list in O((n + m)logn)
* Test: https://open.kattis.com/problems/shortestpath1
*/

template<class T>
vector<T> dijkstra(vector<vector<pair<int, T>>>& graph, int sp) {
    vector<T> d(graph.size(), -1);
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, sp});
    d[sp] = 0;

    while (pq.size()) {
        int c = pq.top().second;
        int cd = pq.top().first;
        pq.pop();

        if (cd != d[c]) continue;

        for (auto [t, w] : graph[c]) {
            if (d[c] + w < d[t] || d[t] == -1) {
                d[t] = d[c] + w;
                pq.push({d[t], t});
            }
        }
    }

    return d;
}
