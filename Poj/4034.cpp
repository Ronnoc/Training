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
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 100000007;
const double eps = 1e-6;
#define OP begin()
#define ED end()
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SORT(L) sort(L.OP,L.ED)
LL extgcd(LL a,LL b,LL &x,LL &y) {
	LL ret=a;
	if(b) {
		ret=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	} else x=1,y=0;
	return ret;
}
LL modInv(LL a,LL m) {
	LL x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}
int s, p;
int a[360100];
int det[720100];
int next[360100];
bool match[720100];
void getnext(int T[], int lt, int next[]) {
	next[0] = -1; next[1] = 0;
	for(int i = 1, j = 0; i < lt;) {
		while(j != -1 && T[i] != T[j]) j = next[j];
		i++; j++;
		next[i] = j;
	}
//    for(int i = 0; i < lt; i++) printf("%d next %d\n", i, next[i]);
}
void KMP(int S[], int ls, int T[], int lt) {
	getnext(T, lt, next);
	for(int i = 0; i < ls; i++) match[i] = false;
	for(int i = 0, j = 0; i < ls; i++) {
		while(j != -1 && S[i] != T[j]) j = next[j];
		j++;
		if(j == lt) {
			j = next[j];
			match[i] = true;
		}
	}
}
LL cnt[360005];
LL AA[360005];
LL IV[360005];
LL play(LL m,int n) {
//	cout<<m<<"^"<<n<<endl;
	LL ret=1;
	while(n) {
		if(n&1)ret=ret*m%MOD;
		m=m*m%MOD;
		n/=2;
	}
	return ret;
	int i;
	for(i=0; i<=n&&i<=m; i++) {
		//Comb[m][i]*Comb[n][i]*i!
		LL add=IV[n-i]*IV[i]%MOD*IV[m-i]%MOD;
		ret+=add;
	}
	ret=ret*AA[n]%MOD;
	ret=ret*AA[m]%MOD;
	return ret;
}
int main() {
	int i, j;
	AA[0]=1;
	for(i=1; i<=360000; i++)AA[i]=AA[i-1]*i%MOD;
	for(i=0; i<=360000; i++)IV[i]=modInv(AA[i],MOD);
	while(scanf("%d%d", &s, &p) != EOF && s != -1 && p != -1) {
		for(i = 0; i < p; i++) scanf("%d", &a[i]);
		sort(a, a + p);
		a[p] = a[0] + 360000;
		for(i = 0; i < p; i++) {
			det[i + p] = det[i] = a[i + 1] - a[i];
		}
//		for ( i = 0; i < 2 * p; i++ ) printf( "%d det %d\n", i, det[i] );
		KMP(det, 2 * p, det, p);
//		for ( i = 0; i < 2 * p; i++ ) {
//			printf( "%d match %d\n", i, match[i] );
//		}
		for(i=1; i<=p; i++)cnt[i]=0;
		int all=0;
		for(i=p; i<2*p; i++)if(match[i]) {
				int l=__gcd(2*p-1-i,p);
//				cout<<i<<" "<<l<<endl;
				cnt[l]++;
				all++;
			}
//		for ( i=1; i<=p; i++ )if ( cnt[i] )
//				cout<<i<<"@ "<<cnt[i]<<"*"<<play( s,i )<<endl;
		LL ans=0;
		for(i=1; i<=p; i++)if(cnt[i])ans=(ans+cnt[i]*play(s,i))%MOD;
		ans*=modInv(all,MOD);
		ans%=MOD;
		cout<<ans<<endl;
	}
	return 0;
}
