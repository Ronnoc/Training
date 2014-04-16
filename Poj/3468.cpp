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
	LL lazy,w;
	SEG() {}
	SEG( int _l,int _r ) {l=_l,r=_r,lazy=0,w=0;}
} SGT[1<<18];
void build( int l,int r,int id ) {
	SGT[id]=SEG( l,r );
	int mid=( l+r )/2;
	if ( l!=r )build( l,mid,id*2 );
	if ( l!=r )build( mid+1,r,id*2+1 );
}
void pushdown( int id,int l,int r,LL w ) {
//	if ( SGT[id].l==SGT[id].r ) {SGT[id].w+=w; return;}
//	cout<<id<<" "<<SGT[id].l<<" "<<SGT[id].r<<" "<<l<<" "<<r<<" "<<w<<endl;
	if ( SGT[id].l==l&&SGT[id].r==r ) {SGT[id].lazy+=w; return;}
	SGT[id].w+=w*( r-l+1 );
	int mid=( SGT[id].l+SGT[id].r )/2;
	if ( l>mid ) pushdown( id*2+1,l,r,w );
	else if ( r<=mid ) 	pushdown( id*2,l,r,w );
	else {
		pushdown( id*2,l,mid,w );
		pushdown( id*2+1,mid+1,r,w );
	}
}
LL query( int p,int q,int id ) {
	LL lazy=SGT[id].lazy*( q-p+1 );
	if ( SGT[id].l==p&&SGT[id].r==q )return lazy+SGT[id].w;
	int mid=( SGT[id].l+SGT[id].r )/2;
	if ( q<=mid )return lazy+query( p,q,id*2 );
	else if ( p>mid )return lazy+query( p,q,id*2+1 );
	else {
		LL al=query( p,mid,id*2 );
		LL ar=query( mid+1,q,id*2+1 );
		return lazy+al+ar;
	}
}
int n,q;
LL a[100010];
int main() {
	int i,j,l,r;
	LL x;
	while ( ~scanf( "%d%d",&n,&q ) ) {
		build( 1,n,1 );
		for ( i=1; i<=n; i++ )scanf( "%lld",&a[i] );
		for ( i=1; i<=n; i++ )pushdown( 1,i,i,a[i] );
		for ( j=1; j<=q; j++ ) {
			char s[2];
			scanf( "%s",s );
			if ( s[0]=='Q' ) {
				scanf( "%d%d",&l,&r );
				printf( "%lld\n",query( l,r,1 ) );
			} else {
				scanf( "%d%d%lld",&l,&r,&x );
				pushdown( 1,l,r,x );
			}
		}
	}
	return 0;
}
=======
#include<stdio.h>
#define LL long long
struct line{
	int l,r;
	LL x,s;
	}T[1<<18];
void build(int s,int t,int w){
	T[w].l=s;T[w].r=t;
	T[w].x=0;T[w].s=0;
	if(s==t)return;
	int mid=(s+t)/2;
	build(s,mid,w*2);
	build(mid+1,t,w*2+1);
	}
void insert(int s,int t,int w,LL val){
	if(T[w].l==s&&T[w].r==t){T[w].x+=val;return;}
	T[w].s+=(t+1-s)*val;
	int mid=(T[w].l+T[w].r)/2;
	if(s>mid)insert(s,t,w*2+1,val);
	else if(t<=mid)insert(s,t,w*2,val);
	else {
		insert(s,mid,w*2,val);
		insert(mid+1,t,w*2+1,val);
		}
	}
LL sum(int s,int t,int w){
	LL tp=(t+1-s)*T[w].x; 
	if(T[w].l==s&&T[w].r==t)return tp+T[w].s;
	int mid=(T[w].l+T[w].r)/2;
	if(s>mid)return tp+sum(s,t,w*2+1);
	else if(t<=mid)return tp+sum(s,t,w*2);
	else {
		return tp+sum(s,mid,w*2)+sum(mid+1,t,w*2+1);
		}	
	}
int main(){
	int N,Q;
	while(scanf("%d%d",&N,&Q)!=EOF){
		build(1,N,1);
		int i,j,s,t;
		LL x;
		char c;
		for(i=1;i<=N;i++){
			scanf("%lld%*c",&x);
			insert(i,i,1,x);
			}
		for(i=1;i<=Q;i++){
			scanf("%c",&c);
			if(c=='Q'){
				scanf("%d %d%*c",&s,&t);
				printf("%lld\n",sum(s,t,1)); 
				continue;
				}
			scanf("%d %d %lld%*c",&s,&t,&x);
			insert(s,t,1,x);
			}
		} 
	return 0;
	}
>>>>>>> 020dfaf6b07b9f7c884acd4bc4c88875a20c169d
