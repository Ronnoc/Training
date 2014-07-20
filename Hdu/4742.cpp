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
const LL MOD = 1LL<<30;
PII a[100005];
int b[100005];
vector<pair<int,PII> >TL;
int K,iCmp,nTid;
struct node {
	PII p;
	int k;
	node *ls,*rs;
	int dp,_dp,cnt,_cnt;
	PII L,R;
	void update( int flag=0 ) {
		dp=_dp,cnt=_cnt;
		if ( flag ) {
			L=p,R=p;
			if ( ls )
				cmax( R.AA,ls->R.AA ),cmax( R.BB,ls->R.BB ),cmin( L.AA,ls->L.AA ),cmin( L.BB,ls->L.BB );
			if ( rs )
				cmax( R.AA,rs->R.AA ),cmax( R.BB,rs->R.BB ),cmin( L.AA,rs->L.AA ),cmin( L.BB,rs->L.BB );
		}
		if ( ls )cmax( dp,ls->dp );
		if ( rs )cmax( dp,rs->dp );
		if ( dp!=_dp )cnt=0;
		if ( ls&&ls->dp==dp )cnt+=ls->cnt;
		if ( cnt>=MOD )cnt-=MOD;
		if ( rs&&rs->dp==dp )cnt+=rs->cnt;
		if ( cnt>=MOD )cnt-=MOD;
	}
} kd[400005],*root;
bool cmpX( const PII &a,const PII &b ) {return a.AA<b.AA;}
bool cmpY( const PII &a,const PII &b ) {return a.BB<b.BB;}
node *create() {
	node &G=kd[nTid++];
	return &G;
}
vector<PII>C;
node *build( int l,int r,int k ) {
	if ( l>=r )return 0;
	k%=2;
	int mid=( l+r )/2;
	if ( k )nth_element( C.OP+l,C.OP+mid,C.OP+r,cmpX );
	else nth_element( C.OP+l,C.OP+mid,C.OP+r,cmpY );
	node *G=create();
	G->k=k,G->p=C[mid],G->_dp=0,G->_cnt=1;
	G->ls=build( l,mid,k+1 );
	G->rs=build( mid+1,r,k+1 );
	G->update( 1 );
	return G;
}
void buildKDTree() {
	K=2;
	nTid=0;
	root=build( 0,C.SZ,0 );
}
int DP,CNT;
PII O,OO=MP( 0,0 );
void show( node p ) {
	cout<<p.p.AA<<","<<p.p.BB<<" :: ";
	cout<<p._dp<<" "<<p._cnt<<"\t"<<p.dp<<" "<<p.cnt<<endl;
}
void queryF( node *p ) {
	if ( !p )return;
	if ( p->R.AA<=O.AA&&p->R.BB<=O.BB ) {
		if ( p->dp>DP )DP=p->dp,CNT=p->cnt;
		else if ( p->dp==DP )CNT+=p->cnt;
		if ( CNT>=MOD )CNT-=MOD;
	} else if ( p->L.AA<=O.AA&&p->L.BB<=O.BB ) {
		if ( p->p.AA<=O.AA&&p->p.BB<=O.BB ) {
			if ( p->_dp>DP )DP=p->_dp,CNT=p->_cnt;
			else if ( p->_dp==DP )CNT+=p->_cnt;
			if ( CNT>=MOD )CNT-=MOD;
		}
		queryF( p->ls );
		queryF( p->rs );
	}
//	show( *p );
}
void updateO( node *p ) {
	if ( !p )return;
	if ( p->p==O ) {
		p->_dp=DP+1;
		p->_cnt=CNT;
		p->update();
		return;
	}
	if ( O.AA<=p->R.AA&&O.AA>=p->L.AA )
		if ( O.BB<=p->R.BB&&O.BB>=p->L.BB ) {
			updateO( p->ls );
			updateO( p->rs );
			p->update();
		}
//	show( *p );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		int n;
		scanf( "%d",&n );
		for ( i=0; i<n; i++ )scanf( "%d%d%d",&a[i].AA,&a[i].BB,&b[i] );
		TL.clear();
		for ( i=0; i<n; i++ )TL.PB( MP( b[i],a[i] ) );
		SORT( TL );
		C.clear();
		for ( i=0; i<n; i++ )C.PB( a[i] );
		C.PB( OO );
		SORT( C );
		C.erase( unique( C.OP,C.ED ),C.ED );
		buildKDTree();
		for ( i=0; i<TL.SZ; i++ ) {
//			cout<<"TL "<<TL[i].BB.AA<<","<<TL[i].BB.BB<<endl;
			DP=CNT=0;
			O=TL[i].BB;
			queryF( root );
			if ( DP==0 )CNT=1;
//			cout<<"after QF get "<<DP<<" "<<CNT<<endl;
			updateO( root );
		}
		cout<<root->dp<<" "<<root->cnt<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
