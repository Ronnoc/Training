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
const double PI=acos( -1. );
const LL MOD = 1000000007;

struct mac{
	int d,p,r,g;
	mac() {}
	bool operator <(const mac &m)const {return d<m.d;}
	LL calB(){return -p+r-1LL*g*(d+1);}
	LL calK(){return g;}
	void read(){scanf("%d%d%d%d",&d,&p,&r,&g);}
	void write(char *s=""){printf("d=%d p=%d r=%d g=%d%s",d,p,r,g,s);}
}Y[100005];
LL F[100005];
LL B[100005];
LL K[100005];
int slope(LL Y,LL X,LL Q,LL P){
	if(X<0)X=-X,Y=-Y;
	if(P<0)P=-P,Q=-Q;
	if(1.*P*Y<1.*Q*X)return -1;
	return 1.*P*Y>1.*Q*X;
}
int dq[100005],op,ed;
void addHull(int id){
	while(ed-op>0){
		int la=dq[ed-1];
		if(K[la]==K[id]){if(B[la]<B[id])ed--;else return;}
		else break;
	}
	while(ed-op>1){
		int s=dq[ed-2],t=dq[ed-1];
		if(slope(B[t]-B[s],K[t]-K[s],B[t]-B[id],K[t]-K[id])<=0)ed--;
		else break;
	}
	dq[ed++]=id;
//	printf("==>");
//	for(int i=op;i<ed;i++)printf("(%I64d,%I64d)@%d$%d ",K[dq[i]],B[dq[i]],dq[i],Y[dq[i]].d);
//	printf("\n");
}
vector<int>solve(int l,int r){
	vector<int>ret;
	if(l==r){
		if(r)cmax(F[r],F[r-1]);
		B[r]=F[r]+Y[r].calB();
		K[r]=Y[r].calK();
		if(F[r]>=Y[r].p)ret.PB(r);
		return ret;
	}
	int mid=(l+r)/2;
	vector<int>le=solve(l,mid);
	int id=0;
	for(int i=mid+1;i<=r;i++){
		while(id+1<le.SZ){
			int s=le[id],t=le[id+1];
			if(slope(B[t]-B[s],K[t]-K[s],-Y[i].d,1)>0)id++;
			else break;
		}
		if(id<le.SZ)cmax(F[i],K[ le[id] ]*Y[i].d+B[ le[id] ]);
	}
	vector<int>re=solve(mid+1,r);
	int il=0,ir=0;
	op=ed=0;
//	for(int i=0;i<le.SZ;i++)printf("(%I64d,%I64d)@%d$%d ",K[le[i]],B[le[i]],le[i],Y[le[i]].d);
//	printf("\n");
//	for(int i=0;i<re.SZ;i++)printf("(%I64d,%I64d)@%d$%d ",K[re[i]],B[re[i]],re[i],Y[re[i]].d);
//	printf("\n");
	while(il<le.SZ&&ir<re.SZ){
		if(K[le[il]]<K[re[ir]])addHull(le[il++]);
		else addHull(re[ir++]);
	}
	while(il<le.SZ)addHull(le[il++]);
	while(ir<re.SZ)addHull(re[ir++]);
	for(int i=op;i<ed;i++)ret.PB(dq[i]);
	return ret;
}
LL dp[100005];
int main() {
//	freopen("3842.in","r",stdin);
	int i,j,k,T;
	int N,C,D,CA=0;
	while(~scanf("%d%d%d",&N,&C,&D)){
		if(!N&&!C&&!D)break;
		for(i=1;i<=N;i++)Y[i].read();
		sort(Y+1,Y+N+1);
		for(i=0;i<=N;i++)F[i]=C;
		solve(1,N);
//		for(dp[0]=C,i=1;i<=N;i++)
//			for(dp[i]=dp[i-1],j=1;j<i;j++)if(dp[j]>=Y[j].p){
//				LL next=dp[j]-Y[j].p+Y[j].r+1LL*Y[j].g*(Y[i].d-Y[j].d-1);
//				cmax(dp[i],next);
//			}
		LL ans=F[0];
		for(i=1;i<=N;i++)if(F[i]>=Y[i].p)
			cmax(ans,K[i]*(D+1)+B[i]);
		printf("Case %d: %I64d\n",++CA,ans);
	}
	return 0;
}
