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

#define N 10100
#define M 101000

int n, m, ind, ncnt;
struct node {
    int u, v, next;
}edge[M];
int last[N], tot;
int ans;
int belong[N], dfn[N], low[N], instack[N];
stack < int > sta;

void addedge(int u, int v) {
    edge[tot].u = u; edge[tot].v = v; edge[tot].next = last[u]; last[u] = tot++;
}

void Tarjan(int u, int prev) {
    low[u] = dfn[u] = ++ind;
    sta.push(u);
    instack[u] = 1;
    int v;
    for(int j = last[u]; j != -1; j = edge[j].next) {
        //if(j == prev) continue;
        v = edge[j].v;
        if(!dfn[v]) {
            Tarjan(v, j ^ 1);
            low[u] = min(low[u], low[v]);
        } else if(instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        ncnt++;
        int cnt = 0;
        do
        {
            cnt++;
            v = sta.top();
            instack[v] = 0;
            sta.pop();
            belong[v] = ncnt;
        }
        while(v != u);
        if(cnt > 1) {
            ans++;
        }
    }
}

int father[N];
int num[N], num1[N], g[N];
int getfa(int x) {
    if(x == father[x]) return x;
    else return (father[x] = getfa(father[x]));
}

int main() {
    int u, v;
    while(scanf("%d%d", &n, &m) != EOF) {
        tot = 0;
        memset(last, -1, sizeof(last));
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            //addedge(v, u);
        }
        for(int i = 1; i <= n; i++) father[i] = i;
        for(int i = 0; i < m; i++) {
            u = getfa(edge[i].u), v = getfa(edge[i].v);
            if(u != v) {
                father[u] = v;
            }
        }
        memset(num, 0, sizeof(num));
        memset(num1, 0, sizeof(num1));
        memset(g, 0, sizeof(g));
        for(int i = 1; i <= n; i++) {
            u = getfa(i);
            num[u]++;
            //g[u] = i;
        }
        memset(belong, -1, sizeof(belong));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(instack, 0, sizeof(instack));
        ind = 0; ncnt = 0;
        ans = 0;
        for(int i = 1; i <= n; i++)
        if(!dfn[i]) {
            while(!sta.empty()) sta.pop();
            Tarjan(i, -1);
        }
        for(int i = 1; i <= n; i++) {
            g[belong[i]] = getfa(i);
        }
        for(int i = 1; i <= n; i++) {
            if(num[g[i]] > 1) num1[g[i]]++;
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
            if(num1[i] == 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
/*
7 6
1 2
2 3
3 1
1 4
4 5
5 1

7 6
1 2
2 3
3 1
7 4
4 5
5 7
*/
