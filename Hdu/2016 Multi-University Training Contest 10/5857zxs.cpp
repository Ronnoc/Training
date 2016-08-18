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

const int MXN = 100005;
struct SEG {
    int l, r, sum;
    SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN<<5];
int nextid;
int root[MXN];
inline void update(SEG &de,SEG &l,SEG &r){
    de.sum=l.sum+r.sum;
}
void build(int id,int le,int re){
    SEG &de=SGT[id];
    if(re-le==1){
        de.sum=0;
        return;
    }
    int me=(le+re)>>1;
    build(de.l=nextid++,le,me);
    build(de.r=nextid++,me,re);
    update(de,SGT[de.l],SGT[de.r]);
}
void dfs(int id,int c,int w,int le,int re){
    SEG &de=SGT[id];
    int me=(le+re)/2;
    if(re-le==1){
        de.sum+=w;
        return;
    }
    if(c<me){
        SGT[nextid]=SGT[de.l];
        dfs(de.l=nextid++,c,w,le,me);
    }else {
        SGT[nextid]=SGT[de.r];
        dfs(de.r=nextid++,c,w,me,re);
    }
    update(de,SGT[de.l],SGT[de.r]);
}
int nz,ak,al,ar;
void query(int ii,int ia,int ib,int ic,int id,int pe,int qe,int le,int re){
	SEG &de=SGT[ii];
	if(le==pe&&re==qe){
		de.sum=SGT[ib].sum-SGT[ia].sum+SGT[id].sum-SGT[ic].sum;
		return;
	}
	int me=(le+re)>>1;
	if(qe<=me)
		query(ii,SGT[ia].l,SGT[ib].l,SGT[ic].l,SGT[id].l,pe,qe,le,me);
	else if(pe>=me)
		query(ii,SGT[ia].r,SGT[ib].r,SGT[ic].r,SGT[id].r,pe,qe,me,re);
	else {
		query(de.l=nextid++,SGT[ia].l,SGT[ib].l,SGT[ic].l,SGT[id].l,pe,me,le,me);
		query(de.r=nextid++,SGT[ia].r,SGT[ib].r,SGT[ic].r,SGT[id].r,me,qe,me,re);
    	update(de,SGT[de.l],SGT[de.r]);
	}
}
void ask(int id,int K,int pe,int qe,int le,int re){
	SEG &de=SGT[id];
	if(le==pe&&re==qe){
		ak=K,al=le,ar=re;
		return;
	}
	int me=(le+re)>>1;
	if(qe<=me)ask(id,K,pe,qe,le,me);
	else if(pe>=me)ask(id,K,pe,qe,me,re);
	else {
		int sumleft=SGT[de.l].sum;
		if(K<=sumleft)ask(de.l,K,pe,me,le,me);
		else ask(de.r,K-sumleft,me,qe,me,re);
	}
}
int fuck(int ia,int ib,int ic,int id,int K,int pe,int qe,int le,int re){
	int me=(le+re)/2;
	if(pe==le&&qe==re){
		if(qe-pe==1)return le;
		int sumleft=SGT[SGT[ib].l].sum-SGT[SGT[ia].l].sum+SGT[SGT[id].l].sum-SGT[SGT[ic].l].sum;
		if(K<=sumleft)return fuck(SGT[ia].l,SGT[ib].l,SGT[ic].l,SGT[id].l,K,pe,me,le,me);
		else return fuck(SGT[ia].r,SGT[ib].r,SGT[ic].r,SGT[id].r,K-sumleft,me,qe,me,re);
	}
	if(qe<=me)return fuck(SGT[ia].l,SGT[ib].l,SGT[ic].l,SGT[id].l,K,pe,qe,le,me);
	if(pe>=me)return fuck(SGT[ia].r,SGT[ib].r,SGT[ic].r,SGT[id].r,K,pe,qe,me,re);
}
int play(int ia,int ib,int ic,int id,int K,int le,int re){
	int now;
	query(now=nextid++,ia,ib,ic,id,le,re,0,nz);
	ask(now,K,le,re,0,nz);
	int ret=fuck(ia,ib,ic,id,ak,al,ar,0,nz);
	nextid=now;
	return ret;
}
int w[MXN];
int iz[MXN],z[MXN];
void solve(){
	DRI(n);DRI(q);
	rep(i,1,n+1)RI(w[i]);
	rep(i,1,n+1)z[i-1]=w[i];
	sort(z,z+n);
	nz=unique(z,z+n)-z;
	nextid=0;
	build(root[0]=nextid++,0,nz);
	rep(i,1,n+1)
		iz[i]=lower_bound(z,z+nz,w[i])-z;
	rep(i,1,n+1){
		SGT[root[i]=nextid++]=SGT[root[i-1]];
		dfs(root[i],iz[i],1,0,nz);
	}
	while(q--){
		DRI(a);DRI(b);DRI(c);DRI(d);
		int tot=b-a+1+d-c+1;
		LL ans=0;
		if(tot&1)
			ans+=z[play(root[a-1],root[b],root[c-1],root[d],(tot+1)/2,0,nz)]*2LL;
		else {
			ans+=z[play(root[a-1],root[b],root[c-1],root[d],tot/2,0,nz)]*2LL;
			ans+=z[play(root[a-1],root[b],root[c-1],root[d],tot/2+1,0,nz)]*2LL;
			ans/=2;
		}
		if(ans<0)putchar('-'),ans=-ans;
		if(ans==0)cout<<"0.0\n";
		else if(ans%2==0)cout<<ans/2<<".0\n";
		else cout<<ans/2<<".5\n";
	}
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}