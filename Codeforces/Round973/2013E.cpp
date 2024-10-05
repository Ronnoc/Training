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

const int MAXN = 100005;
int p[MAXN];
int pre[MAXN];
int a[MAXN];
void solve()
{
    DRI(n);
    rep(i, 0, n) RI(a[i]);
    sort(a, a + n);
    rep(i,1,n)a[i]=gcd(a[i],a[0]);
    rep(i,0,n)cerr<<a[i]<<" ";cerr<<endl;
    LL ans = a[0];
    map<int,int>cnt;
    rep(i,1,n)cnt[a[i]]++;
    while(!cnt.empty()){
        int x = cnt.begin()->first;
        int y = cnt.begin()->second;
        ans += x;
        y--;
        if(y==0)cnt.erase(cnt.begin());
        else cnt[x]=y;
        map<int,int>ncnt;
        for(auto &w:cnt){
            int wf = w.first;
            int nwf = gcd(w.first,x);
            ncnt[nwf]+=w.second;
            // cerr<<wf<<" "<<w.second<<" "<<nwf<<endl;
        }
        // cerr<<"---"<<endl;
        cnt = ncnt;
    }
    cout << ans << endl;
}

int main()
{
    int i, j, k, _T = 1;
    memset(p, 0, sizeof(p));
    for (i = 2; i < MAXN; i++)
        if (!p[i])
            for (j = i + i; j < MAXN; j += i)
                p[j] = 1,pre[j]=i;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        // printf("Case #%d:", CA);
        solve();
    }
    fflush(stdout);
    return 0;
}