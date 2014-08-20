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

char s[44];
struct edgenode {
	int v, next;
} edge[1<<21],Edge[1<<21];
int tot, last[1<<21];
int Tot, Last[1<<21];
int L[1<<21],R[1<<21];
int n, m;
void addEdge ( int x, int y ) {
//	cout<<"E:"<<x<<" "<<y<<endl;
	Edge[Tot].v = y;
	Edge[Tot].next = Last[x];
	Last[x] = Tot++;
}
void addedge ( int x, int y ) {
//	cout<<"e:"<<x<<" "<<y<<endl;
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}
int w[44];
void update(int &ans,int foo){
	foo=abs(foo);
	if(~ans)cmin(ans,foo);
	else ans=foo;
}
int main() {
//	freopen("1004.in","r",stdin);
//	freopen("m1004.out","w",stdout);
	int i,j,k;
	int N;
	while ( ~scanf ( "%d",&N ) &&N ) {
		scanf ( "%s",s );
		for ( i=0; i<N<<1; i++ ) scanf ( "%d",&w[i] );
		for ( tot=Tot=i=0; i< ( 1<< ( N+1 ) ); i++ ) Last[i]=last[i]=-1;
		int ALL= ( 1<<N )-1;
		for ( i=0; i<1<<N; i++ ) {
			int A=i,B=ALL^i;
			if ( A>B ) continue;
			int SA=0,SB=0,flag=1;
			while ( A&&B ) {
				int ia=__builtin_ctz ( A );
				int ib=__builtin_ctz ( B );
				A^=1<<ia,B^=1<<ib;
				if ( s[ia]!=s[ib] ) {
					flag=0;
					break;
				}
				SA+=w[ia];
				SB+=w[ib];
			}
			if ( !flag ) continue;
			if(!A&&!B){
				addedge(1,SA-SB);
				addedge(1,SB-SA);
				continue;
			}
			if ( B&&!A ) swap ( A,B ),swap ( SA,SB );
			int st=1;
			while ( A ) {
				int ia=__builtin_ctz ( A );
				A^=1<<ia;
				st<<=1;
				if ( s[ia]=='a' ) st|=1;
				SA+=w[ia];
			}
			addedge ( st,SA-SB );
		}
		int ans=-1;
		for ( i=0; i<1<<N; i++ ) {
			int A=i,B=ALL^i;
			if ( A>B ) continue;
			int SA=0,SB=0,flag=1;
			while ( A&&B ) {
				int ia=__builtin_ctz ( A );
				int ib=__builtin_ctz ( B );
				A^=1<<ia,B^=1<<ib;
				if ( s[N-1-ia+N]!=s[N-1-ib+N] ) {
					flag=0;
					break;
				}
				SA+=w[N-1-ia+N];
				SB+=w[N-1-ib+N];
			}
			if ( !flag ) continue;
			if(!A&&!B){
				addEdge(1,SA-SB);
				addEdge(1,SB-SA);
				continue;
			}
			if ( B&&!A ) swap ( A,B ),swap ( SA,SB );
			int st=1;
			while ( A ) {
				int ia=31-__builtin_clz ( A );
				A^=1<<ia;
				st<<=1;
				if ( s[N-1-ia+N]=='a' ) st|=1;
				SA+=w[N-1-ia+N];
			}
			addEdge(st,SA-SB);
		}
		for(i=0;i<1<<(N+1);i++){
			int il=0,ir=0;
			for(j=last[i];~j;j=edge[j].next)
				L[il++]=edge[j].v;
			for(j=Last[i];~j;j=Edge[j].next)
				R[ir++]=Edge[j].v;
			if(il&&ir){
				sort(L,L+il);
				sort(R,R+ir);
				for(j=0;j<il;j++){
					int id=upper_bound(R,R+ir,L[j])-R;
					if(id<ir)update(ans,R[id]-L[j]);
					if(id)update(ans,L[j]-R[id-1]);
				}
			}
		}
		printf ( "%d\n",ans );
	}
	return 0;
}
