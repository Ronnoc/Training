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
#include <fstream>
#include <cstdlib>
#include <cstring>
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
#define SORT(p) sort(p.OP,p.ED)
#define cmax(x,a) (x)=(max((x),(a)))
typedef long long LL;
typedef pair<int, int> PII;
bool play( string s,int w,int k ) {
	cout<<w<<endl;
	int i,j;
	vector<PII>L;
	for(i=1;i<=k;i++)L.PB(MP(0,i));
	for(i=0;i<s.SZ;i++)if(s[i]!='0')L[s[i]-'0'-1].AA++;
	SORT(L);
	reverse(L.OP,L.ED);
	for ( i=0; i<s.SZ; i++ ) {
		if ( s[i]!='0' )continue;
		int can=0;
		for ( j=0;j<L.SZ;j++ ) {
			s[i]='0'+L[j].BB;
			int l=i-1,r=i+1;
			while ( l>=0&&s[l]!=s[i] )l--;
			while ( r<s.SZ&&s[r]!=s[i] )r++;
			if(l==-1)l-=10;
			if(r==s.SZ)r+=10;
			cout<<"("<<s[i]<<" "<<l<<" "<<r<<")";
			int tp=min( r-i,i-l );
			if ( tp>=w ) {can=1; break;}
		}
		cout<<"\t"<<s<<endl;
		if ( !can )return 0;
	}
	return 1;
}
int greedy( string s,int zero,int k ) {
	cout<<s<<" "<<zero<<" "<<k<<endl;
	int ret;
	for ( ret=zero; ret>1; ret-- )if ( play( s,ret,k ) )return ret;
	return 1;
}
map<vector<int>,int>dp[55];
map<vector<int>,int>::iterator it;
vector<int>tp;
class AmoebaCode {
public:
	int find( string C, int K ) {
//		cout<<C<<endl;
		int left=0,right=0;
		for ( int i=0; i<C.SZ; i++ )if ( C[i]!='0' )left+=i*i;
		reverse( C.OP,C.ED );
		for ( int i=0; i<C.SZ; i++ )if ( C[i]!='0' )right+=i*i;
		if ( left<right )
			reverse( C.OP,C.ED );
		int ret=1;
		int i,j;
		vector<int>G[11];
		for ( i=0; i<C.SZ; i++ )G[C[i]-'0'].PB( i );
		int nb=K;
		for ( i=1; i<=K; i++ )if ( G[i].SZ>1 )for ( j=1; j<G[i].SZ; j++ )nb=min( nb,G[i][j]-G[i][j-1] );
		nb=greedy( C,nb,K );
		int id,tot;
		reverse( C.OP,C.ED );
		id=C.SZ-1,tot=0;
		while ( id>=0&&C[id]=='0' )id--,tot++;
		if ( tot>K ) {
			string c;
			for ( int i=0; i<=id; i++ )c+=C[i];
			for ( int i=0; i<nb; i++ )c+='0';
			C=c;
		}
		reverse( C.OP,C.ED );
		id=C.SZ-1,tot=0;
		while ( id>=0&&C[id]=='0' )id--,tot++;
		if ( tot>K ) {
			string c;
			for ( int i=0; i<=id; i++ )c+=C[i];
			for ( int i=0; i<nb; i++ )c+='0';
			C=c;
		}
		if(nb==K)return nb;
//		if(nb==K-)return nb;
		cout<<C<<"~"<<nb<<endl;
		vector<int>temp;
		for ( i=1; i<=K; i++ )temp.PB( -K );
		for ( i=0; i<=C.SZ; i++ )dp[i].clear();
		dp[0][temp]=K+1;
		for ( i=0; i<C.SZ; i++ ) {
//			cout<<i<<endl;
			for ( it=dp[i].OP; it!=dp[i].ED; ++it ) {
				tp=( *it ).AA;
				int &pd=( *it ).BB;
				for ( j=0; j<tp.SZ; j++ )if ( i-tp[j]>pd )tp[j]=i-pd;
				if ( pd<nb )continue;
				if ( C[i]=='0' ) {
					for ( int ths=0; ths<K; ths++ ) {
						int lst=tp[ths];
						tp[ths]=i;
						if ( dp[i+1][tp]==0 )dp[i+1][tp]=min( pd,i-lst );
						else cmax( dp[i+1][tp],min( pd,i-lst ) );
						tp[ths]=lst;
					}
				} else {
					int ths=C[i]-'0'-1;
					int lst=tp[ths];
					tp[ths]=i;
					if ( dp[i+1][tp]==0 )dp[i+1][tp]=min( pd,i-lst );
					else cmax( dp[i+1][tp],min( pd,i-lst ) );
				}
			}
			dp[i].clear();
		}
		for ( it=dp[i].OP; it!=dp[i].ED; ++it )
			cmax( ret,( *it ).BB );
		return ret;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
