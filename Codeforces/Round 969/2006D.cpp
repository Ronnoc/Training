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

const int N = 100005;
int b[N];
int ql[N], qr[N], ans[N];
int currAns = 0;

int low[N], high[N];

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        int block_a = l / 320;
        int block_b = other.l / 320;
        if (block_a != block_b)
            return block_a < block_b;
        return r < other.r;
    }
} queries[N];

void add(int idx, int k) {
}

void remove(int idx, int k) {
    int val = b[idx];
}

void solve() {
    int n, q, k;
    cin >> n >> q >> k;

    int sk = 1;
    while (sk * sk < k)
        sk++;
    sk++;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    rep(j, 1, sk) rep(i, 0, n + 1)
    {
        low[j][i] = 0;
        high[j][i] = 0;
    }

    for (int i = 0; i < q; i++) {
        cin >> ql[i] >> qr[i];
        queries[i] = {ql[i], qr[i], i};
    }

    sort(queries, queries + q);

    int L = 1, R = 0;
    for (int i = 0; i < q; i++) {
        int left = queries[i].l, right = queries[i].r;
        while (R < right) add(++R, k);
        while (R > right) remove(R--, k);
        while (L < left) remove(L++, k);
        while (L > left) add(--L, k);
        ans[queries[i].idx] = currAns;  // Store the answer for this query
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

void solve()
{
    rep(i, 1, q + 1)
    {
        RI(ql[i]);
        RI(qr[i]);
        int ans = 0;
        // cerr << "q?" << ql[i] << " " << qr[i] << endl;
        int d = qr[i] - ql[i] + 1;
        rep(j, 2, sk)
        {
            // x < j
            int il = j - 1;
            // while (il * j > k) il--;
            int cnt_l = low[il][qr[i]] - low[il][ql[i] - 1];
            // x * j > k
            int cnt_h = high[j][qr[i]] - high[j][ql[i] - 1];
            // cerr << "sk?" << j << ": " << "x<=" << il << ":" << cnt_l << " x*" << j << ">" << k << ":" << cnt_h << endl;
            if (cnt_h + cnt_l < d)
                ans = max(ans, (cnt_h - cnt_l + 1) / 2);
            else
            {
                ans = max(ans, (cnt_h - cnt_l) / 2);
            }
        }
        if (i != 1)
            cout << " ";
        cout << ans;
    }
    cout << endl;
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
