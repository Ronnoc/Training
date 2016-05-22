//kybconnor
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
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
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
const int MAX_N = 22;
LL primeMOD[MAX_N],M[MAX_N],m[MAX_N],r[MAX_N];
LL A,K;
LL b[MAX_N],p[MAX_N],c[MAX_N];
LL extGcd (LL a,LL b,LL &x,LL &y) {
	LL ret=a;
	if (b) {
		ret+=extGcd (b,a%b,y,x);
		y-= (a/b) *x;
	} else x=1,y=0;
	return ret;
}
LL modInv (LL a,LL m) {
	LL x,y;
	extGcd (a,m,x,y);
	return (m+x%m) %m;
}
LL llpow (LL a,LL x,LL m) {
	LL ret=1;
	while (x) {
		if (x&1) ret=ret*a%m;
		a=a*a%m;
		x/=2;
	}
	return ret;
}
LL gaotwo (LL d,LL P,LL c,LL p) {
	if (d&1) return 0;
	return llpow (P,c-1,p);
}
LL dengbi (LL q,LL n,LL m) {
	if (n==0) return 1;
	if (n==1) return (q+1) %m;
	LL nn=n&1?n/2:n/2-1;
	LL tp=dengbi (q,nn,m);
	LL ret= (n&1) ?
					(tp+llpow (q,nn+1,m) *tp%m) %m
					: (1+q*tp%m+llpow (q,nn+2,m) *tp%m) %m;
	return ret;
}
LL gao (LL d,LL P,LL c,LL p) {
	if (P==2&&c>=3) return gaotwo (d,P,c,p);
	int i;
	for (i=2;; i++) if (llpow (i,P-1,P) ==1) break;
	LL g=i;
	return dengbi (llpow (g,d,p),p-p/P-1,p);
}
LL play (LL d,LL n,LL p,LL c,LL m) {
	LL ret=0;
	int i;
	for (i=1; i<=n%m; i++) ret+=llpow (i,d,m);
	LL tp=gao (d,p,c,m);
	return (ret+n/m*tp) %m;
}
void solve() {
	int T,i,j,t;
	scanf ("%d",&T);
	for (t=1; t<=T; t++) {
		scanf ("%I64d%I64d",&A,&K);
		K++;
		for (i=0; i<K; i++) scanf ("%I64d%I64d%I64d",&b[i],&p[i],&c[i]);
		LL N=0;
		for (i=0; i<K; i++) {
			primeMOD[i]=1;
			LL tp=c[i];
			while (tp--) primeMOD[i]*=p[i];
		}
		LL MOD=1LL;
		for (i=0; i<K; i++) MOD*=primeMOD[i];
		for (i=0; i<K; i++) m[i]=MOD/primeMOD[i];
		for (i=0; i<K; i++) M[i]=modInv (m[i],primeMOD[i]);
		for (i=0; i<K; i++) r[i]=b[i];
		for (int i=0; i<K; i++)
			N= ( (N+m[i]*M[i]%MOD*r[i]%MOD) %MOD+MOD) %MOD;
		if (N==0) N+=MOD;
		for (i=0; i<K; i++)
			r[i]=play (A,N,p[i],c[i],primeMOD[i]);
		LL ans=0;
		for (int i=0; i<K; i++)
			ans= ( (ans+m[i]*M[i]%MOD*r[i]%MOD) %MOD+MOD) %MOD;
		printf ("Case %d: %I64d\n",t,ans);c[i]);
//		}
	}
}
int main() {
	solve();
	return 0;
}
