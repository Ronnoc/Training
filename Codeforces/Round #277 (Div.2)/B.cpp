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
int A[105][105];
int B[105][105];
int p[105],q[105];
int s[105],t[105];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n,m;
	while(cin>>n>>m){
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>A[i][j];
		for(i=1;i<=n;i++){
			p[i]=1;
			for(j=1;j<=m;j++)p[i]&=A[i][j];
		}
		for(j=1;j<=m;j++){
			q[j]=1;
			for(i=1;i<=n;i++)q[j]&=A[i][j];
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				B[i][j]=p[i]&q[j];
		for(i=1;i<=n;i++){
			s[i]=0;
			for(j=1;j<=m;j++)s[i]|=B[i][j];
		}
		for(j=1;j<=m;j++){
			t[j]=0;
			for(i=1;i<=n;i++)t[j]|=B[i][j];
		}
		int fail=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if((s[i]|t[j])!=A[i][j])
					fail=1;
		if(fail)puts("NO\n");
		else {
			puts("YES");
			for(i=1;i<=n;i++,cout<<"\n")
				for(j=1;j<=m;j++)cout<<B[i][j]<<" ";
		}
	}
	return 0;
}
