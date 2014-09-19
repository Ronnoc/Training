#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define BB second
#define AA first
#define SZ size()
typedef pair<int,int> PII;
typedef long long LL;
const double PI = acos(-1.);
const double eps = 1e-8;
const LL MOD = 1000000007;
LL dp[1005][1005];
LL A[1005];
int N,M;
LL solve(int m,int n){
	LL &tp=dp[m][n];
	if(~tp)return tp;
	if(m==n)return tp=A[n];
	return tp=(solve(m-1,n-1)*n+solve(m-1,n)*(N-n))%MOD;
}
int main(){
	freopen("rooks.in","r",stdin);
	int i,j,T;
	A[0]=1;
	for(i=1;i<=1000;i++)A[i]=A[i-1]*i%MOD;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		map<int,int>X,Y;
		int n,m;
		scanf("%d%d",&N,&M);
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			X[x]++;
			Y[y]++;
		}
		n=X.SZ,m=Y.SZ;
		if(m<n)swap(m,n),swap(N,M);
		for(i=0;i<=m;i++)for(j=0;j<=i;j++)dp[i][j]=-1;
		printf("Case %d: %d %I64d\n",CA,m,solve(m,n));
	}
	return 0;
}
