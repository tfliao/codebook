
/*
 * edges are vector of map
 *    source vertex -> dest vertex -> cost of edge
 *    * will be modified during iterations
 *    * not allow multiple edge between same pair of vertex
 */
vector<map<int, int>> edges;

/*
 * dijkstra(S, T, N, trace):
 *     retrun minimal cost from S to T in total N vertex graph
 *            trace[] keep last vertex of each vertex in shortest path
 */
int dijkstra(int S, int T, int N, vector<int>& trace) {
    vector<int> mcost(N, INF);
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
        for(auto it : edges[n]) {
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
 * mincost_maxflow(S, T, N):
 *     retrun minimal total cost of from S to T
 */
int mincost_maxflow(int S, int T, int N)
{
    int flow;
    int total_cost = 0;
    vector<int> trace;
    while((flow=dijkstra(S, T, N, trace)) != INF) {
        total_cost += flow;
        int prev, now;
        now = T;
        while (now != S) {
            prev = trace[now];
            int weight = edges[prev][now];
            edges[now][prev] = -weight;
            edges[prev].erase(now);
            now = prev;
        }
    }
    return total_cost;
}