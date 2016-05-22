#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))
const int MOD = 1000000007;
map<LL,int>dp[11][11][11];
map<LL,int>::iterator it;
int n,m;
char s[11][11];
LL ans[11];
void play(int p,int q,int r,int w,LL z,LL x) {
//	cerr<<p<<","<<q<<" "<<r<<" w="<<w<<" z="<<z<<" x="<<x<<"\n";
	int h[11];
	int i,j,k;
	for(i=0; i<n; i++) {
		h[i]=z&15;
		z>>=4;
	}
	if(w)h[q]++;
	else h[q]=0;
	if(p>=r&&q>=r) {
		int fail=0;
		for(i=q; i>=q-r; i--)
			if(h[i]<=r) {fail=1; break;}
		if(!fail)r++;
	}
	int g[11];
	for(i=0; i<=q; i++)g[i]=h[i]+n-1-p;
	for(i=q+1; i<n; i++)g[i]=h[i]+n-p;
//	for(i=0; i<n; i++)cerr<<h[i]<<" "; cerr<<"\n";
//	for(i=0; i<n; i++)cerr<<g[i]<<" "; cerr<<"\n";
	int v[11];
	for(i=0;i<n;i++)v[i]=0;
	for(i=0; i+r<n; i++) {
		int d=g[i];
		for(j=1; j<=r; j++)
			cmin(d,g[i+j]);
		if(d>r)
			for(j=0;j<=r;j++)
				cmax(v[i+j],d);
	}
	for(i=0;i<n;i++)cmin(g[i],v[i]);
	for(i=0; i<=q; i++)h[i]=g[i]-(n-1-p);
	for(i=q+1; i<n; i++)h[i]=g[i]-(n-p);
	for(i=0; i<n; i++)cmax(h[i],0);
//	for(i=0; i<n; i++)cerr<<g[i]<<" "; cerr<<"\n";
//	for(i=0; i<n; i++)cerr<<h[i]<<" "; cerr<<"\n";
	LL next=0;
	for(i=n-1; i>=0; i--) {
		next<<=4;
		next|=h[i];
	}
	q++;
	if(q==n)p++,q=0;
	dp[p][q][r][next]+=x;
	if(dp[p][q][r][next]>=MOD)
		dp[p][q][r][next]-=MOD;
//	cerr<<p<<","<<q<<","<<r<<" next="<<next<<" \n";
//	system("pause");
}
int main() {
	int i,j,k;
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(i=0; i<n; i++)scanf("%s",s[i]);
		memset(ans,0,sizeof ans);
		for(i=0; i<=n; i++)
			for(j=0; j<=n; j++)
				for(k=0; k<=n; k++)
					dp[i][j][k].clear();
		dp[0][0][0][0]=1;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				for(k=0; k<=n; k++) {
//					cerr<<i<<" "<<j<<" "<<k<<" SZ="<<dp[i][j][k].SZ<<"\n";
					for(it=dp[i][j][k].OP; it!=dp[i][j][k].ED; ++it) {
						play(i,j,k,0,(*it).AA,(*it).BB);//black
						if(s[i][j]!='*')
							play(i,j,k,1,(*it).AA,(*it).BB);//white
					}
				}
		for(i=0; i<=n; i++)
			for(it=dp[n][0][i].OP; it!=dp[n][0][i].ED; ++it) {
				ans[i]+=(*it).BB;
				if(ans[i]>=MOD)ans[i]-=MOD;
			}
		for(i=0; i<=n; i++)
			printf("%I64d\n",ans[i]%MOD);
	}
	return 0;
}
/*
1
3
oo*
ooo
***
*/
