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

#define N 1010
#define P 40100
#define K 1010
#define LEN 1000100
int n, p, k;
struct node {
    int u, v, l, next;
}edge[P];
int tot, last[N];
int dist[N], visit[N];
void addedge(int u, int v, int l) {
    edge[tot].u = u; edge[tot].v = v; edge[tot].l = l; edge[tot].next = last[u]; last[u] = tot++;
}

int spfa(int o) {
    queue < int > Q;
    while(!Q.empty()) Q.pop();
    memset(visit, 0, sizeof(visit));
    visit[1] = 1;
    Q.push(1);
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        visit[u] = 0;
        for(int j = last[u]; j != -1; j = edge[j].next) {
            int v = edge[j].v;
            int l = 0;
            if(edge[j].l > o) l = 1;
            if(dist[v] > dist[u] + l) {
                dist[v] = dist[u] + l;
                if(!visit[v]) {
                    visit[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
//    printf("%d    ", o);
//    for(int i = 0; i <= n; i++) printf("%d ", dist[i]);
//    putchar('\n');
    return dist[n];
}
int main() {
    int x, y, z;
    while(scanf("%d%d%d", &n, &p, &k) != EOF) {
        tot = 0;
        memset(last, -1, sizeof(last));
        for(int i = 0; i < p; i++) {
            scanf("%d%d%d", &x, &y, &z);
            addedge(x, y, z);
            addedge(y, x, z);
        }
        int L = 0, R = LEN, M;
        int len = LEN;
        while(L != R) {
            M = (L + R) / 2;
            len = spfa(M);
            if(len <= k) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        if(R == LEN) {
            printf("%d\n", -1);
        } else printf("%d\n", L);
    }
    return 0;
}

/*
4 6 0
1 2 6
2 4 9
1 3 7
3 4 8
1 2 12
1 3 14

4 4 0
1 2 1
2 3 2
3 1 3
1 2 4

4 6 1
1 2 6
2 4 9
1 3 7
3 4 8
1 2 12
1 3 14

4 6 3
1 2 6
2 4 9
1 3 7
3 4 8
1 2 12
1 3 14
*/
