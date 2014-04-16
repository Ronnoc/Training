<<<<<<< HEAD
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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

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
struct SEG {
	int l,r;
	bool same;
	int st;
	SEG() {}
	SEG( int _l,int _r ) {l=_l,r=_r,same=0,st=0;}
} SGT[1<<18];
void build( int l,int r,int id ) {
	SGT[id]=SEG( l,r );
	int mid=( l+r )/2;
	if ( l!=r )build( l,mid,id*2 );
	if ( l!=r )build( mid+1,r,id*2+1 );
}
void pushdown( int id,int l,int r,int st ) {
	if ( SGT[id].l==l&&SGT[id].r==r ) {SGT[id].same=1,SGT[id].st=st; return;}
	int mid=( SGT[id].l+SGT[id].r )/2;
	if(SGT[id].same){
		pushdown(id*2,SGT[id].l,mid,SGT[id].st);
		pushdown(id*2+1,mid+1,SGT[id].r,SGT[id].st);
		SGT[id].same=0;
	}
	if ( l>mid ) pushdown( id*2+1,l,r,st );
	else if ( r<=mid ) 	pushdown( id*2,l,r,st );
	else {
		pushdown( id*2,l,mid,st );
		pushdown( id*2+1,mid+1,r,st );
	}
}
int query(int id,int x) {
	if(SGT[id].r==SGT[id].l)return SGT[id].st;
	if(SGT[id].same)return SGT[id].st;
	int mid=( SGT[id].l+SGT[id].r )/2;
	if(x<=mid)return query(id*2,x);
	else return query(id*2+1,x);
}
int n;
int ll[11111],rr[11111];
int main() {
	int i,j;
	int T,CASE;
	for(scanf("%d",&T),CASE=1;CASE<=T;CASE++){
		scanf( "%d",&n );
		for(i=1;i<=n;i++)scanf("%d%d",&ll[i],&rr[i]);
		vector<int>Z;
		for(i=1;i<=n;i++)Z.PB(ll[i]);
		for(i=1;i<=n;i++)Z.PB(rr[i]);
		SORT(Z);
		Z.erase(unique(Z.OP,Z.ED),Z.ED);
		build( 0,Z.SZ-1,1 );
		pushdown(1,0,Z.SZ-1,-1);
		for(i=1;i<=n;i++){
			int lz=lower_bound(Z.OP,Z.ED,ll[i])-Z.OP;
			int rz=lower_bound(Z.OP,Z.ED,rr[i])-Z.OP;
			pushdown(1,lz,rz,i);
		}
		set<int>Q;
		for(i=0;i<Z.SZ;i++){
			int temp=query(1,i);
			if(temp>0)Q.insert(temp);
		}
		printf("%d\n",(int)Q.SZ);
	}
	return 0;
}
=======
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct line{
	int l,r;
	int x;
	}L[1<<16];
void use(int w){
	printf("i=%d::l=%d,r=%d,x=%d\n",w,L[w].l,L[w].r,L[w].x);
	}
void build(int s,int t,int wl){
//	printf("build (%d,%d) on %d\n",s,t,wl);
//	use(wl);
	L[wl].l=s;L[wl].r=t;
	L[wl].x=0;
	if(s==t)return;
	int mid=(s+t)/2;
	build(s,mid,wl*2);
	build(mid+1,t,wl*2+1);
	}
void insert(int s,int t,int wl,int x){
//	printf("(%d %d)add %d\n",s,t,wl,x);
//	use(wl);
	if(s>t)return;
	if(s==L[wl].l&&t==L[wl].r){L[wl].x=x;return;}
	if(L[wl].l==L[wl].r)return;
	int mid=(L[wl].l+L[wl].r)/2;
		int tp=L[wl].x;L[wl].x=0;
		if(tp)insert(t+1,L[wl].r,wl,tp);
		if(tp)insert(L[wl].l,s-1,wl,tp);
	if(mid>=t)insert(s,t,wl*2,x);
	else if(mid<s)insert(s,t,wl*2+1,x);
	else {
		insert(s,mid,wl*2,x);
		insert(mid+1,t,wl*2+1,x);
		}
	}
int ok[10010];
int l[10010],r[10010];

void visit(int wl){
//	printf("visit(%d)\n",wl);
//	use(wl);
	if(L[wl].x)ok[ L[wl].x ]++;
	else if(L[wl].l==L[wl].r)return;
	else {
		visit(wl*2);
		visit(wl*2+1);
		}
	}
vector<int>Z;
int find(int x){
	int i;
	for(i=0;i<Z.size();i++)if(Z[i]==x)return i;
	}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		Z.clear(); 
		int i;
		for(i=1;i<=n;i++){
			scanf("%d%d",&l[i],&r[i]);
			Z.push_back(l[i]);
			Z.push_back(r[i]);
			}
		build(0,2*n,1);
		sort(Z.begin(),Z.end());
		for(i=1;i<=n;i++){
			insert(find(l[i]),find(r[i]),1,i);
			}
		for(i=1;i<=n;i++)ok[i]=0;
		visit(1);
		int res=0;
		for(i=1;i<=n;i++)if(ok[i])res++;
		printf("%d\n",res);
		}
	return 0;
	}
>>>>>>> 020dfaf6b07b9f7c884acd4bc4c88875a20c169d
