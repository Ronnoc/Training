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
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
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
map<int,LL>fun;
int a[100005];
int kk[100005];
struct RMQ {
    int n;
    int st[20][100005];
    void init(int v[], int L) {
        int i, j, k;
    	for(i = 0; i < L+1; i++) kk[i] = 31 - __builtin_clz(i);
        n = L;
        for(i = 0; i <n; i++) st[0][i] = v[i];
        for(j = 1, k = 0; (1<<j) < n; j++, k++) {
            for(i = 0; i + (1<<j) - 1< n; i++) {
                st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1<<k)]);
            }
        }
    }
    int query(int l, int r) {   //求[l, r]
        int k = kk[r - l + 1];
        return __gcd(st[k][l], st[k][r - (1<<k) + 1]);
    }
};
void solve(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	RMQ rmq;
	rmq.init(a,n);
	fun.clear();
	rep(i,0,n){
		int pe=i,qe=n-1;
		while(qe>=pe){
			int aim=rmq.query(i,pe);
			int le=pe,re=qe,ge=-1;
			while(re>=le){
				int me=(re+le)/2;
				if(re-le<=1){
					if(rmq.query(i,re)==aim)
						ge=re;
					else ge=le;
					break;
				}
				if(rmq.query(i,me)==aim)le=me;
				else re=me;
			}
			fun[aim]+=ge-pe+1;
			pe=ge+1;
		}
	}
	int Q;
	scanf("%d",&Q);
	rep(i,0,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		int g=rmq.query(l-1,r-1);
		printf("%d %I64d\n",g,fun[g]);
	}
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d:\n",CA+1);
		solve();
	}
	return 0;
}