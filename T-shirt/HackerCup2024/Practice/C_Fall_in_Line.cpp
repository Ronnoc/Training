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

void solve()
{
    DRI(n);
    VPII P;
    rep(i, 0, n)
    {
        DRI(x);
        DRI(y);
        P.PB(MP(x, y));
    }
    LL ans = 2;
    int cnt = min(20 * 1000000 / n, n);
    vector<pair<double, int>> TL;
    rep(i, 0, n)
    {
        TL.emplace_back(rand(), i);
    }
    sort(all(TL));
    rep(_i, 0, cnt)
    {
        if(_i%10==0)cerr<<_i<<" of "<<cnt<<endl;
        int i = TL[_i].second;
        int xi = P[i].first;
        int yi = P[i].second;
        map<pair<int, int>, int> Z;
        rep(j, 0, n)
        {
            if (i == j)
                continue;
            LL xj = P[j].first;
            LL yj = P[j].second;
            int dx = xi - xj;
            int dy = yi - yj;
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            Z[{dx, dy}]++;
        }
        for (auto &w : Z)
        {
            cmax(ans, w.second + 1LL);
        }
    }
    cout << n - ans << endl;
}

int main()
{
    int i, j, k, _T = 1;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d: ", CA);
        solve();
    }
    fflush(stdout);
    return 0;
}