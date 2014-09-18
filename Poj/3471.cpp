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
const double PI=acos(-1.);
const LL MOD = 1000000007;
long long P[]= {13251349,13251361,13251367,13251373,13251377,13251383,13251391,1000000007,1000000009};
int nP=1;
LL A[15][205][205];
LL a[205];
int n;
int check(LL x) {
	int i,j,k;
	for(i=0; i<=n; i++) {
		int fail=0;
		for(k=0; k<nP; k++) {	//第k个n-i次函数
			LL now=0;
			LL y=(x%P[k]+P[k])%P[k];
			for(j=n-i; j>=0; j--) {
				now=now*y+A[k][n-i][j];
				if(now>=P[k])now%=P[k];
			}
			if(now) {fail=1; break;}
		}
		if(fail)return i;
	}
	return -1;
}
LL ans[9999],out[205];
int nans,nout;
int main() {
	int i,j,k,T;
	while(~scanf("%d",&n)) {
		a[n]=1;
		for(i=n-1; i>=0; i--)scanf("%I64d",&a[i]);
		for(k=0; k<nP; k++) {
			for(i=0; i<=n; i++)A[k][n][i]=(a[i]%P[k]+P[k])%P[k];
			for(i=n-1; i>=0; i--)
				for(j=0; j<=i; j++){
					A[k][i][j]=A[k][i+1][j+1]*(j+1LL);
					if(A[k][i][j]>=P[k])A[k][i][j]%=P[k];
				}
		}
		nans=0;
		ans[nans++]=0;
		for(int i=0; i<=n; i++)if(a[i]) {
				LL who=a[i];
				if(who<0)who=-who;
				for(LL b=1; b*b<=who; b++)if(who%b==0) {
						ans[nans++]=(b);
						ans[nans++]=(-b);
						ans[nans++]=(who/b);
						ans[nans++]=(-who/b);
					}
				break;
			}
		sort(ans,ans+nans);
		nans=unique(ans,ans+nans)-ans;
		nout=0;
		for(i=0; i<nans&&nout<n; i++) {
			int tot=check(ans[i]);
			for(j=0; j<tot; j++)out[nout++]=(ans[i]);
		}
		printf("%d\n",nout);
		for(i=0; i<nout; i++)printf("%I64d\n",out[i]);
	}
	return 0;
}
/*
1		2095133040
4		-1 1 -1 0
4		-2 1 0 0
4		0 0 0 0
1		-2147483648
1		2147483647
*/
