/*
 * dijkstra(S, T, N, G, trace):
 *     S: source vertex
 *     T: target vertex
 *     N: number of vertex
 *     G: graph represented as edges, G[A][B] = C, implies there is edges from A to B with cost C
 *     trace: trace back array for dijkstra
 *     retrun minimal cost from S to T in total N vertex graph
 *            trace[] keep last vertex of each vertex in shortest path
 */
int dijkstra(int S, int T, int N, const vector<map<int, int>>& G, vector<int>& trace) {
    vector<int> mcost(N, numeric_limits<int>::max());
    vector<bool> v(N, false);
    trace.assign(N, -1);

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(-0, S));
    mcost[S] = 0;
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int n = p.second;
        int c = -p.first;
        if (c != mcost[n]) continue;
        if (n == T) break;
        for(auto it : G[n]) {
            int nx = it.first;
            int w = it.second;
            int nc = c + w;
            if (nc < mcost[nx]) {
                mcost[nx] = nc;
                trace[nx] = n;
                pq.push(make_pair(-nc, nx));
            }
        }
    }
    return mcost[T];
}

/*
 * mincost_maxflow(S, T, N, G):
 *     G: graph represented as edges, G[A][B] = C, implies there is edges from A to B with cost C
 *        > will be modified during iterations
 *        > not allow multiple edge between same pair of vertex
 *     retrun minimal total cost of from S to T on graph G
 */
int mincost_maxflow(int S, int T, int N, vector<map<int, int>>& G)
{
    int flow;
    int total_cost = 0;
    vector<int> trace;
    while((flow=dijkstra(S, T, N, G, trace)) != numeric_limits<int>::max()) {
        total_cost += flow;
        int prev, now;
        now = T;
        while (now != S) {
            prev = trace[now];
            int weight = G[prev][now];
            G[now][prev] = -weight;
            G[prev].erase(now);
            now = prev;
        }
    }
    return total_cost;
}