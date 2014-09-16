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
const int MOD = 1000000007;
#define OP begin()
#define ED end()
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SORT(L) sort(L.OP,L.ED)
int a[1000005];
int sum[1000005];
int dp[1000005][2];
int sv[1000005][2];
void check(int id,int w,int p) {
	int d0=dp[id][0],s0=sv[id][0];
	int d1=dp[id][1],s1=sv[id][1];
	if(w<d0||(w==d0&&p<s0)) {
		dp[id][1]=d0,sv[id][1]=s0;
		dp[id][0]=w,sv[id][0]=p;
	} else if(w>d1||(w==d1&&p>s1))return;
	else dp[id][1]=w,sv[id][1]=p;
}
inline int read() {
	char ch;
	bool flag = false;
	int a = 0;
	while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
	if(ch != '-')a = a*10+(ch-'0');
	else flag = true;
	while(((ch = getchar()) >= '0') && (ch <= '9'))
		a = a*10+(ch-'0');
	if(flag) a = -a;
	return a;
}
void write(int a) {
	if(a < 0) 
		putchar('-'),a = -a;
	if(a >= 10)
		write(a / 10);
	putchar(a % 10 + '0');
}
int main() {
	int i,j;
	int n;
	while(n=read()) {
		for(i=1; i<=n; i++)a[i]=read();
		sum[0]=0;
		for(i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
		for(i=1; i<=n; i++)for(j=0; j<2; j++)dp[i][j]=1LL<<29;
		for(i=1; i<=n; i++)for(j=0; j<2; j++)sv[i][j]=n+1;
		//sum[n-1]
		for(i=n; i<2*n; i++)check(n,sum[i-n]+a[n],i-n+1);
		for(i=n-1; i>=1; i--) {
			if(sv[i+1][0]<n)check(i,a[i]+dp[i+1][0],sv[i+1][0]+1);
			else if(sv[i+1][1]<n)check(i,a[i]+dp[i+1][1],sv[i+1][1]+1);
			check(i,a[i],1);
		}
		int cnt=0;
		for(i=1; i<=n; i++)if(dp[i][0]>=0)cnt++;
		write(cnt);
		putchar('\n');
	}
	return 0;
}
