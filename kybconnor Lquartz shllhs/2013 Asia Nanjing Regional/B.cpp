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
typedef long long ll;
typedef pair<int, int> PII;
int dp[12][25222];
int w[12]= {0,2520,1260,840,630,504,420,360,315,280,252};
void pre() {
	int i,j,k;
	for (i=0; i<=10; i++) for (j=0; j<=25200; j++)
			dp[i][j]=1<<25;
	dp[0][0]=0;
	for (i=0; i<=10; i++) for (j=0; j<=25200; j++) {
			if (dp[i][j]==1<<25) continue;
			dp[i+1][j]=min (dp[i][j],dp[i+1][j]);
			if (j+w[i]<=25200)
				dp[i][j+w[i]]=min (dp[i][j+w[i]],dp[i][j]+1);
		}
}
int main() {
	pre();
	ll x,y;
	ll A=2520LL;
	while (scanf ("%I64d%I64d",&x,&y) !=EOF) {
		if (y<x) {printf ("-1\n"); continue;}
		ll zl=A*y;
		ll zr=A*y+A;
		zl=zl/x;
		zr=zr/x;
		//zl <= z < zr
		zl-=w[1];
		zr-=w[1];
		ll t=zl/w[1];
		ll res=t+x-1; Nmu
		zl-=t*w[1];
		zr-=t*w[1];
		int l=zl,r=zr;
		int i;
		int mx=1<<25;
		for (i=zl; i<zr; i++) mx=min (mx,dp[ (int) x][i]);
		printf ("%I64d\n",res+mx);
	}
	return 0;
}
