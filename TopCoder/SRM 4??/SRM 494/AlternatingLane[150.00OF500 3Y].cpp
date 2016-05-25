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
typedef long long LL;
typedef pair<int, int> PII;

double dp[3][100005][3];//i done last is about j hight next should 0-lower 1-higher
double ex[3][100005][3];
double pre[100005];
class AlternatingLane {
public:
	double expectedBeauty( vector <int> l, vector <int> r ) {
		for ( int i=0; i<l.SZ; i++ )printf( "%4d ",l[i] ); printf( "\n" );
		for ( int i=0; i<r.SZ; i++ )printf( "%4d ",r[i] ); printf( "\n" );
		double ret=0;
		int n=l.SZ,i,j,k,p,q,h=0;
		for ( i=0; i<r.SZ; i++ )h=max( h,r[i] );
		for ( i=0; i<=1; i++ )for ( j=0; j<=h; j++ )for ( k=0; k<2; k++ )dp[i][j][k]=0.0;
		for ( i=0; i<=1; i++ )for ( j=0; j<=h; j++ )for ( k=0; k<2; k++ )ex[i][j][k]=0.0;
		for ( j=l[0]; j<=r[0]; j++ )for ( k=0; k<2; k++ )dp[0][j][k]=0.5/( r[0]-l[0]+1 );
		for ( i=0; i+1<n; i++ ) {
			int x=i%2,y=( i+1 )%2;
			double per=1.0/( r[i+1]-l[i+1]+1 );
//			for ( j=0; j<=h; j++ )
//				if ( dp[i][j][0]+dp[i][j][1]>1e-300 ) {
//					for ( p=l[i+1]; p<min( j,r[i+1]+1 ); p++ ) {
//						dp[i+1][p][1]+=dp[i][j][0]*per;
//						dp[i+1][p][1]+=dp[i][j][1]*per;
//						ex[i+1][p][1]+=( dp[i][j][1]+dp[i][j][0] )*per*( j-p );
//						ex[i+1][p][1]+=( ex[i][j][1]+ex[i][j][0] )*per;
//					}
//					if ( j>=l[i+1]&&j<=r[i+1] ) {
//						dp[i+1][j][1]+=dp[i][j][1]*per;
//						ex[i+1][j][1]+=ex[i][j][1]*per;
//						dp[i+1][j][0]+=dp[i][j][0]*per;
//						ex[i+1][j][0]+=ex[i][j][0]*per;
//					}
//					for ( p=max( j+1,l[i+1] ); p<=r[i+1]; p++ ) {
//						dp[i+1][p][0]+=dp[i][j][1]*per;
//						dp[i+1][p][0]+=dp[i][j][0]*per;
//						ex[i+1][p][0]+=( dp[i][j][1]+dp[i][j][0] )*per*( p-j );
//						ex[i+1][p][0]+=( ex[i][j][1]+ex[i][j][0] )*per;
//					}
//				}


			int ll=l[i+1];
			for ( j=0; j<=h; j++ )dp[y][j][0]=0.0;
			for ( j=0; j<=h; j++ )dp[y][j][1]=0.0;
			for ( j=0; j<=h; j++ )ex[y][j][0]=0.0;
			for ( j=0; j<=h; j++ )ex[y][j][1]=0.0;
			for ( j=0; j<=ll; j++ )dp[y][ll][0]+=dp[x][j][0]*per;
			for ( j=ll+1; j<=h; j++ )dp[y][ll][1]+=dp[x][j][0]*per;
			for ( j=0; j<ll; j++ )dp[y][ll][0]+=dp[x][j][1]*per;
			for ( j=ll; j<=h; j++ )dp[y][ll][1]+=dp[x][j][1]*per;
			ex[y][ll][0]=ex[x][ll][0]*per;
			for ( j=0; j<ll; j++ )ex[y][ll][0]+=( ex[x][j][0]+ex[x][j][1] )*per;
			ex[y][ll][1]=ex[x][ll][1]*per;
			for ( j=ll+1; j<=h; j++ )ex[y][ll][1]+=( ex[x][j][0]+ex[x][j][1] )*per;
			for ( j=ll+1; j<=h; j++ )ex[y][ll][1]+=( dp[x][j][1]+dp[x][j][0] )*per*( j-ll );
			for ( j=0; j<ll; j++ )ex[y][ll][0]+=( dp[x][j][1]+dp[x][j][0] )*per*( ll-j );
			
			
			pre[0]=( dp[x][0][0]+dp[x][0][1] )*per;
			for ( j=1; j<=h; j++ )pre[j]=pre[j-1]+( dp[x][j][0]+dp[x][j][1] )*per;
			for ( j=l[i+1]+1; j<=r[i+1]; j++ ) {
				dp[y][j][0]=dp[y][j-1][0]+dp[x][j-1][1]*per+dp[x][j][0]*per;
				dp[y][j][1]=dp[y][j-1][1]-dp[x][j-1][1]*per-dp[x][j][0]*per;
				ex[y][j][0]=ex[y][j-1][0]+pre[j-2]+( ex[x][j-1][1]+ex[x][j][0]+dp[x][j-1][0]+dp[x][j-1][1] )*per;
				ex[y][j][1]=ex[y][j-1][1]-pre[h]+pre[j]-( ex[x][j-1][1]+ex[x][j][0]+dp[x][j][0]+dp[x][j][1] )*per;
			}
//			for(j=0;j<=h;j++)printf("%.2f ",dp[y][j][0]);printf("\n");
//			for(j=0;j<=h;j++)printf("%.2f ",dp[y][j][1]);printf("\n");
//			for(j=0;j<=h;j++)printf("%.2f ",dp[y][j][1]+dp[y][j][0]);printf("\n");
//			printf("\n");
//			for(j=0;j<=h;j++)printf("%.2f ",ex[y][j][0]);printf("\n");
//			for(j=0;j<=h;j++)printf("%.2f ",ex[y][j][1]);printf("\n");
//			printf("\n");
//			printf("\n");
		}
		int ed=( n-1 )%2;
		ret=0.0;
		for ( j=0; j<=h; j++ )for ( k=0; k<2; k++ )ret+=ex[ed][j][k];
		
		return ret;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
