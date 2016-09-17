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
const int MXN = 1<<17|1;
struct RMQ {
    int n;
    int st[17][MXN];
    void init(int v[], int L) {
        int i, j, k;
        n = L;
        for(i = 0; i <= n; i++) st[0][i] = v[i];
        for(j = 1, k = 0; (1<<j) <= n; j++, k++) {
            for(i = 0; i + (1<<j) - 1<= n; i++) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1<<k)]);
            }
        }
    }
    int query(int l, int r) {   //求[l, r]
        int k = 31 - __builtin_clz(r - l + 1);
        return min(st[k][l], st[k][r - (1<<k) + 1]);
    }
}rmq;
int a[100005];
int main(){
    DRI(T);while(T--){
        DRI(N);
        rep(i,1,N+1)RI(a[i]);
        rmq.init(a,N);
        DRI(M);
        while(M--){
            DRI(l);
            DRI(r);
            int id=l+1;
            int now=a[l];
            while(id<=r){
                int le=id,re=r,ge=-1;
                while(re>=le){
                    if(re-le<=1){
                        if(rmq.query(id, re)<=now)ge=re;
                        if(rmq.query(id, le)<=now)ge=le;
                        break;
                    }
                    int me=(le+re)/2;
                    if(rmq.query(id, me)<=now)re=me;
                    else le=me;
                }
                if(~ge){
                    now%=a[ge];
                    id=ge+1;
                }else {
                    break;
                }
            }
            printf("%d\n",now);
        }
    }
    return 0;
}