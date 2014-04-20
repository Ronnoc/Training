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

#define cmin(x,y) x=min(x,y)
int dp[1111][1111];
int ans;
int to;
void fresh( int now,int cp,int tht ) {
	if ( now>=to ) {
		cmin( ans,tht+now-to );
		return;
	}
	if ( now<1 )return;
	int &tp=dp[now][cp];
	if ( tp==-1||tp>tht ) {
		tp=tht;
		fresh( now,now,tht+1 );
		fresh( now+cp,cp,tht+1 );
		fresh( now-1,cp,tht+1 );
	}
}
class EmoticonsDiv1 {
public:
	int printSmiles( int s ) {
		int ret;
		to=s;
		ans=1e9;
		memset( dp,-1,sizeof dp );
		fresh( 1,0,0 );
		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
