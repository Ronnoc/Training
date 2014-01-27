#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define BGN begin()
#define ED end()
#define SZ size()
#define SORT(p) sort(p.BGN,p.ED)
#define CLR(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> PII;
typedef long long LL;
#define N 110
#define INF (1 << 20)

int n, f, m, d, S, T;
int last[10*N], tot;
struct node {
    int u, v, next, c;
}edge[8 * N * N];
int dis[10*N], cur[10*N], gap[10*N], pre[10*N];

void addedge(int u, int v, int c) {
    edge[tot].u = u; edge[tot].v = v; edge[tot].c = c; edge[tot].next = last[u]; last[u] = tot++;
    edge[tot].u = v; edge[tot].v = u; edge[tot].c = 0; edge[tot].next = last[v]; last[v] = tot++;
}

int SAP(int s, int t, int n) {
    memset(dis, 0, sizeof(dis));
    memset(cur, 0, sizeof(cur));
    for(int i = 0;i < n; i++) cur[i] = last[i];
    memset(gap, 0, sizeof(gap));
    int v = s, maxflow = 0;
    gap[0] = n;
    while(dis[s] <= n) {
        //printf("%d\n", dis[s]);
        bool flag = false;
        for(int j = cur[v]; j != -1; j = edge[j].next)
        if( edge[j].c > 0 && dis[v] == dis[edge[j].v] + 1) {
            flag = true;
            pre[edge[j].v] = v;
            cur[v] = j;
            v = edge[j].v;
            break;
        }
        if(flag) {
            //printf("%d\n", dis[s]);
            if(v == t) {
                int det = INF;

                for(int j = v; j != s; j = pre[j])
                    det = min(det, edge[cur[pre[j]]].c);

                for(int j = v; j != s; j = pre[j]) {
                    edge[cur[pre[j]]].c -= det;
                    edge[cur[pre[j]] ^ 1].c += det;
                }

                maxflow += det;
                v = s;
            }
        }
        else {
            int mind = n;
            for(int j = last[v]; j != -1; j = edge[j].next)
            if(edge[j].c > 0 && dis[edge[j].v] < mind) {
                mind = dis[edge[j].v];
                cur[v] = j;
            }
            if((--gap[dis[v]]) == 0) break;
            gap[dis[v] = mind + 1] ++;
            if(v != s) v = pre[v];
        }
    }
    return maxflow;
}

int main() {
    int nf, nd, x;
    while(scanf("%d%d%d", &n, &f, &d) != EOF) {
        S = 0; T = f + d + n + n + 1;
        tot = 0;
        memset(last, -1, sizeof(last));
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &nf, &nd);
            for(int j = 0; j < nf; j++) {
                scanf("%d", &x);
                addedge(x, f + d + i, 1);
            }
            for(int j = 0; j < nd; j++) {
                scanf("%d", &x);
                addedge(f + d + n + i, f + x, 1);
            }
        }
        for(int i = 1; i <= n; i++) addedge(f + d +i, f + d + n +i, 1);
        for(int i = 1; i <= f; i++) addedge(S, i, 1);
        for(int i = 1; i <= d; i++) addedge(f + i, T, 1);
        printf("%d\n", SAP(S, T, T + 1));
    }
    return 0;
}
