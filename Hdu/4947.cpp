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
const double PI=acos ( -1. );
const LL MOD = 1000000007;
LL BIT[50055];
int BIT_SIZE=50055;
int LB(int x){return x&-x;}
void refresh(int w,LL v){
	for(w+=5;w<BIT_SIZE;w+=LB(w))
		BIT[w]+=v;
}
LL query(int w){
	LL ret=0;
	for(w+=5;w>=1;w-=LB(w))ret+=BIT[w];
	return ret;
}
vector<int>W[200005];
int mu[200005],p[200005],pn;
bool flag[200005];
LL single[50055];
void init ( int n ) {
	pn=0;
	mu[1]=1;
	for ( int i=2; i<n; i++ ) {
		if ( !flag[i] ) {
			p[pn++]=i;
			mu[i]=-1;
		}
		for ( int j=0; j<pn && i*p[j]<n; j++ ) {
			flag[i*p[j]]=1;
			if ( i%p[j]==0 ) {
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
}
int main() {
	init ( 200001 );
//	freopen("1003.in","r",stdin);
//	freopen("m1003.out","w",stdout);
	int i,j,k,u,v,w;
	for ( i=1; i<=200000; i++ )if(mu[i])
		for ( j=i; j<=200000; j+=i )
			W[j].PB ( i );
	int n,m;
	int CA=0;
	while ( ~scanf ( "%d%d",&n,&m ) ) {
		if ( n==0&&m==0 ) break;
		memset(BIT,0,sizeof BIT);
		memset(single,0,sizeof single);
		printf("Case #%d:\n",++CA);
		while ( m-- ) {
			scanf ( "%d",&u );
			if ( u==1 ) {
				scanf ( "%d%d%d",&u,&v,&w );
				if(u%v)continue;
				u/=v;
				for(i=0;i<W[u].SZ;i++){
					if(v*W[u][i]>n)break;
					single[W[u][i]*v]+=w*mu[W[u][i]];
					refresh(W[u][i]*v,w*mu[W[u][i]]);
				}
			}else {
				scanf("%d",&u);
				LL ans=0;
				int le=1,re=u;
				while(le*le<=u)le++;
				for(i=1;i*i<=u;i++){
					ans+=u/i*single[i];
					int pe=u/(i+1)+1;
					int qe=u/i;
					if(qe>re)qe=re;
					if(pe<le)pe=le;
					if(pe<=qe)
						ans+=i*(query(qe)-query(pe-1));
					re=pe-1;
				}
				printf("%I64d\n",ans);
			}
		}
	}
	return 0;
}

