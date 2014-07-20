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

const int N = 100000+10;
int K,iCmp,nTid;
typedef vector<int> Obj;
void show( Obj o ) {
	printf( "%d",o[0] );
	for ( int i=1; i<K; i++ )printf( " %d",o[i] );
	printf( "\n" );
}
struct Filter {
	Obj L,R;
	bool ok( const Obj &o )const {
		for ( int i=0; i<K; i++ )if ( o[i]<L[i]||o[i]>R[i] )return 0;
		return 1;
	}
	bool ok( const Filter &f )const {
		for ( int i=0; i<K; i++ )
			if ( f.L[i]<L[i]||f.R[i]>R[i] )return 0;
		return 1;
	}
	void merge( const Filter &f ) {
		for ( int i=0; i<K; i++ )cmax( R[i],f.R[i] );
		for ( int i=0; i<K; i++ )cmin( L[i],f.L[i] );
	}
};
struct Node {
	Obj u;
	Filter f;
	int c;
	Node *ls,*rs;
	void update() {
		f.L=f.R=u;
		if ( ls )f.merge( ls->f );
		if ( rs )f.merge( rs->f );
	}
};
Node kd[N<<2],*root;
bool cmp( const Obj &a,const Obj &b ) {
	return a[iCmp]<b[iCmp];
}
Node *newNode( const Obj &u,int c ) {
	Node &G=kd[nTid++];
	G.u=u; 
	G.c=c;
	G.ls=G.rs=0;
	return &G;
}
Node *build( vector<Obj> &a,int l,int r,int c ) {
	if ( l>=r )return NULL;
	int mid=( l+r )/2;
	iCmp=c;
	nth_element( a.OP+l,a.OP+mid,a.OP+r,cmp );
	Node *G=newNode( a[mid],c );
	G->ls=build( a,l,mid,( c+1 )%K );
	G->rs=build( a,mid+1,r,( c+1 )%K );
	G->update();
	return G;
}
void queryF( Node *p,const Filter &f ) {
	if ( !p )return;											//空树
	if ( f.ok( p->f ) ) {return;} 				//子树可行
	int x=p->u[p->c];
	if ( x>=f.L[p->c] )queryF( p->ls,f ); //左子树
	if ( x<=f.R[p->c] )queryF( p->rs,f );	//右子树
}
vector<Obj>p;
void initKdTree() {
	//set K
	nTid=0;
	root=build( p,0,p.SZ,0 );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n;
	while ( ~scanf( "%d%d",&n,&K ) ) {
		p.clear();
		for ( i=0; i<n; i++ ) {
			Obj o;
			for ( j=0; j<K; j++ ) {
				int x;
				scanf( "%d",&x );
				o.PB( x );
			}
			p.PB( o );
		}
		initKdTree();
		int m;
		scanf( "%d",&m );
		while ( m-- ) {
			Obj o;
			for ( j=0; j<K; j++ ) {
				int x;
				scanf( "%d",&x );
				o.PB( x );
			}
			int w;
			scanf( "%d",&w );
			queryO( root,o,w );
			printf( "the closest %d points are:\n",w );
			vector<Obj>Out;
			while ( !Ans.empty() ) {
				Out.PB( Ans.top().BB );
				Ans.pop();
			}
			reverse( Out.OP,Out.ED );
			for ( i=0; i<Out.SZ; i++ )show( Out[i] );
		}
	}
	return 0;
}
