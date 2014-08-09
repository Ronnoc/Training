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
#define AA first
#define BB second
#define MP make_pair
#define PB push_back
#define SZ size()

string s[111];
map<pair<string,string>,int>G;
int gao( string A,string B ) {
	if ( A==B )return 0;
	if ( G[MP( A,B )] )return G[MP( A,B )];
	int a[6][6],b[6][6];
	memset( a,0,sizeof a );
	memset( b,0,sizeof b );
	int i,j;
	for ( i=0; i<A.SZ; i++ )for ( j=i+1; j<A.SZ; j++ )
			a[A[i]-'A'][A[j]-'A']++;
	for ( i=0; i<A.SZ; i++ )for ( j=i+1; j<A.SZ; j++ )
			b[B[i]-'A'][B[j]-'A']++;
	int ret=0;
	for ( i=0; i<5; i++ )for ( j=i+1; j<5; j++ )if ( a[i][j]!=b[i][j] )ret++;
//	cout<<A<<" "<<B<<" "<<ret<<endl;
	return G[MP( A,B )]=ret;
}
int main() {
	int i,j;
	int n;
	while ( cin>>n&&n ) {
		for ( i=0; i<n; i++ )cin>>s[i];
		sort( s,s+n );
		int mx=1111111;
		string ms;
		string q="ABCDE";
		do {
			int cnt=0;
			for ( i=0; i<n; i++ )cnt+=gao( q,s[i] );
			if ( cnt<mx )mx=cnt,ms=q;
		} while ( next_permutation( q.begin(),q.end() ) );
		cout<<ms<<" is the median ranking with value "<<mx<<".\n";
	}
	return 0;
}
