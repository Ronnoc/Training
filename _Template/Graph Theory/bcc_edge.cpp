const int N = 100000 + 5;

int ntot,head[N],etot,dfn[N],low[N],belong[N],stack[N],top,tot,tim,n,m;
struct Edge {
    int v,next;
} g[501000];

void add_edge(int u,int v) {
    g[etot].v = v; g[etot].next = head[u]; head[u] = etot ++;
}

void tarjan(int u,int pree) {
    dfn[u] = low[u] = ++tim;
    stack[top++] = u;
    for (int i = head[u]; i != -1; i = g[i].next) {
        int v = g[i].v;
        if ((pree^i) == 1) continue;
        if (!dfn[v]) tarjan(v,i);
        low[u] = std::min(low[u],low[v]);
    }
    if (dfn[u]==low[u]) {
        while (true) {
            int v = stack[--top];
            belong[v] = tot;
            if (v==u) break;
        }
        tot ++;
    }
}

void bcc() {
    tot = tim = top = 0;
    memset(dfn,0,sizeof(dfn));
    for (int i = 0; i < n; ++ i) {
        if (dfn[i] == 0) tarjan(i,-1);
    }
}
