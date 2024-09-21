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

VI G[200005];
char s[200005];
int vis[200005];
int fa[200005];
int son[200005];

void solve()
{
    DRI(n);
    rep(i, 0, n) G[i].clear();
    rep(i, 0, n) vis[i] = 0;
    rep(i, 0, n) fa[i] = -1;
    rep(i, 0, n) son[i] = 0;
    rep(i, 0, n - 1)
    {
        DRI(u);
        DRI(v);
        u--;
        v--;
        G[u].PB(v);
        G[v].PB(u);
    }
    scanf("%s", s);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : G[u])
        {
            if (vis[v])
                continue;
            vis[v] = 1;
            fa[v] = u;
            son[u]++;
            q.push(v);
        }
    }
    int totq = 0;
    rep(i, 1, n) if (s[i] == '?') totq++;
    int sq = 0;
    int s0 = 0;
    int s1 = 0;
    rep(i, 0, n) if (s[i] == '?' && son[i] == 0) sq++;
    rep(i, 0, n) if (s[i] == '0' && son[i] == 0) s0++;
    rep(i, 0, n) if (s[i] == '1' && son[i] == 0) s1++;
    totq -= sq;
    totq &=1;
    int ans = -1;
    if (s[0] == '?')
    {
        ans = max(s1 + sq / 2, s0 + sq / 2);
        if(totq){
            int tans = min(s1, s0) + (sq+1) / 2;
            ans = max(ans, tans);
        }
    }
    else if (s[0] == '0')
    {
        ans = s1 + (sq+1) / 2;
    }
    else
    {
        ans = s0 + (sq+1) / 2;
    }
    cout << ans << endl;
}

int main()
{
    int i, j, k, _T = 1;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        // printf("Case #%d:", CA);
        solve();
    }
    fflush(stdout);
    return 0;
}