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

const int MXN = 200005;
int n, q, a[MXN], b[MXN], nb;
int ql[MXN], qr[MXN], ans[MXN];
int cnt[MXN];
int BLOCK_SIZE;
int odd_count = 0;

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
            return l < other.l;
        return (l / BLOCK_SIZE & 1) ? (r < other.r) : (r > other.r);
    }
};

vector<Query> queries;

void add(int idx) {
    cnt[b[idx]]++;
    if (cnt[b[idx]] % 2 == 1) odd_count++;
    else odd_count--;
}

void remove(int idx) {
    cnt[b[idx]]--;
    if (cnt[b[idx]] % 2 == 0) odd_count--;
    else odd_count++;
}

void mo_s_algorithm() {
    BLOCK_SIZE = static_cast<int>(sqrt(n));
    sort(queries.begin(), queries.end());

    int cur_l = 0, cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = (odd_count == 0);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> uniqa;
    for (int i = 0; i < n; i++) {
        if (uniqa.find(a[i]) == uniqa.end()) {
            uniqa[a[i]] = nb++;
        }
        b[i] = uniqa[a[i]];
    }

    queries.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> ql[i] >> qr[i];
        ql[i]--; qr[i]--;
        queries[i] = {ql[i], qr[i], i};
    }

    mo_s_algorithm();

    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }

    // Reset global variables for next test case
    queries.clear();
    memset(cnt, 0, sizeof(cnt));
    odd_count = 0;
    nb = 0;
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