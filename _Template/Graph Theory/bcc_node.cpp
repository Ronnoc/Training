const int N = 10000 + 5;
const int M = 100000 + 5;

int dfn[N],low[N],head[N],etot,btot,n,m,nq,belong[N];
bool is_cut[N],visited[N];
std::stack<int> stack;
struct Edge {
    int v,next,belong;
    bool visited,is_cut;
}g[M<<1];

std::vector<int> edges[N+M];

void add_edge(int u,int v) {
    g[etot].belong = -1; g[etot].visited = g[etot].is_cut = false;
    g[etot].v = v; g[etot].next = head[u]; head[u] = etot ++;
}

void tarjan(int u,int root,int tim) {
    dfn[u] = low[u] = tim;
    visited[u] = true;
    int child_count = 0;
    for (int i = head[u]; i != -1; i = g[i].next) {
        Edge &e = g[i];
        if (e.visited) continue;
        stack.push(i);
        g[i].visited = g[i^1].visited = true;
        if (visited[e.v]) {
            low[u] = std::min(low[u],dfn[e.v]);
            continue;
        }
        tarjan(e.v,root,tim+1);
        g[i].is_cut = g[i^1].is_cut = (low[e.v]>dfn[u] || g[i].is_cut);
        if (u!=root) is_cut[u] |= (low[e.v]>=dfn[u]);
        if (low[e.v]>=dfn[u] || u==root) {
            while (true) {
                int id = stack.top(); stack.pop();
                g[id].belong = g[id^1].belong = btot;
                if (id==i) break;
            }
            btot ++;
        }
        low[u] = std::min(low[e.v],low[u]);
        child_count ++;
    }
    if (u==root && child_count>1) is_cut[u] = true;
}

void bcc() {
    for (int i = 0; i < n; ++ i) {
        dfn[i] = 0;
        is_cut[i] = false;
        visited[i] = false;
    }
    btot = 0;
    for (int i = 0; i < n; ++ i) {
        if (!visited[i]) {
            tarjan(i,i,1);
        }
    }
}

void build() {
    std::fill(edges,edges+n+m,std::vector<int>());
    for (int u = 0; u < n; ++ u) {
        if (is_cut[u] || head[u]==-1) {
            int id = btot ++;
            belong[u] = id;
            for (int i = head[u]; i != -1; i = g[i].next) {
                Edge &e = g[i];
                int v = e.belong;
                edges[id].push_back(v);
                edges[v].push_back(id);
            }
        }
    }
    for (int u = 0; u < btot; ++ u) {
        std::sort(edges[u].begin(),edges[u].end());
        edges[u].erase(std::unique(edges[u].begin(),edges[u].end()),edges[u].end());
    }
    for (int i = 0; i < m; ++ i) {
        int u = g[i<<1].v;
        int v = g[i<<1|1].v;
        if (!is_cut[u]) belong[u] = g[i<<1].belong;
        if (!is_cut[v]) belong[v] = g[i<<1].belong;
    }
}

int main() {
    while (scanf("%d%d",&n,&m)==2) {
        std::fill(head,head+n,-1); etot = 0;
        for (int i = 0; i < m; ++ i) {
            int a,b;
            scanf("%d%d",&a,&b); a --; b --;
            add_edge(a,b);
            add_edge(b,a);
        }
        bcc();
        build();
    }
    return 0;
}
