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
int query(int id) {
	if(SGT[id].r==SGT[id].l)return SGT[id].st;
	if(SGT[id].same)return SGT[id].st*(SGT[id].r-SGT[id].l+1);
	return query(id*2)+query(id*2+1);
}
int n,q;
LL a[100010];
int main() {
	int i,j,l,r,x;
	int T,CASE;
	for(scanf("%d",&T),CASE=1;CASE<=T;CASE++){
		scanf( "%d%d",&n,&q );
		build( 1,n,1 );
		pushdown(1,1,n,1);
		for ( j=1; j<=q; j++ ) {
			scanf("%d%d%d",&l,&r,&x);
			pushdown(1,l,r,x);
		}
		printf("Case %d: The total value of the hook is %d.\n",CASE,query(1));
	}
	return 0;
}
