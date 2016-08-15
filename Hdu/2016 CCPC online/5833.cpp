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
const int MAXN = 303;
int a[2005][MAXN];
int b[2005];
int gauss_tpivot( int m,int n ) {
	int i, j, k, row, col, index[MAXN];
	int maxp, t;
	for ( i = 0; i < m; i++ )
		index[i] = i;
	for ( k = 0; k < m; k++ ) {
		for ( maxp = 0, i = k; i < m; i++ )
			for ( j = k; j < n; j++ )
				if ( a[i][j]>maxp )
					maxp = a[row = i][col = j];
		if ( maxp == 0 ) {
			for ( i=k; i<m; i++ )if ( b[i]!=0 )return -1;
			return n-k;
		}
		if ( col != k ) {
			for ( i = 0; i < m; i++ )
				t = a[i][col], a[i][col] = a[i][k], a[i][k] = t;
			j = index[col], index[col] = index[k], index[k] = j;
		}
		if ( row != k ) {
			for ( j = k; j < n; j++ )
				t = a[k][j], a[k][j] = a[row][j], a[row][j] = t;
			t = b[k], b[k] = b[row], b[row] = t;
		}
		for ( j = k + 1; j < n; j++ ) {
			for ( i = k + 1; i < m; i++ )
				a[i][j] ^= a[i][k] * a[k][j];
		}
		for ( i = k + 1; i < m; i++ )
			b[i] ^= b[k] * a[i][k];
	}
	return n-m;
}
const int MXN = 100005;
LL w[303];
void solve(){
	int n;cin>>n;
	rep(i,0,n)cin>>w[i];
	set<int>S;
	rep(i,0,n){
		LL temp=w[i];
		for(LL i=2;i*i<=temp;i++)if(temp%i==0){
			S.insert(i);
			while(temp%i==0)temp/=i;
		}
		if(temp>1)S.insert(temp);
	}
	VI L(all(S));
	rep(t,0,sz(L)){
		rep(i,0,n){
			a[t][i]=0;
			while(w[i]%L[t]==0)w[i]/=L[t],a[t][i]^=1;
		}
		b[t]=0;
	}
	int temp=gauss_tpivot( sz(L),n );
	
	LL ans=0;
	if(~temp){
		ans=1;
		while(temp--)ans=ans*2%MOD;
	}
	cout<<(ans+MOD-1)%MOD<<"\n";
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