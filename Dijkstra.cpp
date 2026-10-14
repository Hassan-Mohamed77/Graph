int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<long long> dist(n, 1e18);
    vector<int> par(n, -1);
    priority_queue<pair<long long, int>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        d = -d;
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.emplace(-dist[v], v);
            }
        }
    }
    if (dist[n - 1] == 1e18)
    {
        cout << -1;
        return 0;
    }
    int v = n - 1;
    vector<int> path;
    while (v != -1)
    {
        path.emplace_back(v);
        v = par[v];
    }
    reverse(path.begin(), path.end());
    for (auto u : path)
        cout << u + 1 << ' ';
    return 0;
}