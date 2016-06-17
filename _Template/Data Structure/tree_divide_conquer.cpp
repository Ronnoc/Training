const int N = 100000 + 5;
std::vector<int> edges[N];
int n;
bool vis[N];
int parent[N];
int sz[N];
int que[N];
int balance[N];

int bfs(int source,int fa = -1) {
    int qf = 0,qe = 0;
    que[qe++] = source;
    parent[source] = fa;
    while (qf != qe) {
        int u = que[qf++];
        sz[u] = 1;
        balance[u] = 0;
        for (int v : edges[u]) {
            if (!vis[v] && parent[u] != v) {
                parent[v] = u;
                que[qe++] = v;
            }
        }
    }
    for (int i = qe - 1; i > 0; -- i) {
        int u = que[i];
        sz[parent[u]] += sz[u];
        balance[parent[u]] = std::max(balance[parent[u]],sz[u]);
    }
    return qe;
}

void divide(int root) {
    int tot = bfs(root);
    for (int i = tot - 1; i > 0; -- i) {
        int u = que[i];
        balance[u] = std::max(balance[u],tot - sz[u]);
        if (balance[u] < balance[root]) {
            root = u;
        }
    }
    bfs(root);

    // balabalah

    vis[root] = true;
    for (int u : edges[root]) {
        if (!vis[u]) {
            divide(u);
        }
    }
}
