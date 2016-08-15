#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
    LL ret=1;for(;b;b>>=1){
        if(b&1)ret=ret*a%MOD;a=a*a%MOD;
    }return ret;
}
//**NTT数论变换**
//>EternalReality

//g是p的原根,p为素数且len|p-1&&len=2^?
//998244353=119*2^23
const int p = 998244353, g = 3;
const int N = 1<<18;
LL pm(LL a, int n, int m = p) {
    LL r = 1;
    for (; n; n >>= 1, a = a * a % p)
        if (n & 1) r = r * a % p;
    return r;
}
int rb(int x, int m) {
    int r = 0;
    for (; m > 1; m >>= 1, x >>= 1)r = r << 1 | (x & 1);
    return r;
}
void ntt(int *a, int len) {
    for (int i = 0, j; i < len; ++i)
        if (i < (j = rb(i, len)))swap(a[i], a[j]);
    for (int m = 1; m < len ; m <<= 1) {
        LL w = 1; int w0 = pm(g, (p - 1) / m >> 1);
        for (int k = 0; k < len; k += (m << 1), w = 1)
            for (int j = 0; j < m; ++j , w = w * w0 % p) {
                int t = w * a[k + j + m] % p;
                a[k + j + m] = (a[k + j] + p - t) % p;
                a[k + j] = (a[k + j] + t) % p;
            }
    }
}
int wa[N], wb[N];
void conv(int *a, int *b, int *c, int len) {
    rep (i, 0,len) wa[i] = a[i], wb[i] = b[i];
    ntt(wa, len);
    ntt(wb, len);
    int inv = pm(len, p - 2);
    rep (i,0, len) c[i] = wa[i] * (LL)wb[i] % p * inv % p;
    reverse(c + 1, c + len);
    ntt(c, len);
}
const int MXN = N;
int a[MXN];
int le[MXN],re[MXN],ge[MXN];
LL tw[MXN];
LL ptw[MXN];
LL A[MXN];
LL inv[MXN];
LL pA[MXN];
int ans[MXN];
LL pre[MXN];
void solve(){
    DRI(n);
    rep(i,1,n+1)RI(a[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    pre[0]=0;
    rep(i,1,n+1)pre[i]=(pre[i-1]+a[i])%p;
    int len=1;
    while(n>>len)len++;
    len++;
    len=1<<len;
    rep(i,0,len)le[i]=0,re[i]=0;
    rep(t,0,n)le[t]=A[n-t-1]*a[n-t]%p;
    rep(t,0,n+1)re[t]=ptw[t]*pA[t]%p;
    conv(le,re,ge,len);
    rep(w,0,n)ans[n-w]=tw[w]*pA[n-w-1]%p*ge[w]%p;
    rep(k,2,n+1){
        ans[k]+=ans[k-1];
        ans[k]%=p;
    }
    rep(k,1,n+1)printf("%d ",ans[k]);
    printf("\n");
}
int main(){
    inv[1]=1;for(int i=2;i<=100000;i++)inv[i]=inv[p%i]*(p-p/i)%p;//MOD is prime
    A[0]=1;rep(i,0,100000)A[i+1]=A[i]*(i+1)%p;
    pA[0]=1;rep(i,0,100000)pA[i+1]=pA[i]*inv[i+1]%p;
    tw[0]=1;rep(i,0,100000)tw[i+1]=tw[i]*2%p;
    ptw[0]=1;rep(i,0,100000)ptw[i+1]=ptw[i]*inv[2]%p;
    int _T=1;
    scanf("%d",&_T);
    rep(CA,0,_T){
        //printf("Case #%d: ",CA+1);
        solve();
    }
    return 0;
}