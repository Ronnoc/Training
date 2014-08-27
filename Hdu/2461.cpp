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

int px[22],qx[22],py[22],qy[22];
int ans[1<<20];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,u,v,w,p,q,r,n,m;
	int CA=0;
	while ( ~scanf ( "%d%d",&n,&m ) && ( n||m ) ) {
		for ( i=0; i<n; i++ )
			scanf ( "%d%d%d%d",&px[i],&py[i],&qx[i],&qy[i] );
		printf("Case %d:\n",++CA);
		for ( i=0; i<1<<n; i++ ) ans[i]=0;
		vector<int>X;
		for ( i=0; i<n; i++ ) X.PB ( px[i] );
		for ( i=0; i<n; i++ ) X.PB ( qx[i] );
		sort ( X.OP,X.ED );
		X.erase ( unique ( X.OP,X.ED ),X.ED );
		for ( i=0; i+1<X.SZ; i++ ) {
			int has=0,none=0;
			for ( j=0; j<n; j++ )
				if ( px[j]<X[i+1]&&X[i]<qx[j] ) has|=1<<j;
				else none|=1<<j;
			int shas=has;
			do {
				vector<PII>L;
				int tmp=shas;
				while ( tmp ) {
					int del=tmp&-tmp;
					tmp^=del;
					int id=__builtin_ctz ( del );
					L.PB ( MP ( py[id],qy[id] ) );
				}
				sort ( L.OP,L.ED );
				if ( !L.empty() ) {
					int p=L[0].AA,q=L[0].BB;
					int len=0;
					for ( j=1; j<L.SZ; j++ ) {
						if ( L[j].AA<=q ) cmax ( q,L[j].BB );
						else {
							len+=q-p;
							p=L[j].AA,q=L[j].BB;
						}
					}
					len+=q-p;
					len*=X[i+1]-X[i];
					int sn=none;
					if(len)do {
						ans[sn|shas]+=len;
						sn= ( sn-1 ) &none;
					}
					while ( sn!=none );
				}
				shas= ( shas-1 ) &has;
			}
			while ( shas!=has );
		}
		int nq=0;
		while(m--){
			nq++;
			int q,mask=0;
			scanf("%d",&q);
			while(q--){
				int w;
				scanf("%d",&w);
				mask|=1<<(w-1);
			}
			printf("Query %d: %d\n",nq,ans[mask]);
		}
		printf("\n");
	}
	return 0;
}
