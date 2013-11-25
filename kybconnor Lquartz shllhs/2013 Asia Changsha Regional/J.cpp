//kybconnor
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
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
long double dp[122][10005];
long double mx[122][122];
int t[10005];
void solve() {
	int n,m,i,j;
	while (~scanf ("%d",&n)) {
		n=n* (n-1) * (n-2) /6;
		for (i=0; i<n; i++)
			for (j=0; j<n; j++) {
				double tp;
				scanf ("%lf",&tp);
				mx[i][j]=tp;
			}
//		for (i=0; i<n; i++){
//			for (j=0; j<n; j++)cout<<mx[i][j]<<" ";
//			cout<<endl;
//		}
		scanf ("%d",&m);
		for (j=1; j<=m; j++) scanf ("%d",&t[j]);
		for (i=0; i<n; i++) dp[i][0]=1;
		for (j=1; j<=m; j++) {
			for (i=0; i<n; i++)
				dp[i][j]=dp[i][j-1]*mx[i][t[j]];
//			cout<<t[j]<<endl;
//			for (i=0; i<n; i++) printf ("%3.3lf ",double (mx[i][t[j]])); cout<<endl;
//			for (i=0; i<n; i++) printf ("%3.3lf ",double (dp[i][j])); cout<<endl;
			for (i=0; i<n; i++)
				dp[t[j]][j]=max (dp[t[j]][j],dp[i][j]);
//			for (i=0; i<n; i++) printf ("%3.3lf ",double (dp[i][j])); cout<<endl;
//			cout<<endl;
		}
		long double res=0;
		for (i=0; i<n; i++) res=max (res,dp[i][m]);
		printf ("%.6lf\n",double (res));
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
