int n, m, p, k;
cin >> n >> m >> p >> k;
vector<vector<int>> adj(n + 1);

for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> who(n + 1, -1); // بتخزن المالك اللي بيملك النقطة x مثال
queue<int> q;

for (int i = 0; i < p; i++) {
    int pos;
    cin >> pos;
    if (who[pos] != -1) {
        continue;
    }
    q.push(pos);
    who[pos] = i; // اندكس
}

while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
        if (who[v] == -1) {
            q.push(v);
            who[v] = who[u];
        }
    }
}

while (k--) {
    int src;
    cin >> src;
    cout << who[src] + 1 << endl;
}  