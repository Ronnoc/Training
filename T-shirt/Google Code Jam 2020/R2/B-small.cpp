#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) \
    int(X);    \
    scanf("%d", &X)
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-9;
LL modPow(LL a, LL b, LL MOD)
{
    LL ret = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}
int c[105];
VPII G[105];        // full graph
int r[105], t[105]; // rank/time info
int done[105];
int res[1005];
void solve()
{
    DRI(C);
    DRI(D);
    memset(r, -1, sizeof r);
    memset(t, -1, sizeof t);
    memset(done, 0, sizeof done);
    memset(res,-1,sizeof res);
    rep(i, 2, C + 1)
    {
        RI(c[i]);
        if (c[i] > 0)
            t[i] = c[i];
        else
            r[i] = -c[i];
    }
    rep(i, 1, C + 1) G[i].clear();
    rep(i, 0, D)
    {
        DRI(x);
        DRI(y);
        G[x].PB(MP(y, i));
        G[y].PB(MP(x, i));
    }
    set<PII> SR, ST;
    done[1] = 1;
    t[1] = 0;
    for (auto e : G[1])
    {
        int v = e.AA;
        SR.insert(MP(r[v], v));
        ST.insert(MP(t[v], v));
    }
    int has = 1;
    int timenow = 0;
    while (!SR.empty())
    {
        int u;
        if ((*SR.OP).AA <= has)
        {
            PII sr = *SR.OP;
            u = sr.BB;
            SR.erase(SR.find(MP(r[u], u)));
            ST.erase(ST.find(MP(t[u], u)));
            if (r[u] < has)
                t[u] = timenow;
            else
                t[u] = timenow + 1;
            for (auto e : G[u])
            {
                int v = e.AA;
                int eid = e.BB;
                if (done[v])
                {
                    if (t[v] < t[u])
                        res[eid] = t[u] - t[v];
                }
                else
                {
                    SR.insert(MP(r[v], v));
                    ST.insert(MP(t[v], v));
                }
            }
        }
        else
        {
            PII st = *ST.OP;
            u = st.BB;
            SR.erase(SR.find(MP(r[u], u)));
            ST.erase(ST.find(MP(t[u], u)));
            for (auto e : G[u])
            {
                int v = e.AA;
                int eid = e.BB;
                if (done[v])
                {
                    if (t[v] < t[u])
                        res[eid] = t[u] - t[v];
                }
                else
                {
                    SR.insert(MP(r[v], v));
                    ST.insert(MP(t[v], v));
                }
            }
        }
        done[u] = 1;
        timenow = max(timenow, t[u]);
        has++;
    }
    rep(i, 0, D)
    {
        if (res[i] == -1)
            res[i] = 1000000;
        printf(" %d", res[i]);
    }
    printf("\n");
}

int main()
{
    int i, j, k, _T = 1;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d:", CA);
        solve();
    }
    return 0;
}