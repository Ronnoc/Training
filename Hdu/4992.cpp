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

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
LL powMod(LL a,LL b,LL m) {
	LL ret=1;
	while(b) {
		if(b&1)ret=ret*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ret;
}
int eulerPhi(int n) {
	int res = n;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) {
			res = res / i * (i - 1);
			for(; n % i == 0; n /= i);
		}
	if(n != 1) res = res / n * (n - 1);
	return res;
}
int find_root(int P) {
	if(P==2)return 1;
	int Q=eulerPhi(P);
	int phi=Q;
	vector<int>G;
	int i,j;
	for(i=2; i*i<=Q; i++)if(Q%i==0) {
			G.PB(i);
			while(Q%i==0)Q/=i;
		}
	if(Q>1)G.PB(Q);
	for(i=2;; i++)if(powMod(i,phi,P)==1) {
			int flag=1;
			for(j=0; j<G.SZ; j++)if(powMod(i,phi/G[j],P)==1) {flag=0; break;}
			if(flag)return i;
		}
	return -1;
}
bool check(int n) {
	vector<PII>L;
	int cnt=0;
	while(n%2==0)n/=2,cnt++;
	if(cnt>1)return 0;
	int i;
	for(i=3; i*i<=n; i++)if(n%i==0)break;
	if(n%i==0) {
		while(n%i==0)n/=i;
		if(n>1)return 0;
		return 1;
	}
	return 1;
}
int __gcd(int a,int b) {
	return b?__gcd(b,a%b):a;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(cin>>n) {
		if(n==1) {
			printf("1\n");
			continue;
		}
		if(n==2) {
			printf("1\n");
			continue;
		}
		if(n==4) {
			printf("3\n");
			continue;
		}
		if(!check(n)) {
			printf("-1\n");
			continue;
		}
		int __=find_root(n);
		int Q=eulerPhi(n);
		vector<int>L;
		for(i=1; i+i<=Q; i++)if(__gcd(i,Q-i)==1) {
				L.PB(powMod(__,i,n));
				L.PB(powMod(__,Q-i,n));
			}
		sort(L.OP,L.ED);
		L.erase(unique(L.OP,L.ED),L.ED);
		printf("%d",L[0]);
		for(i=1; i<L.SZ; i++)printf(" %d",L[i]);
		printf("\n");
	}
	return 0;
}
