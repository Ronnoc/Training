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

int a[500005];
int L[500005];
int pre[500005];
int next[500005];
int last[500005];
int dp[500005];
int choose[500005];
int rev[500005];
struct SEG {
	int l,r;
	int m,id;
	SEG(int _l=0,int _r=0) {l=_l,r=_r;}
} PRE[500005<<2|1],DP[500005<<2|1],PRE2[500005<<2|1];
void create(SEG &T,int t) {
	T.m=0;
	T.id=t;
}
void fresh(SEG &T,SEG &L,SEG &R) {
	if(R.m>=L.m)T.m=R.m,T.id=R.id;
	else T.m=L.m,T.id=L.id;
}
void build(int id,int l,int r,SEG *SGT) {
	SGT[id]=SEG(l,r);
	int mid=(l+r)/2;
	if(l!=r) {
		build(id*2,l,mid,SGT);
		build(id*2+1,mid+1,r,SGT);
		fresh(SGT[id],SGT[id<<1],SGT[id<<1|1]);
	} else create(SGT[id],l);
}
void update(int id,int t,int w,SEG *SGT) {
	SEG &T=SGT[id];
	if(T.l==T.r) {
		T.m=max(T.m,w);
		return;
	}
	int mid=(T.l+T.r)>>1;
	if(t<=mid)update(id<<1,t,w,SGT);
	else update(id<<1|1,t,w,SGT);
	fresh(T,SGT[id<<1],SGT[id<<1|1]);
}
void query(int id,SEG &A,SEG *SGT) {
	SEG &T=SGT[id];
	if(T.l==A.l&&T.r==A.r) {A=T; return;}
	int mid=(T.l+T.r)>>1;
	if(A.r<=mid)query(id<<1,A,SGT);
	else if(A.l>mid)query(id<<1|1,A,SGT);
	else {
		SEG le(A.l,mid),re(mid+1,A.r);
		query(id<<1,le,SGT);
		query(id<<1|1,re,SGT);
		fresh(A,le,re);
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T,n;
	while(~scanf("%d",&n)) {
		for(i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			L[i-1]=a[i];
		}
		sort(L,L+n);
		int m=unique(L,L+n)-L;
		for(i=0; i<m; i++)last[i]=-1;
		for(i=1; i<=n; i++)pre[i]=next[i]=-1;
		for(i=0; i<=n; i++)dp[i]=0,choose[i]=rev[i]=-1;
		for(i=1; i<=n; i++) {
			int id=lower_bound(L,L+m,a[i])-L;
			if(~last[id])next[last[id]]=i,pre[i]=last[id];
			last[id]=i;
		}
		build(1,1,n,PRE);
		build(1,1,n,PRE2);
		build(1,0,n,DP);
		int w=1;
		for(i=1; i<=n; i++) {
			if(-1==pre[i])continue;
			while(w<=i&&next[w]<=i) {
				int x=next[w];
				if(~x) {
					SEG AP(w+1,x-1);
					int y,z;
					int ok=0;
					if(AP.r>=AP.l) {
						query(1,AP,PRE);
						int y=AP.id;
						int z=AP.m;
						if(1<=z) {
							SEG AD(0,z-1);
							query(1,AD,DP);
							choose[x]=AD.id;
							dp[x]=AD.m+4;
							rev[x]=y;
							update(1,x,dp[x],DP);
						}
					}
					y=pre[w];
					if(~y) {
						z=pre[y];
						if(~z) {
							SEG AD(0,z-1);
							query(1,AD,DP);
							if(dp[x]<AD.m+4) {
								choose[x]=AD.id;
								dp[x]=AD.m+4;
								rev[x]=y;
								update(1,x,dp[x],DP);
							}
						}
					}
					update(1,x,w,PRE);
					if(~pre[w])update(1,x,pre[w],PRE2);
				}
				w++;
			}
		}
		int mxdp=-1,id=-1;
		for(i=0; i<=n; i++)if(dp[i]>=mxdp)mxdp=dp[id=i];
//		for(i=0; i<=n; i++)cout<<dp[i]<<" "<<choose[i]<<"?"<<rev[i]<<endl;
		printf("%d\n",mxdp);
		vector<int>out;
		while(dp[id]) {
			out.PB(a[id]);
			out.PB(a[rev[id]]);
			out.PB(a[id]);
			out.PB(a[rev[id]]);
			id=choose[id];
		}
		reverse(out.OP,out.ED);
		if(!out.empty()) {
			printf("%d",out[0]);
			for(i=1; i<out.SZ; i++)printf(" %d",out[i]);
			printf("\n");
		}
	}
	return 0;
}
