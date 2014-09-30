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
inline int LB(int x) {return x&(-x);}
const int MXN = 100000 + 10;
void gao(int &D,int &C,int d,int c) {
	if(d>D)D=d,C=c;
	else if(d==D)C+=c;
}
class SegmentTree {
public:
	struct node {
		int v,c,del;
	} pl[MXN<<2|1];
	int allz,ally;
	int del_init;
private:
	void update(node &R,node &A,node &B) { ///here need to edit
		if(A.v>B.v)R.v=A.v,R.c=A.c;
		else if(A.v<B.v)R.v=B.v,R.c=B.c;
		else R.v=A.v,R.c=A.c+B.c;
	}
	void build(int p,int pz,int py) {
		pl[p].v=pl[p].c=0;///here need to edit
		pl[p].del=del_init;
		if(pz==py)return;
		int mid=(pz+py)>>1;
		build(p<<1,pz,mid);
		build(p<<1|1,mid+1,py);
	}
public:
	void init(int leftmost,int rightmost,int del_i=0) {
		allz=leftmost;
		ally=rightmost;
		del_init=del_i;
		build(1,allz,ally);
	}
	void refresh(int p,int pz,int py,int zz,int yy,int vv,int cc) {
		if(yy<zz)return;///delete if (zz<=yy)===true
		int mid=(pz+py)>>1;
		if(pz==zz && py==yy) { ///here need to edit
			gao(pl[p].v,pl[p].c,vv,cc);
			return;
		}
		if(yy<=mid)refresh(p<<1,pz,mid,zz,yy,vv,cc);
		else if(mid<zz)refresh(p<<1|1,mid+1,py,zz,yy,vv,cc);
		else {
			refresh(p<<1,pz,mid,zz,mid,vv,cc);
			refresh(p<<1|1,mid+1,py,mid+1,yy,vv,cc);
		}
		update(pl[p],pl[p<<1],pl[p<<1|1]);
	}
	node query(int p,int pz,int py,int zz,int yy) {
		if(yy<zz) { ///delete if (zz<=yy)===true
			node ret;
			ret.v=0;
			return ret;
		}
		int mid=(pz+py)>>1;
		if(pz==zz && py==yy)return pl[p];
		if(yy<=mid)return query(p<<1,pz,mid,zz,yy);
		else if(mid<zz)return query(p<<1|1,mid+1,py,zz,yy);
		else {
			node A=query(p<<1,pz,mid,zz,mid);
			node B=query(p<<1|1,mid+1,py,mid+1,yy);
			node ret;
			update(ret,A,B);
			return ret;
		}
	}
	void refresh(int zz,int yy,int vv,int cc) {
		refresh(1,allz,ally,zz,yy,vv,cc);
	}
	node query(int zz,int yy) {
		return query(1,allz,ally,zz,yy);
	}
} ST;

struct mac {
	int x,y,z;
	mac(int X=0,int Y=0,int Z=0):x(X),y(Y),z(Z) {}
	bool operator < (const mac &m)const {
		if(x!=m.x)return x<m.x;
		if(y!=m.y)return y<m.y;
		return z<m.z;
	}
	void read() {scanf("%d%d%d",&x,&y,&z);}
};
int n;
mac A[100005];
int dp[100005];
int ct[100005];
void solve(int l,int r) {
//    cout<<"solve "<<l<<"~"<<r<<endl;
	if(l==r)return;
	int i,j,mid=(l+r)>>1;
	solve(l,mid);

	vector<int>Z;
	for(i=l; i<=r; i++)Z.PB(A[i].z);
	sort(Z.OP,Z.ED);
	Z.erase(unique(Z.OP,Z.ED),Z.ED);

	vector<pair<int,PII> >TL;
	for(i=l; i<=r; i++)
		TL.PB(MP(A[i].y,MP(A[i].z,i)));
	sort(TL.OP,TL.ED);

	ST.init(0,Z.SZ);
	for(int t=0; t<TL.SZ; t++) {
		int iz=lower_bound(Z.OP,Z.ED,TL[t].BB.AA)-Z.OP;
		int id=TL[t].BB.BB;
		if(id<=mid)
			ST.refresh(iz,iz,dp[id],ct[id]);
		else {
			SegmentTree::node A=ST.query(0,iz);
			gao(dp[id],ct[id],A.v+1,A.c);
		}
	}
	solve(mid+1,r);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(i=1; i<=n; i++)A[i].read(),dp[i]=ct[i]=1;
		sort(A+1,A+n+1);
		solve(1,n);
		int D=-1,C;
		for(i=1; i<=n; i++)
			gao(D,C,dp[i],ct[i]);
		LL MOD=1LL<<30;
		printf("%d %I64d\n",D,((C%MOD)+MOD)%MOD);
	}
	return 0;
}
