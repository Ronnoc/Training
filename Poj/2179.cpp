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
int is[111][111];
int Q[333],W[333],E[333],R[333],T[333],Y[333];
int m,n,d;
vector<int>G[11111];
set<int>S[11111];
bool valid(int x,int y) {
	if(x<0||x>m)return 0;
	if(y<0||y>n)return 0;
	return 1;
}
void addedge(int u,int v) {
	G[u].PB(v);
	G[v].PB(u);
	S[u].insert(v);
	S[v].insert(u);
}
int main() {
	int i, j ,k;
	//	freopen( "inlay.in", "r", stdin );
	//	freopen( "inlay.out", "w", stdout );
	while(~scanf("%d%d%d",&m,&n,&d)) {
		m*=2,n*=2;
		for(i=0; i<=(m+1)*(n+1); i++)G[i].clear();
		for(i=0; i<=(m+1)*(n+1); i++)S[i].clear();
		memset(is,0,sizeof is);
		for(i=0; i<d; i++) {
			scanf("%d%d",&Q[i],&W[i]);
			scanf("%d%d",&E[i],&R[i]);
			Q[i]*=2;
			W[i]*=2;
			E[i]*=2;
			R[i]*=2;
		}
		Q[d]=0,W[d]=0,E[d]=m,R[d]=0; d++;
		Q[d]=0,W[d]=0,E[d]=0,R[d]=n; d++;
		Q[d]=m,W[d]=n,E[d]=m,R[d]=0; d++;
		Q[d]=m,W[d]=n,E[d]=0,R[d]=n; d++;
		for(i=0; i<d; i++) {
			int x=Q[i],y=W[i],p=E[i],q=R[i];
			int dx=p-x,dy=q-y;
			int gcd=__gcd(abs(dx),abs(dy));
			dx/=gcd,dy/=gcd;
			int a=x,b=y;
			while(valid(a+dx,b+dy)) {
				a+=dx,b+=dy;
				is[a][b]++;
			}
			T[i]=a,Y[i]=b;
			a=x,b=y;
			while(valid(a-dx,b-dy)) {
				a-=dx,b-=dy;
				is[a][b]++;
			}
			is[x][y]++;
		}
		int id=0;
		for(i=0; i<=m; i++)for(j=0; j<=n; j++)
				if(is[i][j]<=1)is[i][j]=0;
				else is[i][j]=++id;
		//		for ( i=0; i<=m; i++ )for ( j=0; j<=n; j++ )if ( is[i][j] )
		//					printf( "%d %d %d\n",i,j,is[i][j] );
		for(i=0; i<d; i++) {
			int x=Q[i],y=W[i],p=E[i],q=R[i];
			int dx=p-x,dy=q-y;
			int gcd=__gcd(abs(dx),abs(dy));
			dx/=gcd,dy/=gcd;
			int a=T[i],b=Y[i];
			int last=is[a][b];
			while(valid(a-dx,b-dy)) {
				a-=dx,b-=dy;
				if(is[a][b]) {
					addedge(last,is[a][b]);
					last=is[a][b];
				}
			}
		}
		int cnt=0;
		for(i=1; i<=id; i++)for(j=0; j<G[i].SZ; j++) {
				//i~u~v
				int u=G[i][j];
				if(i<u)for(k=0; k<G[u].SZ; k++) {
						int v=G[u][k];
						if(u<v&&S[i].count(v))
							cnt++;
					}
			}
		printf("%d\n",cnt);
	}
	return 0;
}

