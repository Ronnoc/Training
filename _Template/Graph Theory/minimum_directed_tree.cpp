// 固定根的最小树形图
// 对于无固定根最小树型图，只要虚拟一个根连所有的点的权为边权总和+1，最后的结果减去(边权总和+1)即可
// 点数开两倍以上

const int INF = 0x3f3f3f3f;
const int N = 1000 + 5;
const int M = 3000 + 5;

struct Edge {
    int u,v,cost;
    Edge(int u=0,int v=0,int cost=0) 
        :u(u),v(v),cost(cost) {}
}g[M];
int directedMST(int root,int n,int m) {
    static int pre[N],idx[M],f[N],inc[N];
    int ret = 0; int u,v;
    while (true) {
        std::fill(inc,inc+n,INF);
        for (int i = 0; i < m; ++ i) {
            u = g[i].u; v = g[i].v;
            if (g[i].cost<inc[v] && u!=v) {
                pre[v] = u;
                inc[v] = g[i].cost;
            }
        }
        for (int i = 0; i < n; ++ i) {
            if (i==root) continue;
            if (inc[i]==INF) return -1;
        }
        int circle = 0;
        std::fill(idx,idx+n,-1);
        std::fill(f,f+n,-1);
        inc[root] = 0;
        for (int i = 0; i < n; ++ i) {
            ret += inc[i];
            int v = i;
            while (f[v]!=i && idx[v]==-1 && v!=root) {
                f[v] = i;
                v = pre[v];
            }
            if (v!=root && idx[v]==-1) {
                for (int u = pre[v]; u != v; u = pre[u]) idx[u] = circle;
                idx[v] = circle ++;
            }
        }
        if (circle==0) break;
        for (int i = 0; i < n; ++ i) {
            if (idx[i]==-1) idx[i] = circle ++;
        }
        for (int i = 0; i < m; ++ i) {
            v = g[i].v;
            g[i].u = idx[g[i].u];
            g[i].v = idx[g[i].v];
            if (g[i].u!=g[i].v) {
                g[i].cost -= inc[v];
            }
        }
        n = circle;
        root = idx[root];
    }
    return ret;
}
